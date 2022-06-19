#pragma once
#include "DlgChildBase.h"

// CDlgHistory 대화 상자

class CDlgHistory : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgHistory)

public:
	CDlgHistory(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgHistory();



private:


private:

	//virtual
	void SetChildAndControlPosition();

public:

public:





// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_USERINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
