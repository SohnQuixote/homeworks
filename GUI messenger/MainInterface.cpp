// MainInterface.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "MainInterface.h"
#include "afxdialogex.h"


// MainInterface 대화 상자

IMPLEMENT_DYNAMIC(MainInterface, CDialogEx)

MainInterface::MainInterface(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAININTERFACE, pParent)
{

}

MainInterface::~MainInterface()
{
}

void MainInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainInterface, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &MainInterface::OnBnClickedButton3)
END_MESSAGE_MAP()


// MainInterface 메시지 처리기


void MainInterface::OnBnClickedButton3()
{
	CDialogEx::OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
