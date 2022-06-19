#pragma once

class CMyEdit : public CEdit
{
public:
	CMyEdit();
	virtual ~CMyEdit();
private:
	COLORREF		m_crOuterLine;
	COLORREF		m_crInnerLine;
	
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

