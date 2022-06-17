// DlgStrategyScroll.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyScroll.h"
#include "afxdialogex.h"


// CDlgStrategyScroll 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyScroll, CDlgScrollBase)

CDlgStrategyScroll::CDlgStrategyScroll(CWnd* pParent /*=nullptr*/)
	: CDlgScrollBase(IDD_DLG_STRATEGY_SCROLL, pParent)
{
	m_nOffDlg[0] = SGS_MAIN_WIDTH;
	m_nOffDlg[1] = 0; 
	m_nSizeDlg[0] = 10; 
	m_nSizeDlg[1] = 1000 + 10;
}

CDlgStrategyScroll::~CDlgStrategyScroll()
{
}

void CDlgStrategyScroll::SetChildAndControlPosition()
{
}

void CDlgStrategyScroll::DoDataExchange(CDataExchange* pDX)
{
	CDlgScrollBase::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_STRATEGY_SCROLL_UPPER, m_btn_strategy_scroll_upper);
	DDX_Control(pDX, IDC_BTN_STRATEGY_SCROLL_CENTER, m_btn_strategy_scroll_center);
	DDX_Control(pDX, IDC_BTN_STRATEGY_SCROLL_LOWER, m_btn_strategy_scroll_lower);
}


BEGIN_MESSAGE_MAP(CDlgStrategyScroll, CDlgScrollBase)
END_MESSAGE_MAP()


// CDlgStrategyScroll 메시지 처리기


BOOL CDlgStrategyScroll::OnInitDialog()
{
	CDlgScrollBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(BKC_STRATEGY_SCROLL);
	SetScrollButtonPointer(&m_btn_strategy_scroll_center, &m_btn_strategy_scroll_upper, &m_btn_strategy_scroll_lower, true);
	SetScrollDialogType(SCROLL_TYPE::SCROLLBAR, SCROLL_ORIENTATION::VERTICAL);
	MoveWindowScrollDialog();
	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

