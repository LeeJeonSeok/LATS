// DlgStrategyFrame.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyFrame.h"
#include "afxdialogex.h"

#include "DlgStrategyInfo.h"
#include "DlgStrategyScrollFrame.h"
#include "DlgStrategySave.h"

// CDlgStrategyFrame 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyFrame, CDialogEx)

CDlgStrategyFrame::CDlgStrategyFrame(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_FRAME, pParent)
{
}

CDlgStrategyFrame::~CDlgStrategyFrame()
{
	DeleteChild();
}

void CDlgStrategyFrame::CreateChildAndPushBackVector(UINT ResourceID, CDialogEx* pChild)
{
	pChild->Create(ResourceID, this);
	m_vct_dlg_child.push_back(pChild);
}

void CDlgStrategyFrame::ChangeMenuToAfterLogin()
{
	m_ptr_dlg_strategy_info->SetChildAndControlPosition();
}


void CDlgStrategyFrame::CreateChild()
{
	 m_ptr_dlg_strategy_info = new CDlgStrategyInfo();
	 CreateChildAndPushBackVector(IDD_DLG_STRATEGY_INFO, m_ptr_dlg_strategy_info);
	 m_ptr_dlg_strategy_info->ShowWindow(true);

	 m_ptr_dlg_strategy_scroll_Frame = new CDlgStrategyScrollFrame();
	 CreateChildAndPushBackVector(IDD_DLG_STRATEGY_SCROLL_FRAME, m_ptr_dlg_strategy_scroll_Frame);
	 m_ptr_dlg_strategy_scroll_Frame->ShowWindow(true);

	 m_ptr_dlg_strategy_saver = new CDlgStrategySave();
	CreateChildAndPushBackVector(IDD_DLG_STRATEGY_SAVE, m_ptr_dlg_strategy_saver);
	 m_ptr_dlg_strategy_saver->ShowWindow(true);
}

void CDlgStrategyFrame::DeleteChild()
{
	for (int i = 0; i < m_vct_dlg_child.size(); i++)
	{
		delete(m_vct_dlg_child[i]);
	}
	m_vct_dlg_child.clear();
}

void CDlgStrategyFrame::SetChildAndControlPosition()
{
	CRect rt;
	GetClientRect(rt);
	
	int nMenuHeight = rt.Height() - STRATEGY::SIZE_HEIGHT_INFO - STRATEGY::SIZE_HEIGHT_SAVE;
	int nScrollHeight = rt.Height() - STRATEGY::SIZE_HEIGHT_SAVE;

	m_ptr_dlg_strategy_info->MoveWindow(0, 0, STRATEGY::SIZE_FRAME_WIDTH, STRATEGY::SIZE_HEIGHT_INFO);
	m_ptr_dlg_strategy_scroll_Frame->MoveWindow(0, STRATEGY::SIZE_HEIGHT_INFO, STRATEGY::SIZE_FRAME_WIDTH, nMenuHeight);
	m_ptr_dlg_strategy_saver->MoveWindow(0, nScrollHeight, STRATEGY::SIZE_FRAME_WIDTH, STRATEGY::SIZE_HEIGHT_SAVE);
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
	CreateChild();

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
