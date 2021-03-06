
// DlgMainFrame.h : 헤더 파일
//

#pragma once
#include "ApiKiwoom.h"


// CDlgMainFrame 대화 상자
class CLATSManager;
class CDlgMainFrame : public CDialogEx
{
// 생성입니다.
public:
	CDlgMainFrame(CWnd* pParent = NULL);	// 표준 생성자입니다.
	~CDlgMainFrame();

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













// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MAINFRAME };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};
