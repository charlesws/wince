// SrewGTS400Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

// CSrewGTS400Dlg �Ի���
class CSrewGTS400Dlg : public CDialog
{
// ����
public:
	CSrewGTS400Dlg(CWnd* pParent = NULL);	// ��׼���캯��

	CString m_user;
	CString m_passwrd;
// �Ի�������
	enum { IDD = IDD_SREWGTS400_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
