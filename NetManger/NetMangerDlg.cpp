
// NetMangerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "NetManger.h"
#include "NetMangerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNetMangerDlg 对话框



CNetMangerDlg::CNetMangerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNetMangerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetMangerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Sex);
	DDX_Control(pDX, IDC_EDIT1, m_Name);
	DDX_Control(pDX, IDC_EDIT2, m_IDCard);
	DDX_Control(pDX, IDC_EDIT3, m_ConmputerId);
	DDX_Control(pDX, IDC_EDIT4, m_Time);
	DDX_Control(pDX, IDC_EDIT5, m_Fee);
	//  DDX_Control(pDX, IDC_COMBO2, m_state);
	//  DDX_Control(pDX, IDC_COMBO2, mState);
	DDX_Control(pDX, IDC_EDIT6, m_State);
}

BEGIN_MESSAGE_MAP(CNetMangerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_CREATE()
ON_BN_CLICKED(IDC_BUTTON3, &CNetMangerDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON2, &CNetMangerDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON1, &CNetMangerDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON4, &CNetMangerDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CNetMangerDlg 消息处理程序

BOOL CNetMangerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_Sex.SetWindowTextW(L"男");
	m_Sex.AddString(L"男");
	m_Sex.AddString(L"女");
	m_State.SetWindowTextW(L"离线");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNetMangerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNetMangerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNetMangerDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	//根据用户名查询
	CString mName;
	m_Name.GetWindowTextW(mName);
	if (mName.IsEmpty())
	{
		MessageBox(L"查询用户名不能为空！");
	}
	else
	{
		NetPerson myPerson(mName);
		m_Name.SetWindowTextW(myPerson.GetPersonName());
		m_IDCard.SetWindowTextW(myPerson.GetPersonIDCard());
		m_Sex.SetWindowTextW(myPerson.GetPersonSex());
		//m_ConmputerId.SetWindowTextW(myPerson.GetPersonComputerID);
		m_Time.SetWindowTextW(myPerson.GetPersonTime());
		m_Fee.SetWindowTextW(myPerson.GetPersonFee());
		m_State.SetWindowTextW(myPerson.GetPersonState());
		myPerson.~NetPerson();
	}
}


void CNetMangerDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CString Text;
	NetPerson myPerson;
	m_Name.GetWindowTextW(Text);
	if (Text.IsEmpty())
	{
		myPerson.SetPersonName(Text);
		m_IDCard.GetWindowTextW(Text);
		myPerson.SetPersonIDCard(Text);
		m_Sex.GetWindowTextW(Text);
		myPerson.SetPersonSex(Text);
		m_ConmputerId.GetWindowTextW(Text);
		myPerson.SetComputerID(Text);
		m_Fee.GetWindowTextW(Text);
		myPerson.SetPersonFee(Text);
		m_State.GetWindowTextW(Text);
		myPerson.SetPersonState(Text);
		Text = myPerson.GetPersonTime();
		m_Time.SetWindowTextW(Text);
		myPerson.AddUser();
		myPerson.~NetPerson();
		m_Name.SetWindowTextW(L"");
		m_IDCard.SetWindowTextW(L"");
		m_Sex.SetWindowTextW(L"");
		m_ConmputerId.SetWindowTextW(L"");
		m_Fee.SetWindowTextW(L"");
		m_Time.SetWindowTextW(L"");
	}
	else
	{
		MessageBox(L"请填写用户数据！", NULL, MB_OK);
	}
}


void CNetMangerDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString Text;
	NetPerson myPerson;
	m_Name.GetWindowTextW(Text);
	if (!Text.IsEmpty())
	{

		m_Name.GetWindowTextW(Text);
		myPerson.SetPersonName(Text);
		m_ConmputerId.GetWindowTextW(Text);
		myPerson.SetComputerID(Text);
		myPerson.SetPersonTime(myPerson.GetNowTime());
		myPerson.SetPersonState(L"在线");
		myPerson.Login();
		m_State.SetWindowTextW(L"在线");
		//myPerson.SetPersonTime();
		Text = myPerson.GetPersonTime();
		m_Time.SetWindowTextW(Text);
		myPerson.~NetPerson();
	}
	else
	{
		MessageBox(L"查询用户名不能为空！");
	}
}


void CNetMangerDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	CString mName;
	m_Name.GetWindowTextW(mName);
	if (mName.IsEmpty())
	{
		MessageBox(L"查询用户名不能为空！");
	}
	else
	{
		NetPerson myPerson;
		myPerson.SetPersonName(mName);
		myPerson.Logout();
		myPerson.~NetPerson();
		CNetMangerDlg::OnBnClickedButton3();
		m_State.SetWindowTextW(L"离线");
	}
}
