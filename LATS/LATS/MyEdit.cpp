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
		m_crOuterLine = RGB(10, 10, 10);
		m_crInnerLine = RGB(45, 45, 45);
	}
	else
	{
		m_crOuterLine = RGB(10, 10, 10);
		m_crInnerLine = RGB(45, 45, 45);
	}

	// ��Ʈ�� Ȱ��ȭ ��
	ClientRect.InflateRect(2, 2);
	pDC->Draw3dRect(&ClientRect, m_crOuterLine, m_crOuterLine);
	ClientRect.DeflateRect(1, 1);
	pDC->Draw3dRect(&ClientRect, m_crInnerLine, m_crInnerLine);	
	
	ReleaseDC(pDC);
}
