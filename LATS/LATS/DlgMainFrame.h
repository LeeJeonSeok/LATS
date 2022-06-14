
// DlgMainFrame.h : ��� ����
//

#pragma once
#include "ApiKiwoom.h"


// CDlgMainFrame ��ȭ ����
class CLATSManager;
class CDlgMainFrame : public CDialogEx
{
// �����Դϴ�.
public:
	CDlgMainFrame(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

private:

	//Global LATS Manager Class
	CLATSManager* m_LATSmanager;
	
	//API
	CApiKiwoom m_api_kiwoom;

	//Values
	bool m_bInit;

private:

public:

public:













// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MAINFRAME };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
