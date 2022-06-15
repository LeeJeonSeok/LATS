// DlgStrategyFrame.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyFrame.h"
#include "afxdialogex.h"


// CDlgStrategyFrame 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyFrame, CDialogEx)

CDlgStrategyFrame::CDlgStrategyFrame(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_FRAME, pParent)
{

}

CDlgStrategyFrame::~CDlgStrategyFrame()
{
}

void CDlgStrategyFrame::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyFrame, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgStrategyFrame 메시지 처리기
