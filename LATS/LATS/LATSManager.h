#pragma once
#include <vector>


class CApiKiwoom;
class CDlgMainFrame;
class CDlgCaption;
class CDlgStrategyFrame;
class CDlgChildBase;

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
	CDlgStrategyFrame* m_ptr_dlg_strategy_frame;

	//Values
	bool m_bMaxiMize;

	//Vector
	std::vector<CDlgChildBase*> m_vct_dlg_child;

private:
	

	//Create / Delete
	void CreateChildDlg();
	void DeleteChildDlg();
	void SetCreateChildAndPushBackInVector(UINT nIDTemplate,  CDlgChildBase* pChildDialog);
	
public:

	//Setter
	void SetKiwoomApiAddress(CApiKiwoom* m_pKiwoom);
	void SetbMaxiMize(bool bMaxi);

	//Getter
	CApiKiwoom* GetKiwoomApiAddress();
	CDlgCaption* GetCaptionDlgAddress();
	CDlgMainFrame* GetMainframeDlgAddress();
	CDlgStrategyFrame* GetStrategyFrameAddress();
	bool GetbMaxiMize();

public:

	void SetChildDlgPosition();
};

