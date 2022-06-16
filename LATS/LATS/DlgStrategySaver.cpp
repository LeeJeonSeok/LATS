// DlgStrategySaver.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategySaver.h"
#include "afxdialogex.h"


// CDlgStrategySaver 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategySaver, CDlgChildBase)

CDlgStrategySaver::CDlgStrategySaver(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_SAVER, pParent)
{

}

CDlgStrategySaver::~CDlgStrategySaver()
{
}

void CDlgStrategySaver::SetChildAndControlPosition()
{
}

void CDlgStrategySaver::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategySaver, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgStrategySaver 메시지 처리기


BOOL CDlgStrategySaver::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(BKC_STRATEGY_SAVER);

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

