#pragma once
#include "DlgChildBase.h"
#include "MyImageScrollBar.h"
//#include <vector>


// Frame �ȿ��� ��ũ�� �ϴ� ���� Dlg ���̽� Ŭ����
// Top, Left, Right, Toolbar ���� ���


// ���ο� ��ũ���� ���� �� ���� ���� ������ ����� �� �Ǿ� ����
// �ʿ��ϸ� ����鼭 ������ ��


// �޴��� ��ũ���� �и��Ͽ� Ÿ�� �����Ͽ� ���
namespace SCROLL_TYPE
{
	enum ENUM
	{
		MENU = 0,
		SCROLLBAR,
	};
	// ON3D 2 ���� �ÿ��� Base �� �θ�� Menu �� Scroll Ŭ���� ���� ����ؼ� ���� ��
	// �׸��� �� ������ ���� ���¼� ���� Ŭ���� �и��� �� �Ǿ��ִ� ��Ȳ
}

namespace SCROLL_ORIENTATION
{
	enum ENUM
	{
		NONE = -1,
		HORIZONTAL, VERTICAL,
	};
}


class CDlgScrollBase : public CDlgChildBase
{
public:
	CDlgScrollBase(UINT nIDTemplate, CWnd* pParent = NULL);
	virtual ~CDlgScrollBase();


protected:

	bool m_bInit;
	SCROLL_TYPE::ENUM m_scrollType;
	SCROLL_ORIENTATION::ENUM m_scrollOrientation;

	bool m_bRequireSync;
	CDlgScrollBase* m_pPairedScrollDialogToSync;

	// ��ũ�� ������ �������� // ������ ������� ���� ��
	bool m_bScrollAvailable;

	// ��ũ�� �� ǥ�� ���� // false �⺻
	// SetScrollButtonPointer ���� ��ư ȣ��� ����
	bool m_bScrollVisible;

	// ���̴� ���� ��Ұ� �ٲ� ��
	// ��ġ�� ��ũ�� �� �� ����
	int m_nOffDlg[2];
	int m_nSizeDlg[2];


	// ƽ�� ��ũ�� // �⺻ 120
	// Dialog ���� �޸� �ϰ� ���� �� ����
	// pair �� �����̸� SetPairedScrollDialogToSync ���� ���� ��������� �Ѵ�
	short m_sDeltaPerTick;

	


	//////////////////////////// ��ũ�� �� ���� ////////////////////////////

	// �����Ǵ� ��ũ�� ��
	CMyImageScrollBar* m_pBTN_SCROLL_CENTER;
	CMyImageScrollBar* m_pBTN_SCROLL_UPPER;
	CMyImageScrollBar* m_pBTN_SCROLL_LOWER;
	

	//////////////////////////// ��ũ�� �� ���� ////////////////////////////


protected:
	
	// Frame ������� ���Ͽ� ���� ��쿡 ��ũ���� �ʿ����� �˻�
	bool IsScrollAvailable();
	int GetFrameLength();


	// ��ũ�� ��ư ������ ���� �� ��ũ�� ǥ�� ���� ����
	void SetScrollButtonPointer(CMyImageScrollBar* pCenter, CMyImageScrollBar* pUpper, CMyImageScrollBar* pLower, bool bScrollVisible);


	// test sr scroll
	////////////////// ConfigSimple ���� ////////////////
	//void TestScroll(int nOff);
	//void TestScroll22222(int rowIndex);
	////////////////// ConfigSimple ���� ////////////////

public:
	// Menu // ScrollBar Ÿ�� ���� // ���⵵ ����
	void SetScrollDialogType(SCROLL_TYPE::ENUM type, SCROLL_ORIENTATION::ENUM orientation);

	void SetPairedScrollDialogToSync(CDlgScrollBase* pPair, short sDeltaPerTick = 60);

	//void GetScrollDialogSize(CRect& rect);

	// ��ũ�� ����
	void OnScrollDialog(short zDelta); // zDelta �� �޾ƾ� ��ũ�Ѽӵ� ���� ����

	// ��ũ�� ���� // ��ũ�� ��ư �巡�� �� �̺�Ʈ
	void OnDragScrollDialog(short offSet);


	// Theme ���� �� (UI_STATE ����) ��ũ�� ����
	void ResetScrollDialogPositionToTop();



	// ���������� ũ�� �� ��ġ ����
	void AdjustScrollButtonPosition();
	void AdjustScrollDialogPosition();
	void MoveWindowScrollDialog(bool bOnSizeOnFrame = false);
	
	// ��ũ�� ���� ����
	void SetSyncedScrollDialogLength(int nHeight);

	// ��ũ�� Dlg ����
	void ShowHideScrollButtonDialog(bool bShow);

	
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

