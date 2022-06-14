#include "stdafx.h"
#include "LATSManager.h"
#include "resource.h"

#include "DlgMainFrame.h"
#include "DlgCaption.h"



CLATSManager::CLATSManager(CDlgMainFrame* pMainFrame)
{
	m_ptr_dlg_mainframe = pMainFrame;
	CreateChildDlg();
}

CLATSManager::~CLATSManager()
{
	DeleteChildDlg();
}

void CLATSManager::CreateChildDlg()
{
	m_ptr_dlg_caption = new CDlgCaption();
	m_ptr_dlg_caption->Create(IDD_DLG_CAPTION, m_ptr_dlg_mainframe);
	m_ptr_dlg_caption->ShowWindow(true);
}

void CLATSManager::DeleteChildDlg()
{
	delete(m_ptr_dlg_caption);
}
