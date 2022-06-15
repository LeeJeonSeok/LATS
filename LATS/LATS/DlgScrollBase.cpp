#include "stdafx.h"
#include "DlgScrollBase.h"


CDlgScrollBase::CDlgScrollBase(UINT nIDTemplate, CWnd* pParent)
{
	m_bInit = false;
	m_bRequireSync = false;
	m_scrollType = SCROLL_TYPE::MENU;
	m_scrollOrientation = SCROLL_ORIENTATION::NONE;
	m_bScrollAvailable = false;
	m_bScrollVisible = false;

	m_sDeltaPerTick = 60;
	
	m_pBTN_SCROLL_CENTER = nullptr;
	m_pBTN_SCROLL_UPPER = nullptr;
	m_pBTN_SCROLL_LOWER = nullptr;
	
	m_nOffDlg[0] = 0;
	m_nOffDlg[1] = 0;
	m_nSizeDlg[0] = 0; // 각각 초기화 필요
	m_nSizeDlg[1] = 0; // 각각 초기화 필요
}

CDlgScrollBase::~CDlgScrollBase()
{
}

bool CDlgScrollBase::IsScrollAvailable()
{
	if (SCROLL_ORIENTATION::NONE == m_scrollOrientation) return false;

	// 프레임 보다 큰 경우만 스크롤 수행 가능
	int totalLength = GetFrameLength();
	if (-1 == totalLength) return false;

	if (totalLength >= m_nSizeDlg[m_scrollOrientation])
	{
		m_bScrollAvailable = false;
	}
	else
	{
		m_bScrollAvailable = true;
	}

	return m_bScrollAvailable;
}

int CDlgScrollBase::GetFrameLength()
{
	// Frame
	RECT rtFrame;
	GetParent()->GetClientRect(&rtFrame);
	int totalLength = -1;

	if (SCROLL_ORIENTATION::HORIZONTAL == m_scrollOrientation)
		totalLength = rtFrame.right - rtFrame.left;
	else if (SCROLL_ORIENTATION::VERTICAL == m_scrollOrientation)
		totalLength = rtFrame.bottom - rtFrame.top;

	return totalLength;
}

void CDlgScrollBase::SetScrollButtonPointer(CMyImageScrollBar * pCenter, CMyImageScrollBar * pUpper, CMyImageScrollBar * pLower, bool bScrollVisible)
{
	m_pBTN_SCROLL_CENTER = pCenter;
	m_pBTN_SCROLL_UPPER = pUpper;
	m_pBTN_SCROLL_LOWER = pLower;
	m_pBTN_SCROLL_CENTER->ShowWindow(SW_HIDE); // 초기 숨김
	m_pBTN_SCROLL_UPPER->ShowWindow(SW_HIDE); // 초기 숨김
	m_pBTN_SCROLL_LOWER->ShowWindow(SW_HIDE); // 초기 숨김
	m_pBTN_SCROLL_CENTER->SetCenterScrollBar(this);
	m_bScrollVisible = bScrollVisible;
}

// test sr scroll
//void CDlgScrollBase::TestScroll(int nOff)
//{
//	if (m_nOffDlg[m_scrollOrientation] < nOff || (nOff + 300) < m_nOffDlg[m_scrollOrientation])
//	{
//		/// 스크롤 속도 반응
//		m_nOffDlg[m_scrollOrientation] = nOff;
//
//		MoveWindowScrollDialog();
//	}
//
//
//	
//}
//
//void CDlgScrollBase::TestScroll22222(int rowIndex)
//{
//	int nOff = rowIndex * -100;
//
//
//
//	TestScroll(nOff);
//	m_pPairedScrollDialogToSync->TestScroll(nOff);
//}

void CDlgScrollBase::SetScrollDialogType(SCROLL_TYPE::ENUM type, SCROLL_ORIENTATION::ENUM orientation)
{
	m_scrollType = type;
	m_scrollOrientation = orientation;
}

void CDlgScrollBase::SetPairedScrollDialogToSync(CDlgScrollBase * pPair, short sDeltaPerTick)
{
	m_pPairedScrollDialogToSync = pPair;

	// 스크롤바 연결 시킬 경우 싱크 발동
	m_bRequireSync = true;
	
	// 틱당 스크롤 도 싱크 필요
	m_sDeltaPerTick = sDeltaPerTick;
}

