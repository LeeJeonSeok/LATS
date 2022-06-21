#include "stdafx.h"
#include "LATSManager.h"
#include "resource.h"

#include "ApiKiwoom.h"
#include "DlgMainFrame.h"
#include "DlgCaption.h"
#include "DlgStrategyFrame.h"
#include "DlgUserInfo.h"
#include "DlgHistory.h"

#include "DlgStrategyInfo.h"
#include "DlgStrategyScrollFrame.h"
#include "DlgStrategySave.h"



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
	//Main
	m_ptr_dlg_caption = new CDlgCaption();
	SetCreateChildAndPushBackInVector(IDD_DLG_CAPTION,  m_ptr_dlg_caption);

	m_ptr_dlg_strategy_frame = new CDlgStrategyFrame();
	SetCreateChildAndPushBackInVector(IDD_DLG_STRATEGY_FRAME,  m_ptr_dlg_strategy_frame);

	m_ptr_dlg_UserInfo = new CDlgUserInfo();
	SetCreateChildAndPushBackInVector(IDD_DLG_USERINFO, m_ptr_dlg_UserInfo);

	m_ptr_dlg_history = new CDlgHistory();
	SetCreateChildAndPushBackInVector(IDD_DLG_HISTORY, m_ptr_dlg_history);


	//strategy Child
	m_ptr_dlg_strategy_info = new CDlgStrategyInfo();
	 SetCreateStrategyChildAndPushBackInVector(IDD_DLG_STRATEGY_INFO, m_ptr_dlg_strategy_info);

	 m_ptr_dlg_strategy_scroll_Frame = new CDlgStrategyScrollFrame();
	 SetCreateStrategyChildAndPushBackInVector(IDD_DLG_STRATEGY_SCROLL_FRAME, m_ptr_dlg_strategy_scroll_Frame);

	 m_ptr_dlg_strategy_save = new CDlgStrategySave();
	SetCreateStrategyChildAndPushBackInVector(IDD_DLG_STRATEGY_SAVE, m_ptr_dlg_strategy_save);

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
	pChildDialog->SetLATSManagerAddress(this);
	pChildDialog->ShowWindow(true);
}

void CLATSManager::SetCreateStrategyChildAndPushBackInVector(UINT nIDTemplate, CDlgChildBase * pChildDialog)
{
	pChildDialog->Create(nIDTemplate, m_ptr_dlg_strategy_frame);
	m_vct_dlg_child.push_back(pChildDialog);
	pChildDialog->SetLATSManagerAddress(this);
	pChildDialog->ShowWindow(true);
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
	return m_ptr_dlg_strategy_frame;
}

CDlgStrategyInfo * CLATSManager::GetStrategyInfoAdress()
{
	return m_ptr_dlg_strategy_info;
}

CDlgStrategyScrollFrame * CLATSManager::GetStrategyScrollFrameAdress()
{
	return m_ptr_dlg_strategy_scroll_Frame;
}

CDlgStrategySave * CLATSManager::GetStrategySaveAdress()
{
	return m_ptr_dlg_strategy_save;
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
	m_strategy_state = MenuStyle;
	m_ptr_dlg_strategy_scroll_Frame->SetStrategyMenuState(MenuStyle);
}

void CLATSManager::SetChildDlgPosition()
{
	CRect rt;
	m_ptr_dlg_mainframe->GetClientRect(rt);
	//보더 보정
	rt.bottom -= LATS::SIZE_HEIGHT_BORDER;

	m_ptr_dlg_caption->MoveWindow(0, 0, rt.Width(), CAPTION::SIZE_HEIGHT);
	m_ptr_dlg_strategy_frame->MoveWindow(0, CAPTION::SIZE_HEIGHT, STRATEGY::SIZE_WIDTH_FRAME, rt.Height());
	m_ptr_dlg_UserInfo->MoveWindow(STRATEGY::SIZE_WIDTH_FRAME, rt.Height() + CAPTION::SIZE_HEIGHT - USER_INFO::SIZE_HEIGHT, rt.Width()  - STRATEGY::SIZE_WIDTH_FRAME, USER_INFO::SIZE_HEIGHT);
	m_ptr_dlg_history->MoveWindow(STRATEGY::SIZE_WIDTH_FRAME, CAPTION::SIZE_HEIGHT, rt.Width() - STRATEGY::SIZE_WIDTH_FRAME, rt.Height() - USER_INFO::SIZE_HEIGHT);

	m_ptr_dlg_strategy_frame->SetChildDlgPosition();
}
