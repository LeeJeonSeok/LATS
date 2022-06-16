
// DlgMainFrame.cpp : ���� ����
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgMainFrame.h"
#include "afxdialogex.h"

#include "LATSManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgMainFrame ��ȭ ����



CDlgMainFrame::CDlgMainFrame(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_MAINFRAME, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bInit = false;
}

CDlgMainFrame::~CDlgMainFrame()
{
	delete(m_LATSmanager);
}

void CDlgMainFrame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_API_KIWOOM, m_api_kiwoom);

}

BEGIN_MESSAGE_MAP(CDlgMainFrame, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()


// CDlgMainFrame �޽��� ó����

BOOL CDlgMainFrame::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_LATSmanager = new CLATSManager(this);

	m_LATSmanager->SetKiwoomApiAddress(&m_api_kiwoom);


	m_LATSmanager->SetChildDlgPosition();
	m_bInit = true;
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CDlgMainFrame::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CDlgMainFrame::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDlgMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if (m_bInit) m_LATSmanager->SetChildDlgPosition();
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CDlgMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//�۾�ǥ���� ����
	RECT rectWorkArea;
	MONITORINFO mi;
	mi.cbSize = sizeof(mi);
	::GetMonitorInfo(::MonitorFromWindow(this->m_hWnd, MONITOR_DEFAULTTONEAREST), &mi);
	rectWorkArea = mi.rcWork;
	int cx = rectWorkArea.right - rectWorkArea.left;
	int cy = rectWorkArea.bottom - rectWorkArea.top;


	lpMMI->ptMaxTrackSize.x = cx + (GetSystemMetrics(SM_CXDLGFRAME) * 2) + (GetSystemMetrics(SM_CXPADDEDBORDER) * 2);
	lpMMI->ptMaxTrackSize.y = cy + (GetSystemMetrics(SM_CYDLGFRAME) * 2) + (GetSystemMetrics(SM_CXPADDEDBORDER) * 2);

	lpMMI->ptMinTrackSize.x = MFS_WIDTH;
	lpMMI->ptMinTrackSize.y = MFS_HEIGHT;
	CDialogEx::OnGetMinMaxInfo(lpMMI);
}
