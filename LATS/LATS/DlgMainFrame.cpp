
// DlgMainFrame.cpp : 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgMainFrame.h"
#include "afxdialogex.h"

#include "LATSManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgMainFrame 대화 상자



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


// CDlgMainFrame 메시지 처리기

BOOL CDlgMainFrame::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_LATSmanager = new CLATSManager(this);

	m_LATSmanager->SetKiwoomApiAddress(&m_api_kiwoom);


	m_LATSmanager->SetChildDlgPosition();
	m_bInit = true;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDlgMainFrame::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDlgMainFrame::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDlgMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if (m_bInit) m_LATSmanager->SetChildDlgPosition();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CDlgMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//작업표시줄 대응
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
