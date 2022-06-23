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

	// 활성 비활성 색상 값만 변경 해 줄 것
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

	// 컨트롤 활성화 시
	ClientRect.InflateRect(2, 2);
	pDC->Draw3dRect(&ClientRect, m_crOuterLine, m_crOuterLine);
	ClientRect.DeflateRect(1, 1);
	pDC->Draw3dRect(&ClientRect, m_crInnerLine, m_crInnerLine);	
	
	ReleaseDC(pDC);
}
