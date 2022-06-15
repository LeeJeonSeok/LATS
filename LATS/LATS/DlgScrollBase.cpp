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
	m_nSizeDlg[0] = 0; // ���� �ʱ�ȭ �ʿ�
	m_nSizeDlg[1] = 0; // ���� �ʱ�ȭ �ʿ�
}

CDlgScrollBase::~CDlgScrollBase()
{
}

bool CDlgScrollBase::IsScrollAvailable()
{
	if (SCROLL_ORIENTATION::NONE == m_scrollOrientation) return false;

	// ������ ���� ū ��츸 ��ũ�� ���� ����
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
	m_pBTN_SCROLL_CENTER->ShowWindow(SW_HIDE); // �ʱ� ����
	m_pBTN_SCROLL_UPPER->ShowWindow(SW_HIDE); // �ʱ� ����
	m_pBTN_SCROLL_LOWER->ShowWindow(SW_HIDE); // �ʱ� ����
	m_pBTN_SCROLL_CENTER->SetCenterScrollBar(this);
	m_bScrollVisible = bScrollVisible;
}

// test sr scroll
//void CDlgScrollBase::TestScroll(int nOff)
//{
//	if (m_nOffDlg[m_scrollOrientation] < nOff || (nOff + 300) < m_nOffDlg[m_scrollOrientation])
//	{
//		/// ��ũ�� �ӵ� ����
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

	// ��ũ�ѹ� ���� ��ų ��� ��ũ �ߵ�
	m_bRequireSync = true;
	
	// ƽ�� ��ũ�� �� ��ũ �ʿ�
	m_sDeltaPerTick = sDeltaPerTick;
}

void CDlgScrollBase::OnScrollDialog(short zDelta)
{
	// ������ ���� ū ��츸 ��ũ�� ����
	if (!IsScrollAvailable()) return;
		
	/// �������� ��ũ��
	///int interval = (zDelta > 0) ? 20 : -20;
	///m_nOffDlg[m_scrollOrientation] += interval;

	/// ��ũ�� �ӵ� ����
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
	// ��ũ���� ������ ���� ���� ���� �˻� 
	// OnSize �� ���� �׻� �˻�
	if (IsScrollAvailable() || bOnSizeOnFrame)
	{
		AdjustScrollDialogPosition();

		// ���� ��ũ�� ��ư ��ġ
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
	// �޴������� ȣ��/�۵�
	if (SCROLL_TYPE::MENU == m_scrollType)
	{
		if (bShow) m_pPairedScrollDialogToSync->ShowWindow(SW_SHOW);
		else m_pPairedScrollDialogToSync->ShowWindow(SW_HIDE);
	}
}

void CDlgScrollBase::AdjustScrollButtonPosition()
{
	if (m_bScrollVisible) // ��ũ�� ǥ���ϴ� ��츸
	{
		if (m_bScrollAvailable)
		{
			int indexWidth = 1 - m_scrollOrientation;
			int indexLength = m_scrollOrientation;

			int frameLength = GetFrameLength();
			double ratioLength = (double)frameLength / (double)m_nSizeDlg[indexLength];
			double ratioOffY = (-1.0 * (double)m_nOffDlg[indexLength]) / (double)m_nSizeDlg[indexLength];

			int lengthScroll = (int)(frameLength * ratioLength) + 1; // �Ҽ��� ����
			if (lengthScroll > frameLength)
				lengthScroll -= 1;
			int offYScroll = (int)(frameLength * ratioOffY);

			////////////////////////////////////////////// center //////////////////////////////////////////////
			int offCenter[2], sizeCenter[2];

			// ����
			sizeCenter[indexLength] = lengthScroll;
			// �� // �θ� �����ڿ��� ���� ���ִ�
			sizeCenter[indexWidth] = 10;


			offCenter[indexWidth] = m_nSizeDlg[indexWidth] - sizeCenter[indexWidth];
			// ���� ��ġ			
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

	// EndPos �� End ���� ���� �� ���� // ���� �˻��ؾ� �Ѵ�
	if (endPos < end)
	{
		int offSet = end - endPos;
		m_nOffDlg[m_scrollOrientation] += offSet;
	}
	// StartPos �� Start ���� Ŭ �� ����
	if (m_nOffDlg[m_scrollOrientation] > 0)
	{
		m_nOffDlg[m_scrollOrientation] = 0;
	}
}

BOOL CDlgScrollBase::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BEGIN_MESSAGE_MAP(CDlgScrollBase, CDialogEx)
	ON_WM_MOUSEWHEEL() // �޽��� �޴� ���̾�α׿� �߰� �� ��
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


BOOL CDlgScrollBase::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	return FALSE;
	return CDialogEx::OnEraseBkgnd(pDC);
}
