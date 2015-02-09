
// NetMangerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "NetPerson.h"


// CNetMangerDlg 对话框
class CNetMangerDlg : public CDialogEx
{
// 构造
public:
	CNetMangerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_NETMANGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
