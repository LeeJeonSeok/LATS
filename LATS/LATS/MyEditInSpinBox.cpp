#include "stdafx.h"
#include "MyEditInSpinBox.h"


CMyEditInSpinBox::CMyEditInSpinBox()
{
	m_crBkg = CONTROL_EDIT::COLOR_BKGROUND;
	m_crOuterLine = CONTROL_EDIT::COLOR_BORDER_OUTER;
	m_crInnerLine = CONTROL_EDIT::COLOR_BORDER_INNER;
}

CMyEditInSpinBox::~CMyEditInSpinBox()
{
}

BEGIN_MESSAGE_MAP(CMyEditInSpinBox, CEdit)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyEditInSpinBox::OnPaint()
{
	Default();

	CDC* pDC = GetDC();

	CRect ClientRect;
	GetClientRect(&ClientRect);
	
	// Ȱ�� ��Ȱ�� ���� ���� ���� �� �� ��
	if (IsWindowEnabled())
	{
		m_crBkg = CONTROL_EDIT::COLOR_BKGROUND;
		m_crOuterLine = CONTROL_EDIT::COLOR_BORDER_OUTER;
		m_crInnerLine = CONTROL_EDIT::COLOR_BORDER_INNER;
	}
	else
	{
		m_crBkg = CONTROL_EDIT::COLOR_BKGROUND_DIS;
		m_crOuterLine = CONTROL_EDIT::COLOR_BORDER_OUTER_DIS;
		m_crInnerLine = CONTROL_EDIT::COLOR_BORDER_INNER_DIS;
	}

	ClientRect.InflateRect(1, 1);
	// ��ư�� �Է�â ������ ����
	pDC->Draw3dRect(&ClientRect, m_crBkg, m_crBkg);

	// ��ư ���δ� �׵θ�
	CRect borderRt = ClientRect;
	borderRt.left = ClientRect.right;
	borderRt.right = borderRt.left + 19; // ��ư �ʺ� + 2�ȼ� // m_nSpinButtonWidth = 17
	pDC->Draw3dRect(&borderRt, m_crInnerLine, m_crInnerLine);

	// ���� �ٱ��� ���� �׵θ�
	ClientRect.right = borderRt.right;
	pDC->Draw3dRect(&ClientRect, m_crInnerLine, m_crInnerLine);

	// �ϳ� ������ �Ͼ� �׵θ� 
	ClientRect.InflateRect(1, 1);
	pDC->Draw3dRect(&ClientRect, m_crOuterLine, m_crOuterLine);

	ReleaseDC(pDC);
}
