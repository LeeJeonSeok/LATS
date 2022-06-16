#pragma once
#include "DlgChildBase.h"

// CDlgStrategyScrollFrame 대화 상자

class CDlgStrategyScrollFrame : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategyScrollFrame)

public:
	CDlgStrategyScrollFrame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyScrollFrame();


private:

private:

	//virtual
	void SetChildAndControlPosition();

public:

public:




// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_SCROLL_FRAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
