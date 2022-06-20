// DlgStrategyInfo.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyInfo.h"
#include "afxdialogex.h"


// CDlgStrategyInfo 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyInfo, CDlgChildBase)

CDlgStrategyInfo::CDlgStrategyInfo(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_INFO, pParent)
{

}

CDlgStrategyInfo::~CDlgStrategyInfo()
{
}

void CDlgStrategyInfo::SetChildAndControlPosition()
{
	m_stc_strategy_info_name.MoveWindow(10, 15, STRATEGY::SIZE_FRAME_WIDTH - 20, 45);
	m_btn_strategy_info_type_left.MoveWindow(10, 70, 60, 60);
	m_stc_strategy_info_type.MoveWindow(70, 85, 160, 45);
	m_btn_strategy_info_type_right.MoveWindow(230, 70, 60, 60);
}


void CDlgStrategyInfo::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_STRATEGY_INFO_TYPE_LEFT, m_btn_strategy_info_type_left);
	DDX_Control(pDX, IDC_BTN_STRATEGY_INFO_TYPE_RIGHT, m_btn_strategy_info_type_right);
	DDX_Control(pDX, IDC_STC_STRATEGY_INFO_NAME, m_stc_strategy_info_name);
	DDX_Control(pDX, IDC_STC_STRATEGY_INFO_TYPE, m_stc_strategy_info_type);
}


BEGIN_MESSAGE_MAP(CDlgStrategyInfo, CDlgChildBase)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgStrategyInfo 메시지 처리기


BOOL CDlgStrategyInfo::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(STRATEGY::COLOR_BKGROUND_INFO);	

	m_btn_strategy_info_type_left.LoadBitmaps(IDB_BMP_STRATEGY_INFO_BTN_LEFT_UP, IDB_BMP_STRATEGY_INFO_BTN_LEFT_DN);
	m_btn_strategy_info_type_right.LoadBitmaps(IDB_BMP_STRATEGY_INFO_BTN_RIGHT_UP, IDB_BMP_STRATRGY_INFO_BTN_RIGHT_DN);

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


HBRUSH CDlgStrategyInfo::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDlgChildBase::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	pDC->SetTextColor(STRATEGY::COLOR_FONT_INFO);
	pDC->SelectObject(&m_fnt_strategy_info);

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
