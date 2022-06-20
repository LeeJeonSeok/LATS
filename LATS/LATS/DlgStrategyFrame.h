#pragma once
#include "DlgChildBase.h"
#include <vector>

// CDlgStrategyFrame 대화 상자

class CDlgStrategyInfo; 
class CDlgStrategyScrollFrame;
class CDlgStrategySave;

class CDlgStrategyFrame : public CDlgChildBase
{
	DECLARE_DYNAMIC(CDlgStrategyFrame)

public:
	CDlgStrategyFrame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgStrategyFrame();


private:

	//Child Dlg
	CDlgStrategyInfo* m_ptr_dlg_strategy_info;
	CDlgStrategyScrollFrame* m_ptr_dlg_strategy_scroll_Frame;
	CDlgStrategySave* m_ptr_dlg_strategy_saver;

	//Vector
	std::vector<CDialogEx*> m_vct_dlg_child;

private:

	//create / delete
	void CreateChild();
	void DeleteChild();
	void CreateChildAndPushBackVector(UINT ResourceID, CDlgChildBase* pChild);

	void ChangeMenuToAfterLogin();

	//virtual
	void SetChildAndControlPosition();

public:


public:

	void SetStrategyMenuState(STRATEGY_MENU::ENUM MenuStyle);
	void SetStrategyTypeText(CString Text);








// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STRATEGY_FRAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
