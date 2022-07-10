// DlgStrategyInfo.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyInfo.h"
#include "afxdialogex.h"

#include "LATSManager.h"

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

}


void CDlgStrategyInfo::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RDO_STRATEGY_INFO_BUY,m_rdo_strategy_info_buy);
	DDX_Control(pDX, IDC_STC_STRATEGY_INFO_BUY, m_stc_strategy_info_buy);

	DDX_Control(pDX, IDC_RDO_STRATEGY_INFO_CELL, m_rdo_strategy_info_cell);
	DDX_Control(pDX, IDC_STC_STRATEGY_INFO_CELL, m_stc_strategy_info_cell);

	DDX_Control(pDX, IDC_RDO_STRATEGY_INFO_MONEY,m_rdo_strategy_info_money);
	DDX_Control(pDX, IDC_STC_STRATEGY_INFO_MONEY,m_stc_strategy_info_money);

	DDX_Control(pDX, IDC_RDO_STRATEGY_INFO_STOCKS, m_rdo_strategy_info_stocks);
	DDX_Control(pDX, IDC_STC_STRATEGY_INFO_STOCKS, m_stc_strategy_info_stocks);
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


