﻿// DlgUserInfo.cpp: 구현 파일
//

#include "stdafx.h"
#include "LATS.h"
#include "DlgUserInfo.h"
#include "afxdialogex.h"


// CDlgUserInfo 대화 상자

IMPLEMENT_DYNAMIC(CDlgUserInfo, CDlgChildBase)

CDlgUserInfo::CDlgUserInfo(CWnd* pParent /*=nullptr*/)
	: CDlgChildBase(IDD_DLG_USERINFO, pParent)
{

}

CDlgUserInfo::~CDlgUserInfo()
{
}

void CDlgUserInfo::SetChildAndControlPosition()
{
}

void CDlgUserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDlgChildBase::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgUserInfo, CDlgChildBase)
END_MESSAGE_MAP()


// CDlgUserInfo 메시지 처리기


BOOL CDlgUserInfo::OnInitDialog()
{
	CDlgChildBase::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(BKC_USERIFO);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
