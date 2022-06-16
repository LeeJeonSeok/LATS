#pragma once
#include "DlgChildBase.h"
#include "MyImageScrollBar.h"
//#include <vector>


// Frame 안에서 스크롤 하는 바탕 Dlg 베이스 클래스
// Top, Left, Right, Toolbar 현재 사용


// 가로용 스크롤은 실제 쓴 적이 없어 사이즈 고려가 안 되어 있음
// 필요하면 만들면서 적용할 것


// 메뉴와 스크롤을 분리하여 타입 지정하여 사용
namespace SCROLL_TYPE
{
	enum ENUM
	{
		MENU = 0,
		SCROLLBAR,
	};
	// ON3D 2 만들 시에는 Base 를 부모로 Menu 와 Scroll 클래스 따로 상속해서 만들 것
	// 그림이 다 나오지 않은 상태서 만들어서 클래스 분리가 안 되어있는 상황
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

	// 스크롤 가능한 상태인지 // 사이즈 계산으로 변경 됨
	bool m_bScrollAvailable;

	// 스크롤 바 표시 유무 // false 기본
	// SetScrollButtonPointer 에서 버튼 호출시 설정
	bool m_bScrollVisible;

	// 높이는 구성 요소가 바뀔 때
	// 위치는 스크롤 할 때 갱신
	int m_nOffDlg[2];
	int m_nSizeDlg[2];


	// 틱당 스크롤 // 기본 120
	// Dialog 별로 달리 하고 싶을 때 설정
	// pair 로 움직이면 SetPairedScrollDialogToSync 에서 같게 설정해줘야 한다
	short m_sDeltaPerTick;

	


	//////////////////////////// 스크롤 바 전용 ////////////////////////////

	// 연동되는 스크롤 바
	CMyImageScrollBar* m_pBTN_SCROLL_CENTER;
	CMyImageScrollBar* m_pBTN_SCROLL_UPPER;
	CMyImageScrollBar* m_pBTN_SCROLL_LOWER;
	

	//////////////////////////// 스크롤 바 전용 ////////////////////////////


protected:
	
	// Frame 사이즈와 비교하여 작을 경우에 스크롤이 필요한지 검사
	bool IsScrollAvailable();
	int GetFrameLength();


	// 스크롤 버튼 포인터 설정 및 스크롤 표시 유무 지정
	void SetScrollButtonPointer(CMyImageScrollBar* pCenter, CMyImageScrollBar* pUpper, CMyImageScrollBar* pLower, bool bScrollVisible);


	// test sr scroll
	////////////////// ConfigSimple 전용 ////////////////
	//void TestScroll(int nOff);
	//void TestScroll22222(int rowIndex);
	////////////////// ConfigSimple 전용 ////////////////

public:
	// Menu // ScrollBar 타입 설정 // 방향도 설정
	void SetScrollDialogType(SCROLL_TYPE::ENUM type, SCROLL_ORIENTATION::ENUM orientation);

	void SetPairedScrollDialogToSync(CDlgScrollBase* pPair, short sDeltaPerTick = 60);

	//void GetScrollDialogSize(CRect& rect);

	// 스크롤 수행
	void OnScrollDialog(short zDelta); // zDelta 를 받아야 스크롤속도 반응 가능

	// 스크롤 수행 // 스크롤 버튼 드래그 시 이벤트
	void OnDragScrollDialog(short offSet);


	// Theme 변경 시 (UI_STATE 말고) 스크롤 리셋
	void ResetScrollDialogPositionToTop();



	// 멤버변수대로 크기 및 위치 수정
	void AdjustScrollButtonPosition();
	void AdjustScrollDialogPosition();
	void MoveWindowScrollDialog(bool bOnSizeOnFrame = false);
	
	// 싱크할 높이 설정
	void SetSyncedScrollDialogLength(int nHeight);

	// 스크롤 Dlg 숨김
	void ShowHideScrollButtonDialog(bool bShow);

	
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

