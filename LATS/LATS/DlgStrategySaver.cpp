// DlgStrategySaver.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategySaver.h"
#include "afxdialogex.h"


// CDlgStrategySaver 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategySaver, CDlgChildBase)

CDlgStrategySaver::CDlgStrategySaver(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_SAVER, pParent)
{

}

CDlgStrategySaver::~CDlgStrategySaver()
{
}

void CDlgStrategySaver::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategySaver, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgStrategySaver 메시지 처리기
