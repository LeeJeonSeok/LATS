#pragma once
#include "DlgScrollBase.h"

// CDlgStrategyMain 대화 상자

class CDlgStrategyMain : public CDlgScrollBase
{
	DECLARE_DYNAMIC(CDlgStrategyMain)

public:
	CDlgStrategyMain(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyMain();

private:

private:

public:

public:

	//ChangeMenu
	void HideAllControls();
	void SetPlaceToBuyMenu();
	void SetPlaceToCellMenu();
	void SetPlaceToMoneyMenu();




// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
