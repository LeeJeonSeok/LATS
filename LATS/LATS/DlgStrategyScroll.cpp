// DlgStrategyScroll.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyScroll.h"
#include "afxdialogex.h"


// CDlgStrategyScroll 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyScroll, CDlgScrollBase)

CDlgStrategyScroll::CDlgStrategyScroll(CWnd* pParent /*=nullptr*/)
	: CDlgScrollBase(IDD_DLG_STRATEGY_SCROLL, pParent)
{

}

CDlgStrategyScroll::~CDlgStrategyScroll()
{
}

void CDlgStrategyScroll::SetChildAndControlPosition()
{
}

void CDlgStrategyScroll::DoDataExchange(CDataExchange* pDX)
{
	CDlgScrollBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyScroll, CDlgScrollBase)
END_MESSAGE_MAP()


// CDlgStrategyScroll 메시지 처리기


BOOL CDlgStrategyScroll::OnInitDialog()
{
	CDlgScrollBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(BKC_STRATEGY_SCROLL);

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
