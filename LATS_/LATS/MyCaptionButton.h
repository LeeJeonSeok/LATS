#pragma once
#include <afxwin.h>

class CMyCaptionButton :    public CButton
{
protected:

protected:

private:
    //버튼 텍스트 저장
    CString m_str_Text;

    //초기화 했는지 검사
    bool m_bInit;

    //호버상태 검사
    bool m_bHover;

    //RGB값 저장
    int m_nR;
    int m_nG;
    int m_nB;
	
	//close 버튼인지 확인
	bool m_bCloseButton;

private:

    //초기화
    void InitButton();

    //RGB설정
    void SetHoverRGB();
    void SetDefaltRGB();

    //Hover상태 설정
    void SetHover();

    //Leave상태 설정
    void SetLeave();

public:

public:

    //생성자, 소멸자
    CMyCaptionButton();
    ~CMyCaptionButton();

    //버튼 텍스트 설정
    void SetButtonText(CString text);

	//CloseButton 지정
	void SetCloseButton();
    
    DECLARE_MESSAGE_MAP()
    afx_msg void OnPaint();
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnMouseHover(UINT nFlags, CPoint point);
    afx_msg void OnMouseLeave();
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

