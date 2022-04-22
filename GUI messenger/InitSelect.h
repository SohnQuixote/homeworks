#pragma once


// InitSelect 대화 상자
#define HOST 0
#define CLIENT 1
class InitSelect : public CDialogEx
{
	DECLARE_DYNAMIC(InitSelect)

public:
	InitSelect(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~InitSelect();
	int flag = -1;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
		afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
