#include "stdafx.h"
#include "MyComboBox.h"
//#include "Enumerations.h"

CMyComboBox::CMyComboBox()
{
	m_crOuterLine = CONTROL_COMBO::COLOR_BORDER_OUTER;
	m_crInnerLine = CONTROL_COMBO::COLOR_BORDER_INNER;
	m_crBorderBtnBright = CONTROL_COMBO::COLOR_BORDER_BTN_BRIGHT;
	m_crBorderBtnDark = CONTROL_COMBO::COLOR_BORDER_BTN_DARK;
	m_crArrow = CONTROL_COMBO::COLOR_ARROW;

	m_nSpace = 0;

	m_bIsButtonClick = false;
}


CMyComboBox::~CMyComboBox()
{
}
BEGIN_MESSAGE_MAP(CMyComboBox, CComboBox)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CMyComboBox::OnPaint()
{
	Default();

	CDC* pDC = GetDC();

	CRect ClientRect;
	GetClientRect(&ClientRect);
		
	// Ȱ�� ��Ȱ�� ���� ���� ���� �� �� ��
	if (IsWindowEnabled())
	{
		m_crOuterLine = CONTROL_COMBO::COLOR_BORDER_OUTER;
		m_crInnerLine = CONTROL_COMBO::COLOR_BORDER_INNER;
		m_crBorderBtnBright = CONTROL_COMBO::COLOR_BORDER_BTN_BRIGHT;
		m_crBorderBtnDark = CONTROL_COMBO::COLOR_BORDER_BTN_DARK;
		m_crArrow = CONTROL_COMBO::COLOR_ARROW;		
	}
	else
	{
		m_crOuterLine = CONTROL_COMBO::COLOR_BORDER_OUTER_DIS;
		m_crInnerLine = CONTROL_COMBO::COLOR_BORDER_INNER_DIS;
		m_crBorderBtnBright = CONTROL_COMBO::COLOR_BORDER_BTN_DIS;
		m_crBorderBtnDark = CONTROL_COMBO::COLOR_BORDER_BTN_DIS;
		m_crArrow = CONTROL_COMBO::COLOR_ARROW_DIS;		
	}
	
	pDC->Draw3dRect(&ClientRect, m_crOuterLine, m_crOuterLine);
	ClientRect.DeflateRect(1, 1);
	pDC->Draw3dRect(&ClientRect, m_crInnerLine, m_crInnerLine);

	///////////////////////////////////////////////////
	// Draw the Button
	CRect insideBtn = ClientRect;
	
	
	// ������ �⺻ �ػ󵵳� ������ ���� �޺� ũ�Ⱑ �޶����Ƿ� ��ũ�� �ʺ� ���ؿͼ� ����
	int nButtonWidth = ::GetSystemMetrics(SM_CXVSCROLL);
	insideBtn.left = insideBtn.right - nButtonWidth - 1;
	//insideBtn.left = insideBtn.right - 18; // �ϵ��ڵ� ����	
	
	// �Ͼ� �׵θ�
	pDC->Draw3dRect(&insideBtn, m_crInnerLine, m_crInnerLine);
	insideBtn.DeflateRect(1, 1);
	
	// ��Ʈ�� Ȱ��ȭ ��
	if (IsWindowEnabled())
	{
		if (!m_bIsButtonClick)	//regular state - btn NOT pressed
		{
			m_nSpace = 0;
			// �׸��� �׵θ�		
			pDC->Draw3dRect(&insideBtn, m_crBorderBtnBright, m_crBorderBtnDark);
			pDC->SetPixel(insideBtn.right - 1, insideBtn.top, m_crBorderBtnBright);

			insideBtn.DeflateRect(1, 1);
			CPoint leftPoint = insideBtn.TopLeft();
			CPoint rightPoint;
			rightPoint.x = insideBtn.right;
			rightPoint.y = insideBtn.top;

			// �׵θ� ���� ���� ���� �� �� �� //
			int r = 84;
			int g = 84;
			int b = 89;
			double cnt = (double)insideBtn.Height();
			int interval = (int)(50.0 / cnt);
			// �׵θ� ���� ���� ���� �� �� �� //

			for (int i = 0; i < cnt; i++)
			{
				CPen inPen(PS_SOLID, 1, RGB(r, g, b));
				CPen* pInOldPen = pDC->SelectObject(&inPen);

				pDC->MoveTo(leftPoint);
				VERIFY(pDC->LineTo(rightPoint));
				++leftPoint.y;
				++rightPoint.y;
				r -= interval;
				g -= interval;
				b -= interval;
			}
		}
		else		//btn is pressed
		{
			m_nSpace = 1;
			m_bIsButtonClick = false;

			// �׸��� �׵θ�
			pDC->Draw3dRect(&insideBtn, m_crBorderBtnDark, m_crBorderBtnBright);
			pDC->SetPixel(insideBtn.right - 1, insideBtn.top, m_crBorderBtnDark);

			insideBtn.DeflateRect(1, 1);
			CPoint rightPoint = insideBtn.BottomRight();
			rightPoint.y -= 1;
			CPoint leftPoint;
			leftPoint.x = insideBtn.left;
			leftPoint.y = insideBtn.bottom - 1;

			// �׵θ� ���� ���� ���� �� �� �� //
			int r = 84;
			int g = 84;
			int b = 89;
			double cnt = (double)insideBtn.Height();
			int interval = (int)(50.0 / cnt);
			// �׵θ� ���� ���� ���� �� �� �� //

			for (int i = 0; i < cnt; i++)
			{
				CPen inPen(PS_SOLID, 1, RGB(r, g, b));
				CPen* pInOldPen = pDC->SelectObject(&inPen);

				pDC->MoveTo(leftPoint);
				VERIFY(pDC->LineTo(rightPoint));
				--leftPoint.y;
				--rightPoint.y;
				r -= interval;
				g -= interval;
				b -= interval;
			}
		}
	}
	// ��Ʈ�� ��Ȱ�� ��
	else
	{
		m_nSpace = 0;
		// �׸��� �׵θ�		
		pDC->Draw3dRect(&insideBtn, m_crBorderBtnBright, m_crBorderBtnDark);
		pDC->SetPixel(insideBtn.right - 1, insideBtn.top, m_crBorderBtnBright);

		insideBtn.DeflateRect(1, 1);
		CPoint leftPoint = insideBtn.TopLeft();
		CPoint rightPoint;
		rightPoint.x = insideBtn.right;
		rightPoint.y = insideBtn.top;

		// �׵θ� ���� ���� ���� �� �� �� //
		//int r = 84;
		//int g = 84;
		//int b = 89;
		double cnt = (double)insideBtn.Height();
		//int interval = (int)(50.0 / cnt);
		// �׵θ� ���� ���� ���� �� �� �� //

		for (int i = 0; i < cnt; i++)
		{
			//CPen inPen(PS_SOLID, 1, RGB(r, g, b));
			CPen inPen(PS_SOLID, 1, CONTROL_COMBO::COLOR_BKGROUND_DIS);
			CPen* pInOldPen = pDC->SelectObject(&inPen);

			pDC->MoveTo(leftPoint);
			VERIFY(pDC->LineTo(rightPoint));
			++leftPoint.y;
			++rightPoint.y;
			//r -= interval;
			//g -= interval;
			//b -= interval;
		}
	}
		
	insideBtn.InflateRect(1, 1);

	///////////////////////////////////////////////////
	// Draw the Arrow
	// ���� �� �ﰢ��
	CPoint CenterPoint(insideBtn.CenterPoint());
	// ��ư Ŭ�� �� �ȼ� �� �о �׸�
	CenterPoint.x += m_nSpace;
	CenterPoint.y += m_nSpace - 1; // ����
	// ���� ��ġ ���
	++CenterPoint.y;
	++CenterPoint.y;
	CPoint UpperPoint(CenterPoint.x, CenterPoint.y - 4);	
	CPen Pen(PS_SOLID, 1, m_crArrow);
	CPen* pOldPen = pDC->SelectObject(&Pen);
	for (int i = 0; i < 4; ++i)
	{
		pDC->MoveTo(CenterPoint);
		VERIFY(pDC->LineTo(UpperPoint));

		--CenterPoint.x;
		--CenterPoint.y;
		--UpperPoint.x;
	}
	// ������ �� �ﰢ��
	CenterPoint = insideBtn.CenterPoint();
	// ��ư Ŭ�� �� �ȼ� �� �о �׸�
	CenterPoint.x += m_nSpace;
	CenterPoint.y += m_nSpace - 1; // ����
	// ���� ��ġ ���
	++CenterPoint.y;
	++CenterPoint.y;
	UpperPoint = CenterPoint;
	UpperPoint.y -= 4;
	for (int i = 0; i < 4; ++i)
	{
		pDC->MoveTo(CenterPoint);
		VERIFY(pDC->LineTo(UpperPoint));
	
		++CenterPoint.x;
		--CenterPoint.y;
		++UpperPoint.x;
	}
	//until here - painting the arrow:
		
	ReleaseDC(pDC);
}


void CMyComboBox::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	m_bIsButtonClick = true;

	CComboBox::OnLButtonDown(nFlags, point);
}
