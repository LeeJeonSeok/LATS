#pragma once
#include "afxwin.h"

// 부모
class CDlgScrollBase;

class CMyImageScrollBar : public CButton
{
public:
	CMyImageScrollBar();
	virtual ~CMyImageScrollBar();


private:
	bool m_bCenter;

	bool m_bHover;

	COLORREF m_colSide;
	COLORREF m_colCenter;	


	COLORREF m_colCenterOuter;
	COLORREF m_colCenterOuterHover;

	COLORREF m_colCenterInner;
	COLORREF m_colCenterInnerHover;


	// 본인 위치
	int m_nPos[4];


	// 마우스 이전 이동 위치
	CPoint m_ptMouseMovePrev;

	// 마우스 클릭상태
	bool m_bMouseClicked;



	// 부모 포인터
	CDlgScrollBase* m_pParentDlg;


private:


public:

	void SetCenterScrollBar(CDlgScrollBase* pParent);

	void MoveScrollBarButton(int offX, int offY, int width, int height);
	


	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);


	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);


	afx_msg void OnMouseHover(UINT nFlags, CPoint point);

	afx_msg void OnMouseLeave();
};

