#include "stdafx.h"
#include "LATSManager.h"
#include "resource.h"

#include "ApiKiwoom.h"
#include "DlgMainFrame.h"
#include "DlgCaption.h"



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
	m_ptr_dlg_caption->Create(IDD_DLG_CAPTION, m_ptr_dlg_mainframe);
	m_ptr_dlg_caption->SetLATSManagerAddress(this);
	m_ptr_dlg_caption->ShowWindow(true);
}

void CLATSManager::DeleteChildDlg()
{
	delete(m_ptr_dlg_caption);
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

bool CLATSManager::GetbMaxiMize()
{
	return m_bMaxiMize;
}

void CLATSManager::SetChildDlgPosition()
{
	CRect rt;
	m_ptr_dlg_mainframe->GetClientRect(rt);

	m_ptr_dlg_caption->MoveWindow(0, 0, rt.Width(), CS_HEIGHT);
}
