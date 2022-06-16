#pragma once
#include "DlgScrollBase.h"

// CDlgStrategyScroll 대화 상자

class CDlgStrategyScroll : public CDlgScrollBase
{
	DECLARE_DYNAMIC(CDlgStrategyScroll)

public:
	CDlgStrategyScroll(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyScroll();

private:

	CMyImageScrollBar m_btn_strategy_scroll_upper;
	CMyImageScrollBar m_btn_strategy_scroll_center;
	CMyImageScrollBar m_btn_strategy_scroll_lower;

private:

	//virtual
	void SetChildAndControlPosition();

public:

public:









// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_SCROLL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnStrategyScrollUpper();
	afx_msg void OnBnClickedBtnStrategyScrollLower();
};
