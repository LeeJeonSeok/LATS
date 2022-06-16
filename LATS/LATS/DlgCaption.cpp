// DlgCaption.cpp: 구현 파일
//
#include "stdafx.h"
#include "LATS.h"
#include "DlgCaption.h"
#include "afxdialogex.h"

#include "LATSManager.h"
#include "DlgMainFrame.h"


// CDlgCaption 대화 상자

IMPLEMENT_DYNAMIC(CDlgCaption, CDialogEx)

CDlgCaption::CDlgCaption(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_CAPTION, pParent)
{

}

CDlgCaption::~CDlgCaption()
{
}

void CDlgCaption::SetChildAndControlPosition()
{
	CRect rt;
	GetClientRect(rt);

	int nStaticWidth = rt.Width() - (CTS_BTNWIDTH * 3) - CTS_ICONWIDTH;

	m_btn_caption_icon.MoveWindow(0, 0, CTS_ICONWIDTH, CTS_HEIGHT);

	m_stc_caption_info.MoveWindow(CTS_ICONWIDTH + 10, CTS_STATICYPOS, nStaticWidth, CTS_STATICHEIGHT);

	int nBTNpos = rt.Width() - (CTS_BTNWIDTH * 3);
	m_btn_caption_hide.MoveWindow(nBTNpos, 0, CTS_BTNWIDTH, CTS_HEIGHT);
	nBTNpos += CTS_BTNWIDTH;
	m_btn_caption_minmax.MoveWindow(nBTNpos, 0, CTS_BTNWIDTH, CTS_HEIGHT);
	nBTNpos += CTS_BTNWIDTH;
	m_btn_caption_close.MoveWindow(nBTNpos, 0, CTS_BTNWIDTH, CTS_HEIGHT);
}

void CDlgCaption::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_CAPTION_ICON, m_btn_caption_icon);
	DDX_Control(pDX, IDC_BTN_CAPTION_HIDE, m_btn_caption_hide);
	DDX_Control(pDX, IDC_BTN_CAPTION_MINMAX, m_btn_caption_minmax);
	DDX_Control(pDX, IDC_BTN_CAPTION_CLOSE, m_btn_caption_close);
	DDX_Control(pDX, IDC_STC_CAPTION_INFO, m_stc_caption_info);
}


BEGIN_MESSAGE_MAP(CDlgCaption, CDlgChildBase)

	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_CAPTION_HIDE, &CDlgCaption::OnBnClickedBtnCaptionHide)
	ON_BN_CLICKED(IDC_BTN_CAPTION_MINMAX, &CDlgCaption::OnBnClickedBtnCaptionMinmax)
	ON_BN_CLICKED(IDC_BTN_CAPTION_CLOSE, &CDlgCaption::OnBnClickedBtnCaptionClose)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlgCaption 메시지 처리기


BOOL CDlgCaption::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(BKC_CAPTION);

	m_btn_caption_icon.LoadBitmaps(IDB_BMP_CAPTION_ICON);

	m_btn_caption_hide.SetButtonText("―");
	m_btn_caption_minmax.SetButtonText("□");
	m_btn_caption_close.SetButtonText("×");

	m_btn_caption_close.SetCloseButton();


	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CDlgCaption::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_RETURN == pMsg->wParam || VK_ESCAPE == pMsg->wParam)
		{
			return 0;
		}
	}

	return CDlgChildBase::PreTranslateMessage(pMsg);
}


HBRUSH CDlgCaption::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDlgChildBase::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	pDC->SetTextColor(FTC_CAPTION);

	//	// EDT, LST, DLG, STATIC	

	pDC->SelectObject(&m_fnt_caption);

	if (nCtlColor == CTLCOLOR_EDIT || nCtlColor == CTLCOLOR_LISTBOX)
	{

		pDC->SetTextColor(FTC_CAPTION);
		pDC->SetBkColor(BKC_CAPTION);

		hbr = CreateSolidBrush(RGB(45, 45, 45));
		return hbr;
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CDlgCaption::OnBnClickedBtnCaptionHide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ptr_LATSManager->GetMainframeDlgAddress()->ShowWindow(SW_MINIMIZE);
}


void CDlgCaption::OnBnClickedBtnCaptionMinmax()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!m_ptr_LATSManager->GetbMaxiMize())
	{
		m_ptr_LATSManager->GetMainframeDlgAddress()->ShowWindow(SW_MAXIMIZE);
	}
	else
	{
		m_ptr_LATSManager->GetMainframeDlgAddress()->ShowWindow(SW_SHOWNOACTIVATE);
	}
	m_ptr_LATSManager->SetbMaxiMize(!m_ptr_LATSManager->GetbMaxiMize());
}


void CDlgCaption::OnBnClickedBtnCaptionClose()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ptr_LATSManager->GetMainframeDlgAddress()->PostMessageA(WM_CLOSE);
}



void CDlgCaption::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_ptr_LATSManager->GetMainframeDlgAddress()->PostMessageA(WM_NCLBUTTONDOWN, HTCAPTION, MAKEWPARAM(point.x, point.y));

	CDlgChildBase::OnLButtonDown(nFlags, point);
}
