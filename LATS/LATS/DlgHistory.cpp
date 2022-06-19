// DlgHistory.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgHistory.h"
#include "afxdialogex.h"


// CDlgHistory 대화 상자

IMPLEMENT_DYNAMIC(CDlgHistory, CDlgChildBase)

CDlgHistory::CDlgHistory(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_USERINFO, pParent)
{

}

CDlgHistory::~CDlgHistory()
{
}

void CDlgHistory::SetChildAndControlPosition()
{
}

void CDlgHistory::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgHistory, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgHistory 메시지 처리기


BOOL CDlgHistory::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(0, 0, 0 ));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
