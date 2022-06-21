#pragma once
#include <afxdialogex.h>
#include <vector>

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
	

public:
    DECLARE_MESSAGE_MAP()
    afx_msg void OnSize(UINT nType, int cx, int cy);
    virtual BOOL OnInitDialog();
};

