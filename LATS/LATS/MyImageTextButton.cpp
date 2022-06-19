       // ImageTextButton.cpp : implementation file
//
#include "stdafx.h"
#include "MyImageTextButton.h"

#include "Resource.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

/////////////////////////////////////////////////////////////////////////////

CMyImageTextButton::CMyImageTextButton():m_strText(""),
                                     m_nXpos(-1),
                                     m_nYpos(-1),
                                     m_uiPos(DT_SINGLELINE | DT_CENTER | DT_VCENTER),
                                     m_bLoaded(FALSE),
                                     m_clrCptnUpDwn(RGB(255,255,255)),
                                     m_clrCptnDisabled(RGB(255,255,255))
{ 
	m_bIsCheckEnabled = true;
}

CMyImageTextButton::~CMyImageTextButton()
{
    m_ImageList.DeleteImageList();
    m_Font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CMyImageTextButton, CButton)
	//{{AFX_MSG_MAP(CMyImageTextButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
 	ON_WM_SETFOCUS()
	ON_WM_ENABLE()
	//}}AFX_MSG_MAP	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyImageTextButton message handlers

void CMyImageTextButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (lpDrawItemStruct->CtlType != ODT_BUTTON)
		return;
	//To keep the text color 
	COLORREF clrText;

	int nImgCount = 0;
	//Keeps the index of the image(based on 0) to be drawn
	int nPosImg = 0;

	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	if (!m_bLoaded)
	{
		m_rectBtn = lpDrawItemStruct->rcItem;
	}
	else
	{
		//Gets the number of image in the image list
		nImgCount = m_ImageList.GetImageCount();
		::SetWindowPos(lpDrawItemStruct->hwndItem, NULL, m_rectBtn.left, m_rectBtn.top, m_bitmap.bmWidth, m_bitmap.bmHeight, SWP_NOMOVE);

	}

	pDC->DrawFrameControl(&m_rectBtn, DFC_BUTTON, DFCS_BUTTONPUSH | DFCS_PUSHED);
	//if( m_bLoaded )
	{
		if (ODS_DISABLED & lpDrawItemStruct->itemState)
		{
			if (m_bLoaded)
			{
				if (3 == nImgCount)
					nPosImg = 2;
				else
					nPosImg = 0;
			}
			clrText = m_clrCptnDisabled;
		}
		else if (ODS_SELECTED & lpDrawItemStruct->itemState)
		{
			if (m_bLoaded)
			{
				if (2 <= nImgCount)
					nPosImg = 1;
				else
					nPosImg = 0;
			}
			clrText = m_clrCptnUpDwn;
		}
		else
		{
			if (m_bLoaded)
			{
				nPosImg = 0;
			}
			clrText = m_clrCptnUpDwn;
		}
		if (m_bLoaded)
		{
			//Draw the image in to the DC
			m_ImageList.DrawIndirect(
				pDC,
				nPosImg,
				CPoint(m_rectBtn.left, m_rectBtn.top),
				CSize(m_bitmap.bmWidth, m_bitmap.bmHeight),
				CPoint(0, 0),
				ILD_NORMAL
			);
		}
	}
	if (!m_strText.IsEmpty())
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(clrText);

		HFONT hOldFont = NULL;
		//Sets the font
		if (m_Font.GetSafeHandle() != NULL)
		{
			hOldFont = (HFONT)pDC->SelectObject(m_Font.GetSafeHandle());
		}

		////////////////////////////////////// 원본 //////////////////////////////////////
		//if(m_nYpos!=-1 && m_nXpos!=-1)
		//{
		//  pDC->TextOut(m_nXpos,m_nYpos,m_strText);
		//}
		//else
		//{
		//  pDC->DrawText( m_strText, m_rectBtn , m_uiPos);
		//}
		////////////////////////////////////// 원본 //////////////////////////////////////

		////////////////////////////////////// 수정본 //////////////////////////////////////
		// 클릭시 클릭 효과를 위해 한 픽셀씩 밀어줌	 
		if (ODS_DISABLED & lpDrawItemStruct->itemState)
		{
			if (m_nYpos != -1 && m_nXpos != -1)
			{
				pDC->TextOut(m_nXpos, m_nYpos, m_strText);
			}
			else
			{
				pDC->DrawText(m_strText, m_rectBtn, m_uiPos);
			}
		}
		else if (ODS_SELECTED & lpDrawItemStruct->itemState)
		{
			if (m_nYpos != -1 && m_nXpos != -1)
			{
				pDC->TextOut(m_nXpos + 1, m_nYpos + 1, m_strText);
			}
			else
			{
				CSize size = pDC->GetTextExtent(m_strText);
				int widthText = size.cx;
				int heightText = size.cy;
				CPoint centerOfBtn = m_rectBtn.CenterPoint();
				int offX = (int)(centerOfBtn.x - (0.5 * widthText));
				int offY = (int)(centerOfBtn.y - (0.5 * heightText));
				pDC->TextOut(offX + 1, offY + 1, m_strText);
			}
		}
		else
		{
			if (m_nYpos != -1 && m_nXpos != -1)
			{
				pDC->TextOut(m_nXpos, m_nYpos, m_strText);
			}
			else
			{
				pDC->DrawText(m_strText, m_rectBtn, m_uiPos);
			}
		}
		////////////////////////////////////// 수정본 //////////////////////////////////////

		//Reset the old font
		if (hOldFont != NULL)
		{
			pDC->SelectObject(hOldFont);
		}
	}
}

