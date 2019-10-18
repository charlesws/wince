// SrewGTS400Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"

// CSrewGTS400Dlg 对话框
class CSrewGTS400Dlg : public CDialog
{
// 构造
public:
	CSrewGTS400Dlg(CWnd* pParent = NULL);	// 标准构造函数

	CString m_user;
	CString m_passwrd;
// 对话框数据
	enum { IDD = IDD_SREWGTS400_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedLogin();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickeduser();
	afx_msg void OnStnClickedpasswrd();
	
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
