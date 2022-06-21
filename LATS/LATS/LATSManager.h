#pragma once
#include <vector>


class CApiKiwoom;
class CDlgMainFrame;
class CDlgCaption;
class CDlgStrategyFrame;
class CDlgChildBase;
class CDlgUserInfo;
class CDlgHistory;

class CDlgStrategyInfo; 
class CDlgStrategyScrollFrame;
class CDlgStrategySave;

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
	CDlgUserInfo* m_ptr_dlg_UserInfo;
	CDlgHistory* m_ptr_dlg_history;

	//Strategy Child Dlg
	CDlgStrategyInfo* m_ptr_dlg_strategy_info;
	CDlgStrategyScrollFrame* m_ptr_dlg_strategy_scroll_Frame;
	CDlgStrategySave* m_ptr_dlg_strategy_save;

	//Values
	bool m_bMaxiMize;

	STRATEGY_MENU::ENUM m_strategy_state;

	//Vector
	std::vector<CDlgChildBase*> m_vct_dlg_child;

private:
	

	//Create / Delete
	void CreateChildDlg();
	void DeleteChildDlg();
	void SetCreateChildAndPushBackInVector(UINT nIDTemplate,  CDlgChildBase* pChildDialog);
	void SetCreateStrategyChildAndPushBackInVector(UINT nIDTemplate,  CDlgChildBase* pChildDialog);
	
public:

	//Setter
	void SetKiwoomApiAddress(CApiKiwoom* m_pKiwoom);
	void SetbMaxiMize(bool bMaxi);

	//Getter
	CApiKiwoom* GetKiwoomApiAddress();
	CDlgCaption* GetCaptionDlgAddress();
	CDlgMainFrame* GetMainframeDlgAddress();
	CDlgStrategyFrame* GetStrategyFrameAddress();

	CDlgStrategyInfo* GetStrategyInfoAdress();
	CDlgStrategyScrollFrame* GetStrategyScrollFrameAdress();
	CDlgStrategySave* GetStrategySaveAdress();
	STRATEGY_MENU::ENUM GetStrategyMenuState();

	bool GetbMaxiMize();

	//change Menu
	void ChangeStrategyMenu(STRATEGY_MENU::ENUM MenuStyle);

	void SetChildDlgPosition();
};

