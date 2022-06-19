#pragma once


class CMyComboBox : public CComboBox
{
public:
	CMyComboBox();
	virtual ~CMyComboBox();

private:
	COLORREF		m_crOuterLine;
	COLORREF		m_crInnerLine;

	COLORREF		m_crBorderBtnBright;
	COLORREF		m_crBorderBtnDark;

	COLORREF		m_crArrow;

	// 버튼 클릭시 화살표 한줄씩 밀어서 그리기 위해 
	int				m_nSpace;
		
	bool			m_bIsButtonClick;
	
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

