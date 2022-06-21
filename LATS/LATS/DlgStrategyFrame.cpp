// DlgStrategyFrame.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyFrame.h"
#include "afxdialogex.h"

#include "DlgStrategyInfo.h"
#include "DlgStrategyScrollFrame.h"
#include "DlgStrategySave.h"
#include "LATSManager.h"

// CDlgStrategyFrame 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyFrame, CDialogEx)

CDlgStrategyFrame::CDlgStrategyFrame(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_FRAME, pParent)
{
}

CDlgStrategyFrame::~CDlgStrategyFrame()
{
}

void CDlgStrategyFrame::SetChildDlgPosition()
{
	CRect FrameRect;
	GetClientRect(&FrameRect);
	m_ptr_LATSManager->GetStrategyInfoAdress()->MoveWindow(0, 0, STRATEGY::SIZE_WIDTH_FRAME, STRATEGY::SIZE_HEIGHT_INFO);
	m_ptr_LATSManager->GetStrategyScrollFrameAdress()->MoveWindow(0, STRATEGY::SIZE_HEIGHT_INFO, STRATEGY::SIZE_WIDTH_FRAME, FrameRect.Height() - STRATEGY::SIZE_HEIGHT_INFO - STRATEGY::SIZE_HEIGHT_SAVE);
	m_ptr_LATSManager->GetStrategySaveAdress()->MoveWindow(0, FrameRect.Height() - STRATEGY::SIZE_HEIGHT_SAVE, STRATEGY::SIZE_WIDTH_FRAME, STRATEGY::SIZE_HEIGHT_SAVE);
}


void CDlgStrategyFrame::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyFrame, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgStrategyFrame 메시지 처리기


BOOL CDlgStrategyFrame::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
