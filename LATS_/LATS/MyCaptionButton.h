#pragma once
#include <afxwin.h>

class CMyCaptionButton :    public CButton
{
protected:

protected:

private:
    //��ư �ؽ�Ʈ ����
    CString m_str_Text;

    //�ʱ�ȭ �ߴ��� �˻�
    bool m_bInit;

    //ȣ������ �˻�
    bool m_bHover;

    //RGB�� ����
    int m_nR;
    int m_nG;
    int m_nB;
	
	//close ��ư���� Ȯ��
	bool m_bCloseButton;

private:

    //�ʱ�ȭ
    void InitButton();

    //RGB����
    void SetHoverRGB();
    void SetDefaltRGB();

    //Hover���� ����
    void SetHover();

    //Leave���� ����
    void SetLeave();

public:

public:

    //������, �Ҹ���
    CMyCaptionButton();
    ~CMyCaptionButton();

    //��ư �ؽ�Ʈ ����
    void SetButtonText(CString text);

	//CloseButton ����
	void SetCloseButton();
    
    DECLARE_MESSAGE_MAP()
    afx_msg void OnPaint();
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnMouseHover(UINT nFlags, CPoint point);
    afx_msg void OnMouseLeave();
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