void CMyImageTextButton::SetButtonImg(UINT uiImageIDU, UINT uiImgIDD, UINT uiImgIDX)
{
	CBitmap bitmapImage;
	if (m_bLoaded)
	{
		m_ImageList.DeleteImageList();
		m_bLoaded = FALSE;
	}
	//Loading Bitmap
	if (bitmapImage.LoadBitmap(uiImageIDU))
	{

		bitmapImage.GetObject(sizeof(m_bitmap), &m_bitmap);
		m_rectBtn.top = 0; m_rectBtn.left = 0;
		m_rectBtn.right = m_bitmap.bmWidth; m_rectBtn.bottom = m_bitmap.bmHeight;

		if (m_ImageList.Create(m_bitmap.bmWidth, m_bitmap.bmHeight, ILC_COLORDDB, 1, 2))
		{
			m_ImageList.Add(&bitmapImage, &bitmapImage);
			if (0 != uiImgIDD)
			{
				bitmapImage.DeleteObject();
				bitmapImage.LoadBitmap(uiImgIDD);
				m_ImageList.Add(&bitmapImage, &bitmapImage);

			}
			if (0 != uiImgIDX)
			{
				bitmapImage.DeleteObject();
				bitmapImage.LoadBitmap(uiImgIDX);
				m_ImageList.Add(&bitmapImage, &bitmapImage);

			}
			bitmapImage.DeleteObject();
			m_bLoaded = TRUE;
		}
	}
	RedrawWindow();
}

void CMyImageTextButton::MySetWindowText(const CString &strCaption)
{
	m_strText = strCaption;
	RedrawWindow();
}

CString CMyImageTextButton::MyGetWindowText()
{
	return m_strText;
}

void CMyImageTextButton::OnSetFocus(CWnd* pOldWnd) 
{
	CButton::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	Invalidate(TRUE);
}

void CMyImageTextButton::OnEnable(BOOL bEnable) 
{
	CButton::OnEnable(bEnable);
	
	// TODO: Add your message handler code here
	Invalidate(TRUE);
}

//Function used for setting the position of the Text in the button according X y position
void CMyImageTextButton::SetTextPosition(int nXPos, int nYPos)
{
	m_nXpos = nXPos;
	m_nYpos = nYPos;
}

//Function used for setting the position of the Text in the button according to the center, left etc
void CMyImageTextButton::SetTextPosition(UINT uiPos)
{
	m_uiPos = uiPos;
}

void CMyImageTextButton::SetTextColor(const COLORREF &clrUpDwn,const COLORREF &clrDisabled)
{
    m_clrCptnUpDwn    = clrUpDwn;
    m_clrCptnDisabled = clrDisabled;
	RedrawWindow();
}

void CMyImageTextButton::SetFont(CString srtFntName_i, int nSize_i)
{
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 0;

	lfCtrl.lfHeight = nSize_i;

	lfCtrl.lfItalic = FALSE;
	lfCtrl.lfUnderline = FALSE;
	lfCtrl.lfStrikeOut = FALSE;

	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	_tcscpy_s(lfCtrl.lfFaceName, srtFntName_i);

	//Normal Font
	lfCtrl.lfWeight = FW_NORMAL;
	m_Font.CreateFontIndirect(&lfCtrl);
}

// 체크박스
void CMyImageTextButton::MySetCheck(bool bCheck, bool bAnalysisGroupFold)
{
	if (!m_bIsCheckEnabled) return;

	m_bCheck = bCheck;

	if (bCheck)
	{
	//	if(bAnalysisGroupFold) SetButtonImg(IDB_BMP_BUTTONUP, IDB_MENU_GROUP_FOLD_CLOSE_DN);
	//	else SetButtonImg(IDB_MENU_CHECK_ON);
	}
	else
	{
	//	if (bAnalysisGroupFold) SetButtonImg(IDB_MENU_GROUP_FOLD_OPEN_UP, IDB_MENU_GROUP_FOLD_OPEN_DN);
//		else SetButtonImg(IDB_MENU_CHECK_OFF);
	}
}

bool CMyImageTextButton::MyGetCheck()
{
	return m_bCheck;
}

void CMyImageTextButton::MyEnableCheck(bool bEnable)
{
	if (bEnable)
	{
		m_bIsCheckEnabled = true;
		MySetCheck(m_bCheck);
	}
	else
	{
		m_bIsCheckEnabled = false;
//		SetButtonImg(IDB_MENU_CHECK_DIS);
	}
}

bool CMyImageTextButton::MyGetEnabled()
{
	return m_bIsCheckEnabled;
}
