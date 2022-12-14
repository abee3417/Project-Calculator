
// calculatorDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 대화 상자



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_value(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_value);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CcalculatorDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTONT_TWO, &CcalculatorDlg::OnBnClickedButtontTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CcalculatorDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CcalculatorDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CcalculatorDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CcalculatorDlg::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CcalculatorDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CcalculatorDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CcalculatorDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CcalculatorDlg::OnBnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CcalculatorDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CcalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CcalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_TIMES, &CcalculatorDlg::OnBnClickedButtonTimes)
	ON_BN_CLICKED(IDC_BUTTON_DIVISION, &CcalculatorDlg::OnBnClickedButtonDivision)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CcalculatorDlg::OnBnClickedButtonEqual)
END_MESSAGE_MAP()


// CcalculatorDlg 메시지 처리기

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClickedButtonOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 1;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtontTwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 2;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonThree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 3;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonFour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 4;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonFive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 5;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonSix()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 6;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonSeven()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 7;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonEight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 8;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonNine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 9;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonZero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_current = 0;
	stackValue();
}


void CcalculatorDlg::OnBnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_value = 0;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	before = m_value;
	m_value = 0;
	m_state = PLUS;
}


void CcalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	before = m_value;
	m_value = 0;
	m_state = MINUS;
}


void CcalculatorDlg::OnBnClickedButtonTimes()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	before = m_value;
	m_value = 0;
	m_state = TIMES;
}


void CcalculatorDlg::OnBnClickedButtonDivision()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	before = m_value;
	m_value = 0;
	m_state = DIVISION;
}


void CcalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	after = m_value;
	if (m_state == PLUS) {
		m_value = 0;
		m_value = before + after;
		UpdateData(false);
	}
	else if (m_state == MINUS) {
		m_value = 0;
		m_value = before - after;
		UpdateData(false);
	}
	else if (m_state == TIMES) {
		m_value = 0;
		m_value = before * after;
		UpdateData(false);
	}
	else if (m_state == DIVISION) {
		m_value = 0;
		m_value = before / after;
		UpdateData(false);
	}
}

void CcalculatorDlg::stackValue() {
	if (m_value == 0) {
		m_value = m_current;
		UpdateData(false);
	}
	else if (m_value != 0) {
		m_value *= 10;
		m_value += m_current;
		UpdateData(false);
	}
}