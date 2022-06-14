#pragma once


class CDlgMainFrame;
class CDlgCaption;

class CLATSManager
{
public:
	CLATSManager(CDlgMainFrame* pMainFrame);
	~CLATSManager();


private:

	//Dialog
	CDlgMainFrame* m_ptr_dlg_mainframe;
	CDlgCaption* m_ptr_dlg_caption;

private:
	

	//Create / Delete
	void CreateChildDlg();
	void DeleteChildDlg();

public:

public:

};

