#pragma once
#include "DlgChildBase.h"

// CDlgStrategySaver 대화 상자

class CDlgStrategySaver : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategySaver)

public:
	CDlgStrategySaver(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategySaver();

private:

private:

	//virtual
	void SetChildAndControlPosition();

public:

public:









// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_SAVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
