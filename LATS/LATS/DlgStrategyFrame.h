#pragma once
#include "DlgChildBase.h"

// CDlgStrategyFrame 대화 상자

class CDlgStrategyFrame : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategyFrame)

public:
	CDlgStrategyFrame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyFrame();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_FRAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
