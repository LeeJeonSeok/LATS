// DlgCaption.cpp: 구현 파일
//
#include "stdafx.h"
#include "LATS.h"
#include "DlgCaption.h"
#include "afxdialogex.h"


// CDlgCaption 대화 상자

IMPLEMENT_DYNAMIC(CDlgCaption, CDialogEx)

CDlgCaption::CDlgCaption(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_CAPTION, pParent)
{
	m_bInit = false;
}

CDlgCaption::~CDlgCaption()
{
}

void CDlgCaption::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_CAPTION_ICON, m_btn_caption_icon);
	DDX_Control(pDX, IDC_BTN_CAPTION_HIDE, m_btn_caption_hide);
	DDX_Control(pDX, IDC_BTN_CAPTION_MINMAX, m_btn_caption_minmax);
	DDX_Control(pDX, IDC_BTN_CAPTION_CLOSE, m_btn_caption_close);
	DDX_Control(pDX, IDC_STC_CAPTION_INFO, m_stc_caption_info);
}


BEGIN_MESSAGE_MAP(CDlgCaption, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgCaption 메시지 처리기


void CDlgCaption::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


BOOL CDlgCaption::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(CR_CAPTION);

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CDlgCaption::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_RETURN == pMsg->wParam || VK_ESCAPE == pMsg->wParam)
		{
			return 0;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
