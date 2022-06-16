#include "stdafx.h"
#include "MyCaptionButton.h"

BEGIN_MESSAGE_MAP(CMyCaptionButton, CButton)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()


void CMyCaptionButton::InitButton()
{
	if (!m_bInit)
	{
		SetButtonStyle(BS_USERBUTTON);
		SetDefaltRGB();
		m_bInit = true;
		m_bHover = false;
	} 
}


void CMyCaptionButton::SetHoverRGB()
{
	if (m_bCloseButton)
	{
		m_nR = 255;
		m_nG = 0;
		m_nB = 0;
	}
	else
	{
		m_nR = 80;
		m_nG = 80;
		m_nB = 80;
	}
}

void CMyCaptionButton::SetDefaltRGB()
{
	m_nR = 50;
	m_nG = 50;
	m_nB = 50;
}

void CMyCaptionButton::SetHover()
{
	SetHoverRGB();
	m_bHover = true;
	Invalidate(0);
}

void CMyCaptionButton::SetLeave()
{
	SetDefaltRGB();
	m_bHover = false;
	Invalidate(0);
}

CMyCaptionButton::CMyCaptionButton()
{
	m_str_Text = "none";
	m_bInit = false;
	m_bCloseButton = false;
}

CMyCaptionButton::~CMyCaptionButton()
{
}

void CMyCaptionButton::SetButtonText(CString text)
{
	m_str_Text = text;
	Invalidate(0);
}

void CMyCaptionButton::SetCloseButton()
{
	m_bCloseButton = true;
}

void CMyCaptionButton::OnPaint()
{
	InitButton();

	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CButton::OnPaint()��(��) ȣ������ ���ʽÿ�.
	CRect rt;
	GetClientRect(rt);
	CBrush FillBrush(RGB(m_nR, m_nG, m_nB));
	CPen pen(PS_SOLID, 1, RGB(m_nR, m_nG, m_nB));
	dc.SelectObject(&FillBrush);
	dc.SelectObject(&pen);
	dc.Rectangle(rt);
	DeleteObject(pen);
	DeleteObject(FillBrush);
	dc.SetBkColor(RGB(m_nR, m_nG, m_nB));
	dc.SetTextColor(RGB(200, 200, 200));
	dc.DrawText(m_str_Text, &rt, DT_CENTER | DT_VCENTER | DT_SINGLELINE );

}


void CMyCaptionButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bHover == FALSE)
	{
		TRACKMOUSEEVENT tme;
		ZeroMemory(&tme, sizeof(TRACKMOUSEEVENT));
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bHover = _TrackMouseEvent(&tme);
	}
	CButton::OnMouseMove(nFlags, point);
}


void CMyCaptionButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	SetHover();
	CButton::OnMouseHover(nFlags, point);
}


void CMyCaptionButton::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	SetLeave();
	CButton::OnMouseLeave();
}


//BOOL CMyCaptionButton::PreTranslateMessage(MSG* pMsg)
//{
//	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
//
//	return CButton::PreTranslateMessage(pMsg);
//}
