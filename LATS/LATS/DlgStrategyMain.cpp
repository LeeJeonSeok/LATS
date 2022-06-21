// DlgStrategyMain.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyMain.h"
#include "afxdialogex.h"


// CDlgStrategyMain 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyMain, CDlgScrollBase)

CDlgStrategyMain::CDlgStrategyMain(CWnd* pParent /*=nullptr*/)
	: CDlgScrollBase(IDD_DLG_STRATEGY_MAIN, pParent)
{
	m_nSizeDlg[0] = STRATEGY::SIZE_WIDTH_MAIN;
	m_nSizeDlg[1] = 1000 + 10;
}

CDlgStrategyMain::~CDlgStrategyMain()
{
}


void CDlgStrategyMain::HideAllControls()
{
}

void CDlgStrategyMain::SetPlaceToBuyMenu()
{
}

void CDlgStrategyMain::SetPlaceToCellMenu()
{
}

void CDlgStrategyMain::SetPlaceToMoneyMenu()
{
}

void CDlgStrategyMain::DoDataExchange(CDataExchange* pDX)
{
	CDlgScrollBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyMain, CDlgScrollBase)
END_MESSAGE_MAP()


// CDlgStrategyMain 메시지 처리기


BOOL CDlgStrategyMain::OnInitDialog()
{
	CDlgScrollBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetScrollDialogType(SCROLL_TYPE::MENU, SCROLL_ORIENTATION::VERTICAL);
	MoveWindowScrollDialog();

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
