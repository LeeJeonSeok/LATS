// DlgStrategySaver.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategySave.h"
#include "afxdialogex.h"


// CDlgStrategySave 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategySave, CDlgChildBase)

CDlgStrategySave::CDlgStrategySave(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_SAVE, pParent)
{

}

CDlgStrategySave::~CDlgStrategySave()
{
}

void CDlgStrategySave::SetChildAndControlPosition()
{
}

void CDlgStrategySave::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategySave, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgStrategySave 메시지 처리기


BOOL CDlgStrategySave::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(STRATEGY::COLOR_BKGROUND_SAVE);

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

