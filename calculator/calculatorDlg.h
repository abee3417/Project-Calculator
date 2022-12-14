
// calculatorDlg.h: 헤더 파일
//

#pragma once


// CcalculatorDlg 대화 상자
class CcalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	static const int PLUS = 1;
	static const int MINUS = 2;
	static const int TIMES = 3;
	static const int DIVISION = 4;
public:
	afx_msg void OnBnClickedButtonOne();
	afx_msg void OnBnClickedButtontTwo();
	afx_msg void OnBnClickedButtonThree();
	afx_msg void OnBnClickedButtonFour();
	afx_msg void OnBnClickedButtonFive();
	afx_msg void OnBnClickedButtonSix();
	afx_msg void OnBnClickedButtonSeven();
	afx_msg void OnBnClickedButtonEight();
	afx_msg void OnBnClickedButtonNine();
	afx_msg void OnBnClickedButtonZero();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonTimes();
	afx_msg void OnBnClickedButtonDivision();
	afx_msg void OnBnClickedButtonEqual();
	void stackValue();
	int m_value;
	int m_current;
	int m_state;
	int before;
	int after;
};
