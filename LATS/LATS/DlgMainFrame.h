
// DlgMainFrame.h : ��� ����
//

#pragma once


// CDlgMainFrame ��ȭ ����
class CLATSManager;
class CDlgMainFrame : public CDialogEx
{
// �����Դϴ�.
public:
	CDlgMainFrame(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

private:

	//Global LATS Manager Class;
	CLATSManager* m_LATSmanager;
	

private:

public:

public:













// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LATS_DIALOG };
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
};
