#pragma once


// ClientStartInterface 대화 상자

class ClientStartInterface : public CDialogEx
{
	DECLARE_DYNAMIC(ClientStartInterface)

public:
	ClientStartInterface(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ClientStartInterface();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
};
