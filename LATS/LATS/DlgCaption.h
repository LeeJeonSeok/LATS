#pragma once
#include"stdafx.h"
#include "MyCaptionButton.h"
#include "DlgChildBase.h"
// CDlgCaption 대화 상자

class CDlgCaption : public CDlgChildBase
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



private:
	void SetControlPosition();

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
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBtnCaptionHide();
	afx_msg void OnBnClickedBtnCaptionMinmax();
	afx_msg void OnBnClickedBtnCaptionClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
