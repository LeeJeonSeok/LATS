#include "stdafx.h"
#include "MyGroupBox.h"


CMyGroupBox::CMyGroupBox():
	m_crText(GetSysColor(COLOR_BTNTEXT)),
	m_crBackground(GetSysColor(COLOR_BTNFACE)),
	m_crBorder(CLR_INVALID),
	m_crEtchedBorder(CLR_INVALID),
	//m_nXMargin(DEFAULT_X_MARGIN),
	//m_nYMargin(0),
	m_nYOffset(-1),
	//m_hIcon(0),
	//m_hGrayIcon(0),
	//m_bGrayPaletteSet(FALSE),
	//m_nIconSpacing(DEFAULT_ICON_SPACING),
	//m_nIconSize(0),
	//m_bDestroyIcon(FALSE),
	m_rect(CRect(0, 0, 0, 0)),
	m_sizeText(CSize(0, 0)),
	//m_bThemed(FALSE),
	//m_bEnableTheme(TRUE),
	//m_bShowDisabledState(TRUE),
	//m_eStyle(groupbox),
	//m_eIconAlignment(left),
	//m_eControlAlignment(left),
	m_eBorderStyle(etched)
{

}


CMyGroupBox::~CMyGroupBox()
{


}

BEGIN_MESSAGE_MAP(CMyGroupBox, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CMyGroupBox::DrawBorder(CDC * pDC, CRect & rect)
{
	// user color overrides themes
	if (m_crBorder != CLR_INVALID)
	{
		DrawEtchedRectangle(pDC, rect, m_crBorder, m_crEtchedBorder);
	}

}

void CMyGroupBox::DrawItem(CDC * pDC, CRect & rect)
{
	ASSERT(pDC);
	if (!pDC)
		return;

	CRect rectItem(rect);
	CRect rectDraw(rectItem);
	CRect rectText(rectDraw);
	//CRect rectIcon(rectDraw);
	CRect rectFrame(rectDraw);
	CRect rectHeader(rectDraw);

	// 텍스트의 길이 구하기
	if (m_sizeText.cx == 0)
	{
		// get string width
		CString strText = _T("");
		GetWindowText(strText);

		CFont *pOldFont = pDC->SelectObject(m_pFont);
		if (!strText.IsEmpty())
			m_sizeText = pDC->GetTextExtent(strText);
		if (pOldFont)
			pDC->SelectObject(pOldFont);
	}

	m_nYOffset = m_sizeText.cy + 1; // __max(m_sizeText.cy, m_nIconSize) + 1;
	rectText.bottom = rectText.top + m_nYOffset;
	rectHeader.bottom = rectHeader.top + m_nYOffset;
	m_nYOffset = m_nYOffset / 2;
	rectFrame.top += m_nYOffset;
	//rectIcon.top = rectFrame.top; // -m_nIconSize / 2;
	//rectIcon.bottom = rectIcon.top; // +m_nIconSize;

	// set up for double buffering
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC, rectDraw.Width(), rectDraw.Height());
	CBitmap *pOldBitmap = memDC.SelectObject(&bmp);

	// fill in entire window
	memDC.FillSolidRect(&rectItem, m_crBackground);

	// get parent DC and copy current contents - this will emulate 
	// transparent blt'ing

	CRect rectWindow;
	GetWindowRect(&rectWindow);
	GetParent()->ScreenToClient(&rectWindow);
	rectWindow.top += m_nYOffset * 2;

	CDC *pParentDC = GetParent()->GetDC();
	memDC.BitBlt(0, m_nYOffset * 2, rectWindow.Width(), rectWindow.Height(),
		pParentDC, rectWindow.left, rectWindow.top, SRCCOPY);
	VERIFY(ReleaseDC(pParentDC));


	// select NULL brush for border drawing
	HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(memDC.m_hDC, hBrush);

	// erase the old border that exists in the parent DC
	//EraseBorder(&memDC, m_rect, m_crBackground);
	m_rect = rectFrame;


	DrawBorder(&memDC, rectFrame);

	if (hOldBrush)
		::SelectObject(memDC.m_hDC, hOldBrush);

	//EraseHeaderArea(&memDC, rectHeader, RGB(0, 255, 0));//) m_crBackground);

	rectText.left = rectHeader.left;
	//rectIcon.left = rectHeader.left;

	DrawHeader(&memDC, rectText);


	// end double buffering
	pDC->BitBlt(0, 0, rectDraw.Width(), rectDraw.Height(),
		&memDC, 0, 0, SRCCOPY);

	// swap back the original bitmap
	if (pOldBitmap)
		memDC.SelectObject(pOldBitmap);
	if (bmp.GetSafeHandle())
		bmp.DeleteObject();

	memDC.DeleteDC();

}

