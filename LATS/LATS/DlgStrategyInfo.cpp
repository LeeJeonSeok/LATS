// DlgStrategyInfo.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgStrategyInfo.h"
#include "afxdialogex.h"


// CDlgStrategyInfo 대화 상자

IMPLEMENT_DYNAMIC(CDlgStrategyInfo, CDlgChildBase)

CDlgStrategyInfo::CDlgStrategyInfo(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_STRATEGY_INFO, pParent)
{

}

CDlgStrategyInfo::~CDlgStrategyInfo()
{
}

void CDlgStrategyInfo::SetChildAndControlPosition()
{
}

void CDlgStrategyInfo::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgStrategyInfo, CDlgChildBase)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgStrategyInfo 메시지 처리기


BOOL CDlgStrategyInfo::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(BKC_STRATEGY_INFO);

	m_bInit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgStrategyInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CPen BorderLinePen(PS_SOLID, 1, BLC_BORDER);
	CPen* pOldPen = NULL;
	dc.SelectObject(&BorderLinePen);
	dc.MoveTo(0, SGS_INFO_HEIGHT-1);
	dc.LineTo(SGS_FRAME_WIDTH, SGS_INFO_HEIGHT-1);
	dc.SelectObject(pOldPen);
	BorderLinePen.DeleteObject();
					   // 그리기 메시지에 대해서는 CDlgChildBase::OnPaint()을(를) 호출하지 마십시오.
}
