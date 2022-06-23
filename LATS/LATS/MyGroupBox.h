#pragma once
class CMyGroupBox : public CStatic
{
public:
	CMyGroupBox();
	virtual ~CMyGroupBox();

public:
	enum BORDER_STYLE { flat = 0, etched };

protected:

	CFont*			m_pFont;					// font used for text
	COLORREF		m_crText;				// text color
	COLORREF		m_crBackground;			// background color
	COLORREF		m_crBorder;				// user-specified border color
	COLORREF		m_crEtchedBorder;		// user-specified border color

	int				m_nYOffset;				// y offset of frame (text extends 
											// above frame)
	
	CRect			m_rect;
	CSize			m_sizeText;				// size of text from GetTextExtent()

	BORDER_STYLE	m_eBorderStyle;			// border line style - flat or etched;
											// applies only if no border color
											// and no theme
	
protected:
	

public:
	void		DrawBorder(CDC *pDC, CRect& rect);
	void		DrawItem(CDC *pDC, CRect& rect);
	int			DrawText(CDC *pDC, CRect& rect);
	void		EraseBorder(CDC *pDC, CRect& rect, COLORREF crBackground);

	void		DrawEtchedRectangle(CDC *pDC, CRect& rect, COLORREF cr, COLORREF crE);
	void		DrawHeader(CDC *pDC, CRect& rectText);
	
	void		SetFont(CFont* pFont, BOOL bRedraw);
	void		SetTextColor(COLORREF cr); //, BOOL bRedraw = TRUE);
	void		SetBKColor(COLORREF crBk);
	void		SetBorderColor(COLORREF cr, COLORREF crE); // , BOOL bRedraw = TRUE);
	void		SetBorderStyle(BORDER_STYLE eStyle); // , BOOL bRedraw = TRUE);

	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

