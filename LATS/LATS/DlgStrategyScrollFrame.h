#pragma once
#include "DlgChildBase.h"

// CDlgStrategyScrollFrame 대화 상자

class CDlgStrategyScroll;
class CDlgStrategyMain;
class CDlgStrategyScrollFrame : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategyScrollFrame)

public:
	CDlgStrategyScrollFrame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyScrollFrame();


private:
	bool m_bInit;

	//ScrollDialog
	CDlgStrategyScroll* m_ptr_dlg_strategy_scroll;
	CDlgStrategyMain* m_ptr_dlg_strategy_main;

private:

	//virtual
	void SetChildAndControlPosition();

public:

public:
	//ChangeMenu
	void SetStrategyMenuState(STRATEGY_MENU::ENUM MenuStyle);


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_SCROLL_FRAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
