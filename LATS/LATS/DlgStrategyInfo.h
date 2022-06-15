﻿#pragma once
#include "DlgChildBase.h"

// CDlgStrategyInfo 대화 상자

class CDlgStrategyInfo : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategyInfo)

public:
	CDlgStrategyInfo(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyInfo();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};