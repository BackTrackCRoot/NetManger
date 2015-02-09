
// NetMangerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NetManger.h"
#include "NetMangerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNetMangerDlg �Ի���



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


// CNetMangerDlg ��Ϣ�������

BOOL CNetMangerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_Sex.SetWindowTextW(L"��");
	m_Sex.AddString(L"��");
	m_Sex.AddString(L"Ů");
	m_State.SetWindowTextW(L"����");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNetMangerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CNetMangerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNetMangerDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�����û�����ѯ
	CString mName;
	m_Name.GetWindowTextW(mName);
	if (mName.IsEmpty())
	{
		MessageBox(L"��ѯ�û�������Ϊ�գ�");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(L"����д�û����ݣ�", NULL, MB_OK);
	}
}


void CNetMangerDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		myPerson.SetPersonState(L"����");
		myPerson.Login();
		m_State.SetWindowTextW(L"����");
		//myPerson.SetPersonTime();
		Text = myPerson.GetPersonTime();
		m_Time.SetWindowTextW(Text);
		myPerson.~NetPerson();
	}
	else
	{
		MessageBox(L"��ѯ�û�������Ϊ�գ�");
	}
}


void CNetMangerDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString mName;
	m_Name.GetWindowTextW(mName);
	if (mName.IsEmpty())
	{
		MessageBox(L"��ѯ�û�������Ϊ�գ�");
	}
	else
	{
		NetPerson myPerson;
		myPerson.SetPersonName(mName);
		myPerson.Logout();
		myPerson.~NetPerson();
		CNetMangerDlg::OnBnClickedButton3();
		m_State.SetWindowTextW(L"����");
	}
}
