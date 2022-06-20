#pragma once
#include "DlgChildBase.h"

// CDlgStrategySave 대화 상자

class CDlgStrategySave : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategySave)

public:
	CDlgStrategySave(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategySave();

private:

private:

	//virtual
	void SetChildAndControlPosition();

public:

public:









// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_SAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
