// DlgStrategyScrollFrame.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyScrollFrame.h"
#include "afxdialogex.h"

#include "DlgStrategyMain.h"
#include "DlgStrategyScroll.h"


// CDlgStrategyScrollFrame 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyScrollFrame, CDlgChildBase)

CDlgStrategyScrollFrame::CDlgStrategyScrollFrame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_STRATEGY_SCROLL_FRAME, pParent)
{

}

CDlgStrategyScrollFrame::~CDlgStrategyScrollFrame()
{
	delete(m_ptr_dlg_strategy_main);
	delete(m_ptr_dlg_strategy_scroll);
}

void CDlgStrategyScrollFrame::SetChildAndControlPosition()
{
	CRect FrameRect;
	GetClientRect(&FrameRect);

	m_ptr_dlg_strategy_main->MoveWindow(0, 0, FrameRect.Width() - 10, FrameRect.Height());
	m_ptr_dlg_strategy_scroll->MoveWindow(FrameRect.Width() - 10, 0, 10, FrameRect.Height());
}

void CDlgStrategyScrollFrame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyScrollFrame, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgStrategyScrollFrame 메시지 처리기


BOOL CDlgStrategyScrollFrame::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetBackgroundColor(RGB(0, 0, 0));

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ptr_dlg_strategy_main = new CDlgStrategyMain();
	m_ptr_dlg_strategy_main->Create(IDD_DLG_STRATEGY_MAIN, this);
	m_ptr_dlg_strategy_main->ShowWindow(true);

	m_ptr_dlg_strategy_scroll = new CDlgStrategyScroll();
	m_ptr_dlg_strategy_scroll->Create(IDD_DLG_STRATEGY_SCROLL, this);
	m_ptr_dlg_strategy_scroll->ShowWindow(true);

	SetChildAndControlPosition();

	m_ptr_dlg_strategy_main->SetPairedScrollDialogToSync(m_ptr_dlg_strategy_scroll);
	m_ptr_dlg_strategy_scroll->SetPairedScrollDialogToSync(m_ptr_dlg_strategy_main);



	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgStrategyScrollFrame::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_bInit)
	{
		// 스크롤 관련 사이즈 조절만 하고 RefreshMenu는 하지 않는다(Right와 다른 점)
		m_ptr_dlg_strategy_main->MoveWindowScrollDialog(true);
		m_ptr_dlg_strategy_scroll->MoveWindowScrollDialog(true);
	}
}
