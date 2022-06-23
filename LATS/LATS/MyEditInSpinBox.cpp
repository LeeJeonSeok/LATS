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
	
	// 활성 비활성 색상 값만 변경 해 줄 것
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
	// 버튼과 입력창 사이의 여백
	pDC->Draw3dRect(&ClientRect, m_crBkg, m_crBkg);

	// 버튼 감싸는 테두리
	CRect borderRt = ClientRect;
	borderRt.left = ClientRect.right;
	borderRt.right = borderRt.left + 19; // 버튼 너비 + 2픽셀 // m_nSpinButtonWidth = 17
	pDC->Draw3dRect(&borderRt, m_crInnerLine, m_crInnerLine);

	// 제일 바깥의 검정 테두리
	ClientRect.right = borderRt.right;
	pDC->Draw3dRect(&ClientRect, m_crInnerLine, m_crInnerLine);

	// 하나 안쪽의 하얀 테두리 
	ClientRect.InflateRect(1, 1);
	pDC->Draw3dRect(&ClientRect, m_crOuterLine, m_crOuterLine);

	ReleaseDC(pDC);
}
