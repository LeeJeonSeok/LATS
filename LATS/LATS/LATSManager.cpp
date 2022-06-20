#include "stdafx.h"
#include "LATSManager.h"
#include "resource.h"

#include "ApiKiwoom.h"
#include "DlgMainFrame.h"
#include "DlgCaption.h"
#include "DlgStrategyFrame.h"
#include "DlgUserInfo.h"
#include "DlgHistory.h"



CLATSManager::CLATSManager(CDlgMainFrame* pMainFrame)
{
	m_ptr_dlg_mainframe = pMainFrame;
	CreateChildDlg();
	m_bMaxiMize = false;
	m_strategy_state = STRATEGY_MENU::BUY;
}

CLATSManager::~CLATSManager()
{
	DeleteChildDlg();
}

void CLATSManager::CreateChildDlg()
{
	m_ptr_dlg_caption = new CDlgCaption();
	SetCreateChildAndPushBackInVector(IDD_DLG_CAPTION,  m_ptr_dlg_caption);
	m_ptr_dlg_caption->SetLATSManagerAddress(this);
	m_ptr_dlg_caption->ShowWindow(true);

	m_ptr_dlg_strategy_frame = new CDlgStrategyFrame();
	SetCreateChildAndPushBackInVector(IDD_DLG_STRATEGY_FRAME,  m_ptr_dlg_strategy_frame);
	m_ptr_dlg_strategy_frame->SetLATSManagerAddress(this);
	m_ptr_dlg_strategy_frame->ShowWindow(true);

	m_ptr_dlg_UserInfo = new CDlgUserInfo();
	SetCreateChildAndPushBackInVector(IDD_DLG_USERINFO, m_ptr_dlg_UserInfo);
	m_ptr_dlg_UserInfo->SetLATSManagerAddress(this);
	m_ptr_dlg_UserInfo->ShowWindow(true);

	m_ptr_dlg_history = new CDlgHistory();
	SetCreateChildAndPushBackInVector(IDD_DLG_HISTORY, m_ptr_dlg_history);
	m_ptr_dlg_history->SetLATSManagerAddress(this);
	m_ptr_dlg_history->ShowWindow(true);
}

void CLATSManager::DeleteChildDlg()
{
	for (int i = 0; i < m_vct_dlg_child.size(); i++)
	{
		delete(m_vct_dlg_child[i]);
	}
	m_vct_dlg_child.clear();
}

void CLATSManager::SetCreateChildAndPushBackInVector(UINT nIDTemplate,  CDlgChildBase * pChildDialog)
{
	pChildDialog->Create(nIDTemplate, m_ptr_dlg_mainframe);
	m_vct_dlg_child.push_back(pChildDialog);
}

void CLATSManager::SetKiwoomApiAddress(CApiKiwoom* pKiwoom)
{
	m_ptr_api_kiwoom = pKiwoom;
}

void CLATSManager::SetbMaxiMize(bool bMaxi)
{
	m_bMaxiMize = bMaxi;
}

CApiKiwoom* CLATSManager::GetKiwoomApiAddress()
{
	return m_ptr_api_kiwoom;
}

CDlgCaption* CLATSManager::GetCaptionDlgAddress()
{
	return m_ptr_dlg_caption;
}

CDlgMainFrame* CLATSManager::GetMainframeDlgAddress()
{
	return m_ptr_dlg_mainframe;
}

CDlgStrategyFrame * CLATSManager::GetStrategyFrameAddress()
{
	return nullptr;
}

STRATEGY_MENU::ENUM CLATSManager::GetStrategyMenuState()
{
	return m_strategy_state;
}

bool CLATSManager::GetbMaxiMize()
{
	return m_bMaxiMize;
}

void CLATSManager::ChangeStrategyMenu(STRATEGY_MENU::ENUM MenuStyle)
{
	switch (MenuStyle)
	{
	case STRATEGY_MENU::BUY:
		m_ptr_dlg_strategy_frame->SetStrategyTypeText("매수설정");
		break;
	case STRATEGY_MENU::CELL:
		m_ptr_dlg_strategy_frame->SetStrategyTypeText("매도설정");
		break;
	case STRATEGY_MENU::MONEY:
		m_ptr_dlg_strategy_frame->SetStrategyTypeText("자금운용");
		break;

	}
	m_strategy_state = MenuStyle;
	m_ptr_dlg_strategy_frame->SetStrategyMenuState(MenuStyle);
}

void CLATSManager::SetChildDlgPosition()
{
	CRect rt;
	m_ptr_dlg_mainframe->GetClientRect(rt);
	//보더 보정
	rt.bottom -= LATS::SIZE_HEIGHT_BORDER;

	m_ptr_dlg_caption->MoveWindow(0, 0, rt.Width(), CAPTION::SIZE_HEIGHT);
	m_ptr_dlg_strategy_frame->MoveWindow(0, CAPTION::SIZE_HEIGHT, STRATEGY::SIZE_FRAME_WIDTH, rt.Height());
	m_ptr_dlg_UserInfo->MoveWindow(STRATEGY::SIZE_FRAME_WIDTH, rt.Height() + CAPTION::SIZE_HEIGHT - USER_INFO::SIZE_HEIGHT, rt.Width()  - STRATEGY::SIZE_FRAME_WIDTH, USER_INFO::SIZE_HEIGHT);
	m_ptr_dlg_history->MoveWindow(STRATEGY::SIZE_FRAME_WIDTH, CAPTION::SIZE_HEIGHT, rt.Width() - STRATEGY::SIZE_FRAME_WIDTH, rt.Height() - USER_INFO::SIZE_HEIGHT);
}
