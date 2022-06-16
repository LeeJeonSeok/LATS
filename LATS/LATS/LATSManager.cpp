#include "stdafx.h"
#include "LATSManager.h"
#include "resource.h"

#include "ApiKiwoom.h"
#include "DlgMainFrame.h"
#include "DlgCaption.h"
#include "DlgStrategyFrame.h"



CLATSManager::CLATSManager(CDlgMainFrame* pMainFrame)
{
	m_ptr_dlg_mainframe = pMainFrame;
	CreateChildDlg();
	m_bMaxiMize = false;
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

bool CLATSManager::GetbMaxiMize()
{
	return m_bMaxiMize;
}

void CLATSManager::SetChildDlgPosition()
{
	CRect rt;
	m_ptr_dlg_mainframe->GetClientRect(rt);
	//보더 보정
	rt.bottom -= LATS_BORDER_SIZE_Y;

	m_ptr_dlg_caption->MoveWindow(0, 0, rt.Width(), CTS_HEIGHT);
	m_ptr_dlg_strategy_frame->MoveWindow(0, CTS_HEIGHT, SGS_FRAME_WIDTH, rt.Height());
}
