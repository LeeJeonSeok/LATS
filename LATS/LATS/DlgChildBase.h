#pragma once
#include <afxdialogex.h>
#include <vector>
#include "MyComboBox.h"
#include "MyImageTextButton.h"
#include "MyGroupBox.h"
#include "MyEdit.h"
#include "MyEditInSpinBox.h"

class CLATSManager;
class CDlgChildBase :
    public CDialogEx
{
public:


public:
    CDlgChildBase(UINT ResourceID, CWnd* pParent);
    virtual ~CDlgChildBase();


    //Setter
    void SetLATSManagerAddress(CLATSManager* pManager);

protected:

    //LATS Manager Pointer
    CLATSManager* m_ptr_LATSManager;

    //Values
    bool m_bInit;

    //font
    CFont m_fnt_caption;
	CFont m_fnt_strategy_info;

protected:
	
    //ControlPosition
    virtual void SetChildAndControlPosition();
	
    //ControlPosition (전체 Rect 받아서 내가 쓸만큼 쓰고 남은 Rect 반환)
	CRect SetStaticAndEditPosition(CRect& rt, CWnd& Static, CString StaticText, CWnd& Edit, bool bUsingGroupBox);
	CRect SetRadioCheckAndStaticPosition_1P(CRect& rt, CWnd& Button, CWnd& Static, CString StaticText,  bool bUsingGroupBox, bool bRadio);
	CRect SetRadioCheckAndStaticPosition_2P(CRect& rt, CWnd& Button1, CWnd& Static1, CString Static1Text, CWnd& Button2, CWnd& Static2, CString Static2Text, bool bUsingGroupBox, bool bRadio);
	CRect SetButtonPositionAndText_1P(CRect& rt, CWnd& Button, CString ButtonText, bool bUsingGroupBox);
	CRect SetButtonPositionAndText_2P(CRect& rt, CWnd& Button1, CString Button1Text, CWnd& Button2, CString Button2Text, bool bUsingGroupBox);

public:
    DECLARE_MESSAGE_MAP()
    afx_msg void OnSize(UINT nType, int cx, int cy);
    virtual BOOL OnInitDialog();
};

