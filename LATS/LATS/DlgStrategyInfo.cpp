// DlgStrategyInfo.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyInfo.h"
#include "afxdialogex.h"


// CDlgStrategyInfo 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyInfo, CDlgChildBase)

CDlgStrategyInfo::CDlgStrategyInfo(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_INFO, pParent)
{

}

CDlgStrategyInfo::~CDlgStrategyInfo()
{
}

void CDlgStrategyInfo::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyInfo, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgStrategyInfo 메시지 처리기
