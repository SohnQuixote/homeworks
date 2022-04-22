// CMainInterface.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "CMainInterface.h"
#include "afxdialogex.h"


// CMainInterface 대화 상자

IMPLEMENT_DYNAMIC(CMainInterface, CDialogEx)

CMainInterface::CMainInterface(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAININTERFACE, pParent)
{

}

CMainInterface::~CMainInterface()
{
}

void CMainInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainInterface, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CMainInterface::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMainInterface 메시지 처리기


void CMainInterface::OnBnClickedButton3()
{
	CMainInterface::OnCancel();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
