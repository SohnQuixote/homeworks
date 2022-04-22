// ClientInterface.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ClientInterface.h"
#include "afxdialogex.h"


// ClientInterface 대화 상자

IMPLEMENT_DYNAMIC(ClientInterface, CDialogEx)

ClientInterface::ClientInterface(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT, pParent)
{

}

ClientInterface::~ClientInterface()
{
}

void ClientInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ClientInterface, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ClientInterface::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &ClientInterface::OnBnClickedButton1)
END_MESSAGE_MAP()


// ClientInterface 메시지 처리기


void ClientInterface::OnBnClickedButton2()
{
	ClientInterface::OnClose();
	this->DestroyWindow();
	delete(this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ClientInterface::OnBnClickedButton1()
{
	m_interface = new CMainInterface();
	m_interface->DoModal();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