void CDlgScrollBase::OnScrollDialog(short zDelta)
{
	// 프레임 보다 큰 경우만 스크롤 수행
	if (!IsScrollAvailable()) return;
		
	/// 정량으로 스크롤
	///int interval = (zDelta > 0) ? 20 : -20;
	///m_nOffDlg[m_scrollOrientation] += interval;

	/// 스크롤 속도 반응
	m_nOffDlg[m_scrollOrientation] += (zDelta * m_sDeltaPerTick / 120 );

	MoveWindowScrollDialog();
}

void CDlgScrollBase::OnDragScrollDialog(short offSet)
{
	int frameLength = GetFrameLength();

	//short zDelta = (short)((double)offSet * (double)m_nSizeDlg[m_scrollOrientation] / (double)frameLength);
	//zDelta *= 120 / m_sDeltaPerTick;
	double dDelta = (double)offSet * (double)m_nSizeDlg[m_scrollOrientation] / (double)frameLength;
	dDelta *= (double)120 / (double)m_sDeltaPerTick;
	short zDelta = (short)dDelta;

	OnScrollDialog(zDelta);
	if (m_bRequireSync)
	{
		m_pPairedScrollDialogToSync->SetSyncedScrollDialogLength(m_nSizeDlg[m_scrollOrientation]);
		m_pPairedScrollDialogToSync->OnScrollDialog(zDelta);
	}	
}

void CDlgScrollBase::ResetScrollDialogPositionToTop()
{
}

void CDlgScrollBase::MoveWindowScrollDialog(bool bOnSizeOnFrame)
{
	// 스크롤이 가능할 때만 영역 제한 검사 
	// OnSize 일 때는 항상 검사
	if (IsScrollAvailable() || bOnSizeOnFrame)
	{
		AdjustScrollDialogPosition();

		// 내부 스크롤 버튼 배치
		if (SCROLL_TYPE::SCROLLBAR == m_scrollType)
			AdjustScrollButtonPosition();
	}
	
	MoveWindow(m_nOffDlg[0], m_nOffDlg[1], m_nSizeDlg[0], m_nSizeDlg[1]);
}

void CDlgScrollBase::SetSyncedScrollDialogLength(int nHeight)
{
	m_nSizeDlg[m_scrollOrientation] = nHeight;
}

void CDlgScrollBase::ShowHideScrollButtonDialog(bool bShow)
{
	// 메뉴에서만 호출/작동
	if (SCROLL_TYPE::MENU == m_scrollType)
	{
		if (bShow) m_pPairedScrollDialogToSync->ShowWindow(SW_SHOW);
		else m_pPairedScrollDialogToSync->ShowWindow(SW_HIDE);
	}
}

