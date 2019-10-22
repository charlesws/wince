// SrewGTS400Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SrewGTS400.h"
#include "SrewGTS400Dlg.h"
#include "Common.h"
#include "Input.h"
#include "MainDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma optimize( "", off )
// CSrewGTS400Dlg 对话框

CSrewGTS400Dlg::CSrewGTS400Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSrewGTS400Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSrewGTS400Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CSrewGTS400Dlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	
	ON_BN_CLICKED(IDC_Login, &CSrewGTS400Dlg::OnBnClickedLogin)
	
	ON_STN_CLICKED(IDC_user, &CSrewGTS400Dlg::OnStnClickeduser)
	ON_STN_CLICKED(IDC_passwrd, &CSrewGTS400Dlg::OnStnClickedpasswrd)
	ON_BN_CLICKED(IDC_BUTTON3, &CSrewGTS400Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSrewGTS400Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CSrewGTS400Dlg 消息处理程序

BOOL CSrewGTS400Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_user = "";
	m_passwrd = "";
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CSrewGTS400Dlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SREWGTS400_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SREWGTS400_DIALOG));
	}
}
#endif


void CSrewGTS400Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	//com->ReadModuleConfig();
}

void CSrewGTS400Dlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	Common *com = new Common();
	if(m_user.Compare(L"") == 0 || m_passwrd.Compare(L"") ==0)
	{
		AfxMessageBox(_T("Please input user name & password"));
	}else
	{
		if(com->VerifyUser(m_user,m_passwrd))
		{
			//AfxMessageBox(_T("Please input user name & password"));
			GetDlgItem(IDD_MAIN)->ShowWindow(SW_SHOW);

		}else
		{
			AfxMessageBox(_T("Invalid  user name or password"));
		}
	}
	//


}


void CSrewGTS400Dlg::OnStnClickeduser()
{
	// TODO: 在此添加控件通知处理程序代码
	CString m_UserInput;
	CInput key;

	key.m_str = m_user;

	if(key.DoModal()==IDOK)
	{
		m_UserInput = key.get_str();
		if(m_UserInput.Compare(L"") == 0)
			return;
		else
		{
			m_UserInput.Remove('\r');
			m_UserInput.Remove('\n');
			m_user = m_UserInput;
			
			GetDlgItem(IDC_user)->SetWindowText(m_user);

			UpdateData(FALSE);
		}
	}

}

void CSrewGTS400Dlg::OnStnClickedpasswrd()
{
	// TODO: 在此添加控件通知处理程序代码
	CString m_UserInput;
	CInput key;

	key.m_str = m_passwrd;

	if(key.DoModal()==IDOK)
	{
		m_UserInput = key.get_str();
		if(m_UserInput.Compare(L"") == 0)
			return;
		else
		{
			m_passwrd = m_UserInput;
			
			GetDlgItem(IDC_passwrd)->SetWindowText(m_passwrd);

			UpdateData(FALSE);
		}
	}
}

void CSrewGTS400Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//GetDlgItem(IDD_MAIN)->ShowWindow(SW_SHOW);
	MainDialog *Dlg = new MainDialog; 
			Dlg->Create(IDD_MAIN);
			Dlg->ShowWindow(SW_SHOW);
			//OnCancel();
			

}

void CSrewGTS400Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}
