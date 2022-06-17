#include "stdafx.h"
#include "DlgChildBase.h"



CDlgChildBase::CDlgChildBase(UINT ResourceID, CWnd* pParent)
	: CDialogEx(ResourceID, pParent)
{
	m_bInit = false;
}

CDlgChildBase::~CDlgChildBase()
{
	m_fnt_caption.DeleteObject();
}

void CDlgChildBase::SetLATSManagerAddress(CLATSManager* pManager)
{
	m_ptr_LATSManager = pManager;
}
BEGIN_MESSAGE_MAP(CDlgChildBase, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()

void CDlgChildBase::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	//�ʱ�ȭ �� ���̾�α� ��ġ
	if(m_bInit) SetChildAndControlPosition();

	//�ܻ� ����
	Invalidate(0);
}

BOOL CDlgChildBase::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_fnt_caption.CreateFont(15, 0, 0, 0, 0, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("�޸տ�ü"));

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
