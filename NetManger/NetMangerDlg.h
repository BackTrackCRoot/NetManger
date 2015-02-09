
// NetMangerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "NetPerson.h"


// CNetMangerDlg �Ի���
class CNetMangerDlg : public CDialogEx
{
// ����
public:
	CNetMangerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NETMANGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CComboBox m_Sex;
	afx_msg void OnBnClickedButton3();
	CEdit m_Name;
	CEdit m_IDCard;
	CEdit m_ConmputerId;
	CEdit m_Time;
	CEdit m_Fee;
	afx_msg void OnBnClickedButton2();
	CEdit m_State;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
};
