#pragma once
#include "DlgChildBase.h"

// CDlgStrategyInfo 대화 상자

class CDlgStrategyInfo : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategyInfo)

public:
	CDlgStrategyInfo(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyInfo();
	
private:
	//controls
	CMyImageTextButton m_rdo_strategy_info_buy;
	CStatic m_stc_strategy_info_buy;

	CMyImageTextButton m_rdo_strategy_info_cell;
	CStatic m_stc_strategy_info_cell;

	CMyImageTextButton m_rdo_strategy_info_money;
	CStatic m_stc_strategy_info_money;

	CMyImageTextButton m_rdo_strategy_info_stocks;
	CStatic m_stc_strategy_info_stocks;

private:


public:

public:

	//virtual
	void SetChildAndControlPosition();







// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
