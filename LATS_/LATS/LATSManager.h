#pragma once

class CApiKiwoom;
class CDlgMainFrame;
class CDlgCaption;

class CLATSManager
{
public:
	CLATSManager(CDlgMainFrame* pMainFrame);
	~CLATSManager();


private:

	//API
	CApiKiwoom* m_ptr_api_kiwoom;

	//Dialog
	CDlgMainFrame* m_ptr_dlg_mainframe;
	CDlgCaption* m_ptr_dlg_caption;

private:
	

	//Create / Delete
	void CreateChildDlg();
	void DeleteChildDlg();

public:

	//Setter
	void SetKiwoomApiAddress(CApiKiwoom* m_pKiwoom);

	//Getter
	CApiKiwoom* GetKiwoomApiAddress();
	CDlgCaption* GetCaptionDlgAddress();
	CDlgMainFrame* GetMainframeDlgAddress();

public:

	void SetChildDlgPosition();
};

