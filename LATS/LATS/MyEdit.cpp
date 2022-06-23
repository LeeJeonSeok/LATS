#include "stdafx.h"
#include "MyEdit.h"
//#include "Enumerations.h"

CMyEdit::CMyEdit()
{	
}

CMyEdit::~CMyEdit()
{
}

BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyEdit::OnPaint()
{
	Default();

	CDC* pDC = GetDC();

	CRect ClientRect;
	GetClientRect(&ClientRect);

	// Ȱ�� ��Ȱ�� ���� ���� ���� �� �� ��
	if (IsWindowEnabled())
	{
		m_crOuterLine = CONTROL_EDIT::COLOR_BORDER_OUTER;
		m_crInnerLine = CONTROL_EDIT::COLOR_BORDER_INNER;
	}
	else
	{
		m_crOuterLine = CONTROL_EDIT::COLOR_BORDER_OUTER_DIS;
		m_crInnerLine = CONTROL_EDIT::COLOR_BORDER_INNER_DIS;
	}

	// ��Ʈ�� Ȱ��ȭ ��
	ClientRect.InflateRect(2, 2);
	pDC->Draw3dRect(&ClientRect, m_crOuterLine, m_crOuterLine);
	ClientRect.DeflateRect(1, 1);
	pDC->Draw3dRect(&ClientRect, m_crInnerLine, m_crInnerLine);	
	
	ReleaseDC(pDC);
}
