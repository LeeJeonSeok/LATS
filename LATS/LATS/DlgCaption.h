#pragma once
#include"stdafx.h"
#include "MyCaptionButton.h"


// CDlgCaption 대화 상자

class CDlgCaption : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCaption)

public:
	CDlgCaption(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgCaption();


private:

	//controls
	CBitmapButton m_btn_caption_icon;
	CMyCaptionButton m_btn_caption_hide;
	CMyCaptionButton m_btn_caption_minmax;
	CMyCaptionButton m_btn_caption_close;
	CStatic m_stc_caption_info;



	//initializing
	bool m_bInit;


private:

public:

public:





// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAPTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
