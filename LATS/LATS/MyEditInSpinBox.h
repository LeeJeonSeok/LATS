#pragma once

class CMyEditInSpinBox : public CEdit
{
public:
	CMyEditInSpinBox();
	virtual ~CMyEditInSpinBox();
private:
	COLORREF		m_crBkg;
	COLORREF		m_crOuterLine;
	COLORREF		m_crInnerLine;			
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

