// DlgStrategyScrollFrame.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyScrollFrame.h"
#include "afxdialogex.h"


// CDlgStrategyScrollFrame 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyScrollFrame, CDlgChildBase)

CDlgStrategyScrollFrame::CDlgStrategyScrollFrame(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_SCROLL_FRAME, pParent)
{

}

CDlgStrategyScrollFrame::~CDlgStrategyScrollFrame()
{
}

void CDlgStrategyScrollFrame::SetChildAndControlPosition()
{
}

void CDlgStrategyScrollFrame::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyScrollFrame, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgStrategyScrollFrame 메시지 처리기