int CMyGroupBox::DrawText(CDC * pDC, CRect & rect)
{
	int rc = rect.left;		// if no string just return start position

	CString strText = _T("");
	GetWindowText(strText);
	//CString temp = _T(" ");
	//temp += strText + " ";
	//strText = temp;
	//TRACE(_T("strText=<%s>\n"), strText);

	if (!strText.IsEmpty())
	{
		//COLORREF crText = m_crText;
		//if (!IsWindowEnabled() && m_bShowDisabledState)
		//	crText = GetSysColor(COLOR_GRAYTEXT);
		pDC->SetTextColor(m_crText);
		pDC->SetBkColor(m_crBackground);
		pDC->SetBkMode(OPAQUE);
		pDC->SelectObject(m_pFont);

		CFont *pOldFont = pDC->SelectObject(m_pFont);

		// always left aligned within drawing rect
		UINT nFormat = DT_LEFT | DT_VCENTER | DT_SINGLELINE;

		CRect rectText(rect);
		// get size of text so we can update rect
		CSize size = pDC->GetTextExtent(strText);
		rectText.right = rectText.left + size.cx;

		pDC->DrawText(strText, rectText, nFormat);

		rc = rectText.right;

		if (pOldFont)
			pDC->SelectObject(pOldFont);
	}

	return rc;



}

void CMyGroupBox::EraseBorder(CDC * pDC, CRect & rect, COLORREF crBackground)
{
	if (!rect.IsRectEmpty())
	{
		CRect r(rect);
		CPen pen(PS_SOLID, 5, crBackground);
		CPen *pOldPen = pDC->SelectObject(&pen);
		r.DeflateRect(2, 2);
		pDC->Rectangle(&r);
		if (pOldPen)
			pDC->SelectObject(pOldPen);
	}
}

void CMyGroupBox::DrawEtchedRectangle(CDC * pDC, CRect & rect, COLORREF cr, COLORREF crE)
{
	CPen penDark(PS_SOLID, 1, cr);
	CPen *pOldPen = pDC->SelectObject(&penDark);

	if (m_eBorderStyle == etched)
	{
		// border is 2 pixels, so deflate bottom and right sides by 1
		CPen penLight(PS_SOLID, 2, crE);	// 2 pixels wide
		pDC->SelectObject(&penLight);
		rect.DeflateRect(0, 0, 1, 1);
		rect.OffsetRect(1, 1);
		pDC->Rectangle(&rect);			// white rectangle, 2 pixels wide
		rect.OffsetRect(-1, -1);
	}

	pDC->SelectObject(&penDark);
	pDC->Rectangle(&rect);			// dark rectangle - overlay white rectangle

	if (pOldPen)
		pDC->SelectObject(pOldPen);
}

void CMyGroupBox::DrawHeader(CDC * pDC, CRect & rectText)
{
	// there is no spacing if left-aligned 'header'
	//if ((m_eStyle == groupbox) || (m_eControlAlignment != left))
		//rectIcon.left += 3;
		//rectIcon.right = rectIcon.left; // +m_nIconSize;
		rectText.left += 3;// = DrawIcon(pDC, rectIcon);
	//if (m_hIcon)
	//	rectText.left += m_nIconSpacing;
	//pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(m_crBackground);
	DrawText(pDC, rectText);
}

void CMyGroupBox::SetFont(CFont * pFont, BOOL bRedraw)
{
	m_pFont = pFont;

	//if (bRedraw)
	//	RedrawWindow();	
}

void CMyGroupBox::SetTextColor(COLORREF cr) // , BOOL bRedraw)
{
	m_crText = cr;
	
	//if (bRedraw)
	//	RedrawWindow();	
}

void CMyGroupBox::SetBKColor(COLORREF crBk)
{
	m_crBackground = crBk;
}

void CMyGroupBox::SetBorderColor(COLORREF cr, COLORREF crE)//, BOOL bRedraw)
{
	m_crBorder = cr;
	m_crEtchedBorder = crE;

	//if (bRedraw)
	//	RedrawWindow();
}

void CMyGroupBox::SetBorderStyle(BORDER_STYLE eStyle)//, BOOL bRedraw)
{
	m_eBorderStyle = eStyle;

	//if (bRedraw)
	//	RedrawWindow();
}

void CMyGroupBox::OnPaint()
{
	static BOOL bInPaint = FALSE;

	if (bInPaint)
		return;
	bInPaint = TRUE;
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetWindowRect(&rect);
	int w = rect.Width();
	int h = rect.Height();
	rect.left = 0;
	rect.top = 0;
	rect.right = w;
	rect.bottom = h;
	DrawItem(&dc, rect);

	bInPaint = FALSE;

	// Do not call CStatic::OnPaint() for painting messages
}
