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
		
	// 활성 비활성 색상 값만 변경 해 줄 것
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
	
	
	// 윈도우 기본 해상도나 설정에 따라 콤보 크기가 달라지므로 스크롤 너비를 구해와서 보정
	int nButtonWidth = ::GetSystemMetrics(SM_CXVSCROLL);
	insideBtn.left = insideBtn.right - nButtonWidth - 1;
	//insideBtn.left = insideBtn.right - 18; // 하드코딩 위험	
	
	// 하얀 테두리
	pDC->Draw3dRect(&insideBtn, m_crInnerLine, m_crInnerLine);
	insideBtn.DeflateRect(1, 1);
	
	// 컨트롤 활성화 시
	if (IsWindowEnabled())
	{
		if (!m_bIsButtonClick)	//regular state - btn NOT pressed
		{
			m_nSpace = 0;
			// 그림자 테두리		
			pDC->Draw3dRect(&insideBtn, m_crBorderBtnBright, m_crBorderBtnDark);
			pDC->SetPixel(insideBtn.right - 1, insideBtn.top, m_crBorderBtnBright);

			insideBtn.DeflateRect(1, 1);
			CPoint leftPoint = insideBtn.TopLeft();
			CPoint rightPoint;
			rightPoint.x = insideBtn.right;
			rightPoint.y = insideBtn.top;

			// 테두리 색상에 따라 변경 해 줄 것 //
			int r = 84;
			int g = 84;
			int b = 89;
			double cnt = (double)insideBtn.Height();
			int interval = (int)(50.0 / cnt);
			// 테두리 색상에 따라 변경 해 줄 것 //

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

			// 그림자 테두리
			pDC->Draw3dRect(&insideBtn, m_crBorderBtnDark, m_crBorderBtnBright);
			pDC->SetPixel(insideBtn.right - 1, insideBtn.top, m_crBorderBtnDark);

			insideBtn.DeflateRect(1, 1);
			CPoint rightPoint = insideBtn.BottomRight();
			rightPoint.y -= 1;
			CPoint leftPoint;
			leftPoint.x = insideBtn.left;
			leftPoint.y = insideBtn.bottom - 1;

			// 테두리 색상에 따라 변경 해 줄 것 //
			int r = 84;
			int g = 84;
			int b = 89;
			double cnt = (double)insideBtn.Height();
			int interval = (int)(50.0 / cnt);
			// 테두리 색상에 따라 변경 해 줄 것 //

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
	// 컨트롤 비활성 시
	else
	{
		m_nSpace = 0;
		// 그림자 테두리		
		pDC->Draw3dRect(&insideBtn, m_crBorderBtnBright, m_crBorderBtnDark);
		pDC->SetPixel(insideBtn.right - 1, insideBtn.top, m_crBorderBtnBright);

		insideBtn.DeflateRect(1, 1);
		CPoint leftPoint = insideBtn.TopLeft();
		CPoint rightPoint;
		rightPoint.x = insideBtn.right;
		rightPoint.y = insideBtn.top;

		// 테두리 색상에 따라 변경 해 줄 것 //
		//int r = 84;
		//int g = 84;
		//int b = 89;
		double cnt = (double)insideBtn.Height();
		//int interval = (int)(50.0 / cnt);
		// 테두리 색상에 따라 변경 해 줄 것 //

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
	// 왼쪽 반 삼각형
	CPoint CenterPoint(insideBtn.CenterPoint());
	// 버튼 클릭 시 픽셀 씩 밀어서 그림
	CenterPoint.x += m_nSpace;
	CenterPoint.y += m_nSpace - 1; // 보정
	// 기준 위치 잡기
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
	// 오른쪽 반 삼각형
	CenterPoint = insideBtn.CenterPoint();
	// 버튼 클릭 시 픽셀 씩 밀어서 그림
	CenterPoint.x += m_nSpace;
	CenterPoint.y += m_nSpace - 1; // 보정
	// 기준 위치 잡기
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_bIsButtonClick = true;

	CComboBox::OnLButtonDown(nFlags, point);
}
