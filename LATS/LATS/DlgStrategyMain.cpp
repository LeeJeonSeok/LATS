// DlgStrategyMain.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyMain.h"
#include "afxdialogex.h"


// CDlgStrategyMain 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyMain, CDlgScrollBase)

CDlgStrategyMain::CDlgStrategyMain(CWnd* pParent /*=nullptr*/)
	: CDlgScrollBase(IDD_DLG_STRATEGY_MAIN, pParent)
{

}

CDlgStrategyMain::~CDlgStrategyMain()
{
}

void CDlgStrategyMain::DoDataExchange(CDataExchange* pDX)
{
	CDlgScrollBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyMain, CDlgScrollBase)
END_MESSAGE_MAP()


// CDlgStrategyMain 메시지 처리기
