// SrewGTS400Dlg.cpp : ʵ���ļ�
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
// CSrewGTS400Dlg �Ի���

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


// CSrewGTS400Dlg ��Ϣ�������

BOOL CSrewGTS400Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_user = "";
	m_passwrd = "";
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//com->ReadModuleConfig();
}

void CSrewGTS400Dlg::OnBnClickedLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//GetDlgItem(IDD_MAIN)->ShowWindow(SW_SHOW);
	MainDialog *Dlg = new MainDialog; 
			Dlg->Create(IDD_MAIN);
			Dlg->ShowWindow(SW_SHOW);
			//OnCancel();
			

}

void CSrewGTS400Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
