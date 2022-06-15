// DlgStrategyScroll.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyScroll.h"
#include "afxdialogex.h"


// CDlgStrategyScroll 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyScroll, CDlgScrollBase)

CDlgStrategyScroll::CDlgStrategyScroll(CWnd* pParent /*=nullptr*/)
	: CDlgScrollBase(IDD_DLG_STRATEGY_SCROLL, pParent)
{

}

CDlgStrategyScroll::~CDlgStrategyScroll()
{
}

void CDlgStrategyScroll::DoDataExchange(CDataExchange* pDX)
{
	CDlgScrollBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyScroll, CDlgScrollBase)
END_MESSAGE_MAP()


// CDlgStrategyScroll 메시지 처리기
