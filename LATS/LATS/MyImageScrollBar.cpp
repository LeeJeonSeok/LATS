#include "stdafx.h"
#include "MyImageScrollBar.h"

#include "DlgScrollBase.h"

CMyImageScrollBar::CMyImageScrollBar()
{
	m_bCenter = false;
	m_bHover = false;

	//m_colSide = UI_CONFIG::COL_TEXT_DEFAULT;
	m_colSide = RGB(130, 10, 200);
	m_colCenter = RGB(255, 201, 14);
	
	// �⺻
	m_colCenterOuter = RGB(100, 100, 100);
	m_colCenterOuterHover = RGB(153, 153, 153);

	m_colCenterInner = RGB(125, 125, 125);
	m_colCenterInnerHover = RGB(194, 194, 201);

	m_nPos[0] = 0;
	m_nPos[1] = 0;
	m_nPos[2] = 0;
	m_nPos[3] = 0;

	m_ptMouseMovePrev.x = 0;
	m_ptMouseMovePrev.y = 0;

	m_bMouseClicked = false;
}


CMyImageScrollBar::~CMyImageScrollBar()
{
}

void CMyImageScrollBar::SetCenterScrollBar(CDlgScrollBase* pParent)
{
	m_pParentDlg = pParent;
	m_bCenter = true;
}

void CMyImageScrollBar::MoveScrollBarButton(int offX, int offY, int width, int height)
{
	m_nPos[0] = offX;
	m_nPos[1] = offY;
	m_nPos[2] = width;
	m_nPos[3] = height;

	MoveWindow(m_nPos[0], m_nPos[1], m_nPos[2], m_nPos[3]);
}

void CMyImageScrollBar::DrawItem(LPDRAWITEMSTRUCT)
{
	CDC* pDC = GetDC();

	CRect rt;
	GetClientRect(&rt);

	if (m_bCenter)
	{
		if (m_bHover)
		{
			// �׵θ�
			pDC->Draw3dRect(&rt, m_colCenterOuterHover, m_colCenterOuterHover);
			rt.DeflateRect(1, 1);
			// ä���
			pDC->FillSolidRect(rt, m_colCenterInnerHover);
		}
		else
		{
			// �׵θ�
			pDC->Draw3dRect(&rt, m_colCenterOuter, m_colCenterOuter);
			rt.DeflateRect(1, 1);
			// ä���
			pDC->FillSolidRect(rt, m_colCenterInner);
		}		
	}
	else
	{
		pDC->FillSolidRect(rt, m_colSide);
	}

	ReleaseDC(pDC);
}
BEGIN_MESSAGE_MAP(CMyImageScrollBar, CButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()


void CMyImageScrollBar::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	if (m_bCenter)
	{
		m_bMouseClicked = true;

		// ������ �������� ��ǥ ����Ͽ� ó��
		POINT ptPos;
		GetCursorPos(&ptPos);

		m_ptMouseMovePrev = ptPos;
	}

	CButton::OnLButtonDown(nFlags, point);
}


void CMyImageScrollBar::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	if (m_bCenter)
	{
		if (m_bMouseClicked)
		{
			SetCapture();

			// ������ �������� ��ǥ ����Ͽ� ó��
			// ���콺 �巡�� �����̸� ���� ��ǥ���� offSet��ŭ �̵���Ŵ
			POINT ptPos;
			GetCursorPos(&ptPos);

			// 
			CPoint offSet;
			offSet.x = ptPos.x - m_ptMouseMovePrev.x;
			offSet.y = ptPos.y - m_ptMouseMovePrev.y;
			
			m_ptMouseMovePrev = ptPos;
			offSet.y *= -1;
			m_pParentDlg->OnDragScrollDialog((short)(offSet.y));
			
			//if (0 != offSet.y)
			//{
			//	m_ptMouseMovePrev = ptPos;
			//
			//
			//	//// ��ũ�ѹ� ��ġ
			//	//m_nPos[1] += offSet.y;
			//	//
			//	//short sOffSet = 60;
			//	//if (offSet.y > 0) sOffSet *= -1;
			//	//
			//	//// ������ ��ũ�ѹ� ��ġ���� ������ �޴� ��ġ ���ϱ�
			//	//m_pParentDlg->OnDragScrollDialog(sOffSet);
			//
			//	
			//
			//	
			//	// ��ũ�ѹ� ��ġ
			//	//m_nPos[1] += offSet.y;
			//	offSet.y *= -1;
			//	// ������ ��ũ�ѹ� ��ġ���� ������ �޴� ��ġ ���ϱ�
			//	m_pParentDlg->OnDragScrollDialog(offSet.y);
			//	
			//
			//
			//
			//
			//	//short sOffSet = -1 * offSet.y;
			//	//
			//	//// ��ũ�ѹ� ���� ��ġ
			//}
			//else
			//{
			//	int a = 0;
			//}

			// �޴� ��ũ

		}
	}

	TRACKMOUSEEVENT trackmouseevent;
	trackmouseevent.cbSize = sizeof(trackmouseevent);
	// ���� �÷��� : TME_CANCEL, TME_HOVER,
	//                 TME_LEAVE, TME_NONCLIENT, TME_QUERY
	trackmouseevent.dwFlags = TME_HOVER | TME_LEAVE;
	trackmouseevent.hwndTrack = GetSafeHwnd();
	// Hover Timeout ���� TME_HOVER �÷��� ����� �ݿ��ȴ�.
	// �ð��� �������� ������ ����.
	trackmouseevent.dwHoverTime = 0x00000001;
	_TrackMouseEvent(&trackmouseevent);


	CButton::OnMouseMove(nFlags, point);
}


void CMyImageScrollBar::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	if (m_bCenter)
	{
		if (m_bMouseClicked)
		{
			ReleaseCapture();
			m_bMouseClicked = false;
		}
	}

	CButton::OnLButtonUp(nFlags, point);
}


void CMyImageScrollBar::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	m_bHover = true;
	RedrawWindow();

	CButton::OnMouseHover(nFlags, point);
}


void CMyImageScrollBar::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	m_bHover = false;
	RedrawWindow();

	CButton::OnMouseLeave();
}
