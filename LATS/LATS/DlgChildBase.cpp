#include "stdafx.h"
#include "DlgChildBase.h"



CDlgChildBase::CDlgChildBase(UINT ResourceID, CWnd* pParent)
	: CDialogEx(ResourceID, pParent)
{
	m_bInit = false;
}

CDlgChildBase::~CDlgChildBase()
{
	m_fnt_caption.DeleteObject();
}

void CDlgChildBase::SetLATSManagerAddress(CLATSManager* pManager)
{
	m_ptr_LATSManager = pManager;
}
BEGIN_MESSAGE_MAP(CDlgChildBase, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()

void CDlgChildBase::SetChildAndControlPosition()
{
}

CRect CDlgChildBase::SetStaticAndEditPosition(CRect & rt, CWnd & Static, CString StaticText, CWnd & Edit, bool bUsingGroupBox)
{
	return rt;
}

CRect CDlgChildBase::SetRadioCheckAndStaticPosition_1P(CRect & rt, CWnd & Button, CWnd & Static, CString StaticText, bool bUsingGroupBox, bool bRadio)
{
	return rt;
}

CRect CDlgChildBase::SetRadioCheckAndStaticPosition_2P(CRect & rt, CWnd & Button1, CWnd & Static1, CString Static1Text, CWnd & Button2, CWnd & Static2, CString Static2Text, bool bUsingGroupBox, bool bRadio)
{
	return rt;
}

CRect CDlgChildBase::SetButtonPositionAndText_1P(CRect & rt, CWnd & Button, CString ButtonText, bool bUsingGroupBox)
{
	return rt;
}

CRect CDlgChildBase::SetButtonPositionAndText_2P(CRect & rt, CWnd & Button1, CString Button1Text, CWnd & Button2, CString Button2Text, bool bUsingGroupBox)
{
	return rt;
}

void CDlgChildBase::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//초기화 후 다이얼로그 배치
	if(m_bInit) SetChildAndControlPosition();

	//잔상 방지
	Invalidate(0);
}

BOOL CDlgChildBase::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_fnt_caption.CreateFont(15, 0, 0, 0, 0, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("휴먼옛체"));

	m_fnt_strategy_info.CreateFontA(15, 0, 0, 0, 0, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("휴먼옛체"));

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
