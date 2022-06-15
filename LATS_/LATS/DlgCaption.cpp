// DlgCaption.cpp: 구현 파일
//
#include "stdafx.h"
#include "LATS.h"
#include "DlgCaption.h"
#include "afxdialogex.h"


// CDlgCaption 대화 상자

IMPLEMENT_DYNAMIC(CDlgCaption, CDialogEx)

CDlgCaption::CDlgCaption(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_CAPTION, pParent)
{

}

CDlgCaption::~CDlgCaption()
{
}

void CDlgCaption::SetControlPosition()
{
	CRect rt;
	GetClientRect(rt);

	int nStaticWidth = rt.Width() - (CS_BTNWIDTH * 3) - CS_ICONWIDTH;

	m_btn_caption_icon.MoveWindow(0, 0, CS_ICONWIDTH, CS_HEIGHT);

	m_stc_caption_info.MoveWindow(CS_ICONWIDTH + 10, CS_STATICYPOS, nStaticWidth, CS_STATICHEIGHT);

	int nBTNpos = rt.Width() - (CS_BTNWIDTH * 3);
	m_btn_caption_hide.MoveWindow(nBTNpos, 0, CS_BTNWIDTH, CS_HEIGHT);
	nBTNpos += CS_BTNWIDTH;
	m_btn_caption_minmax.MoveWindow(nBTNpos, 0, CS_BTNWIDTH, CS_HEIGHT);
	nBTNpos += CS_BTNWIDTH;
	m_btn_caption_close.MoveWindow(nBTNpos, 0, CS_BTNWIDTH, CS_HEIGHT);
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
END_MESSAGE_MAP()


// CDlgCaption 메시지 처리기


BOOL CDlgCaption::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(CR_CAPTION);

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
	pDC->SetTextColor(CR_FONT);

	//	// EDT, LST, DLG, STATIC	

	pDC->SelectObject(&m_fnt_caption);

	if (nCtlColor == CTLCOLOR_EDIT || nCtlColor == CTLCOLOR_LISTBOX)
	{

		pDC->SetTextColor(CR_FONT);
		pDC->SetBkColor(CR_CAPTION);

		hbr = CreateSolidBrush(RGB(45, 45, 45));
		return hbr;
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
