
// DlgMainFrame.h : Çì´õ ÆÄÀÏ
//

#pragma once
#include "ApiKiwoom.h"


// CDlgMainFrame ´ëÈ­ »óÀÚ
class CLATSManager;
class CDlgMainFrame : public CDialogEx
{
// »ı¼ºÀÔ´Ï´Ù.
public:
	CDlgMainFrame(CWnd* pParent = NULL);	// Ç¥ÁØ »ı¼ºÀÚÀÔ´Ï´Ù.

private:

	//Global LATS Manager Class;
	CLATSManager* m_LATSmanager;
	
<<<<<<< HEAD
	//API
	CApiKiwoom m_api_kiwoom;

	//Values
	bool m_bInit;
=======
>>>>>>> parent of 78be566 (ëˆ„ë½ì •ë³´ ì»¤ë°‹)

private:

public:

public:













// ´ëÈ­ »óÀÚ µ¥ÀÌÅÍÀÔ´Ï´Ù.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MAINFRAME };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV Áö¿øÀÔ´Ï´Ù.


// ±¸ÇöÀÔ´Ï´Ù.
protected:
	HICON m_hIcon;

	// »ı¼ºµÈ ¸Ş½ÃÁö ¸Ê ÇÔ¼ö
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
