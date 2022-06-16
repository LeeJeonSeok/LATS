﻿#pragma once
#include "DlgChildBase.h"
#include <vector>

// CDlgStrategyFrame 대화 상자

class CDlgStrategyInfo;
class CDlgStrategyMain;
class CDlgStrategyScroll;
class CDlgStrategySaver;

class CDlgStrategyFrame : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategyFrame)

public:
	CDlgStrategyFrame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyFrame();


private:

	//Child Dlg
	CDlgStrategyInfo* m_ptr_dlg_strategy_info;
	CDlgStrategyMain* m_ptr_dlg_strategy_main;
	CDlgStrategyScroll* m_ptr_dlg_strategy_scroll;
	CDlgStrategySaver* m_ptr_dlg_strategy_saver;

	//Vector
	std::vector<CDlgChildBase*> m_vct_dlg_child;

private:

	//create / delete
	void CreateChild();
	void DeleteChild();
	void CreateChildAndPushBackVector(UINT ResourceID, CDlgChildBase* pChild);

	//virtual
	void SetChildAndControlPosition();

public:


public:









// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_FRAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