void CDlgScrollBase::AdjustScrollButtonPosition()
{
	if (m_bScrollVisible) // 스크롤 표시하는 경우만
	{
		if (m_bScrollAvailable)
		{
			int indexWidth = 1 - m_scrollOrientation;
			int indexLength = m_scrollOrientation;

			int frameLength = GetFrameLength();
			double ratioLength = (double)frameLength / (double)m_nSizeDlg[indexLength];
			double ratioOffY = (-1.0 * (double)m_nOffDlg[indexLength]) / (double)m_nSizeDlg[indexLength];

			int lengthScroll = (int)(frameLength * ratioLength) + 1; // 소수점 보정
			if (lengthScroll > frameLength)
				lengthScroll -= 1;
			int offYScroll = (int)(frameLength * ratioOffY);

			////////////////////////////////////////////// center //////////////////////////////////////////////
			int offCenter[2], sizeCenter[2];

			// 길이
			sizeCenter[indexLength] = lengthScroll;
			// 폭 // 부모 생성자에서 결정 돼있다
			sizeCenter[indexWidth] = 10;


			offCenter[indexWidth] = m_nSizeDlg[indexWidth] - sizeCenter[indexWidth];
			// 시작 위치			
			////offCenter[indexLength] = m_nSizeDlg[indexLength] - sizeCenter[indexLength];
			if (0 > m_nOffDlg[indexLength])
				offCenter[indexLength] = (-1 * m_nOffDlg[indexLength]) + offYScroll;
			else
				offCenter[indexLength] = offYScroll;
			////////////////////////////////////////////// center //////////////////////////////////////////////
			
			// upper
			int offUpper[2], sizeUpper[2];

			offUpper[indexWidth] = offCenter[indexWidth];
			offUpper[indexLength] = 0;
			sizeUpper[indexWidth] = sizeCenter[indexWidth];
			sizeUpper[indexLength] = offCenter[indexLength];


			// lower
			int offLower[2], sizeLower[2];

			offLower[indexWidth] = offCenter[indexWidth];
			offLower[indexLength] = offCenter[indexLength] + sizeCenter[indexLength];
			sizeLower[indexWidth] = sizeCenter[indexWidth];
			sizeLower[indexLength] = m_nSizeDlg[indexLength] - offLower[indexLength];
			

			if (nullptr != m_pBTN_SCROLL_CENTER && nullptr != m_pBTN_SCROLL_UPPER && nullptr != m_pBTN_SCROLL_LOWER)
			{
				//m_pBTN_SCROLL_CENTER->MoveWindow(offCenter[0] + 2, offCenter[1] + 2, sizeCenter[0] - 4, sizeCenter[1] - 4);
				//m_pBTN_SCROLL_UPPER->MoveWindow(offUpper[0] + 2, offUpper[1] + 2, sizeUpper[0] - 4, sizeUpper[1] - 4);
				//m_pBTN_SCROLL_LOWER->MoveWindow(offLower[0] + 2, offLower[1] + 2, sizeLower[0] - 4, sizeLower[1] - 4);
				m_pBTN_SCROLL_CENTER->MoveScrollBarButton(offCenter[0] + 3, offCenter[1] + 2, sizeCenter[0] - 3, sizeCenter[1] - 4);
				//m_pBTN_SCROLL_UPPER->MoveScrollBarButton(offUpper[0] + 2, offUpper[1] + 2, sizeUpper[0] - 4, sizeUpper[1] - 4);
				//m_pBTN_SCROLL_LOWER->MoveScrollBarButton(offLower[0] + 2, offLower[1] + 2, sizeLower[0] - 4, sizeLower[1] - 4);

				m_pBTN_SCROLL_CENTER->ShowWindow(SW_SHOW);
				//m_pBTN_SCROLL_UPPER->ShowWindow(SW_SHOW);
				//m_pBTN_SCROLL_LOWER->ShowWindow(SW_SHOW);
			}
		}
		else
		{
			if (nullptr != m_pBTN_SCROLL_CENTER && nullptr != m_pBTN_SCROLL_UPPER && nullptr != m_pBTN_SCROLL_LOWER)
			{
				m_pBTN_SCROLL_CENTER->ShowWindow(SW_HIDE);
				//m_pBTN_SCROLL_UPPER->ShowWindow(SW_HIDE);
				//m_pBTN_SCROLL_LOWER->ShowWindow(SW_HIDE);
			}
		}
	}
}

void CDlgScrollBase::AdjustScrollDialogPosition()
{
	int end = GetFrameLength();

	//int* startPos = &m_nOffDlg[m_scrollOrientation];
	int endPos = m_nSizeDlg[m_scrollOrientation] + m_nOffDlg[m_scrollOrientation];

	// EndPos 는 End 보다 작을 수 없다 // 먼저 검사해야 한다
	if (endPos < end)
	{
		int offSet = end - endPos;
		m_nOffDlg[m_scrollOrientation] += offSet;
	}
	// StartPos 는 Start 보다 클 수 없다
	if (m_nOffDlg[m_scrollOrientation] > 0)
	{
		m_nOffDlg[m_scrollOrientation] = 0;
	}
}

BOOL CDlgScrollBase::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BEGIN_MESSAGE_MAP(CDlgScrollBase, CDialogEx)
	ON_WM_MOUSEWHEEL() // 메시지 받는 다이얼로그에 추가 할 것
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


BOOL CDlgScrollBase::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	BOOL BRes = CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
	
	OnScrollDialog(zDelta);
	if (m_bRequireSync)
	{
		m_pPairedScrollDialogToSync->SetSyncedScrollDialogLength(m_nSizeDlg[m_scrollOrientation]);
		m_pPairedScrollDialogToSync->OnScrollDialog(zDelta);
	}
	
	return BRes;
}


BOOL CDlgScrollBase::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return FALSE;
	return CDialogEx::OnEraseBkgnd(pDC);
}
