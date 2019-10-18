// MainDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SrewGTS400.h"
#include "MainDialog.h"
#include "Common.h"
#include "Input.h"
// MainDialog �Ի���

IMPLEMENT_DYNAMIC(MainDialog, CDialog)

MainDialog::MainDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MainDialog::IDD, pParent)
{

}

MainDialog::~MainDialog()
{
}

void MainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(MainDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDialog::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDC_BUTTON2, &MainDialog::OnBnClickedButton2)
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MainDialog::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON7, &MainDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_modify, &MainDialog::OnBnClickedmodify)
	ON_BN_CLICKED(IDC_delete, &MainDialog::OnBnClickeddelete)
	ON_BN_CLICKED(IDC_BUTTON3, &MainDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// MainDialog ��Ϣ�������

void MainDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Common *com = new Common();
	com->ReadModuleConfig();
	//m_com.ReadModuleConfig();
	CString csTemp;

	GetDlgItem(IDC_DstVel)->GetWindowTextW(csTemp);
	com->m_syspara[0].DstVel = _wtof(csTemp);
	
	GetDlgItem(IDC_StartVel)->GetWindowTextW(csTemp);
	com->m_syspara[0].StartVel = _wtof(csTemp);
	
	GetDlgItem(IDC_Acc)->GetWindowTextW(csTemp);
	com->m_syspara[0].Acc = _wtof(csTemp);
	
	GetDlgItem(IDC_DstVel1)->GetWindowTextW(csTemp);
	com->m_syspara[1].DstVel = _wtof(csTemp);
	
	GetDlgItem(IDC_StartVel1)->GetWindowTextW(csTemp);
	com->m_syspara[1].StartVel = _wtof(csTemp);
	
	GetDlgItem(IDC_Acc1)->GetWindowTextW(csTemp);
	com->m_syspara[1].Acc = _wtof(csTemp);

	GetDlgItem(IDC_Dalay1)->GetWindowTextW(csTemp);
	com->m_userpara.Dalay1 = _wtoi(csTemp);

	GetDlgItem(IDC_Dalay2)->GetWindowTextW(csTemp);
	com->m_userpara.Dalay2 = _wtoi(csTemp);

	GetDlgItem(IDC_Dalay3)->GetWindowTextW(csTemp);
	com->m_userpara.Dalay3 = _wtoi(csTemp);

	com->WriteModuleConfig();
	

}


void MainDialog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Common *com = new Common();
	//com->ReadModuleConfig();
	m_com.ReadModuleConfig();
	CString csTemp;

	csTemp.Format(_T("%0.8f"), m_com.m_syspara[0].DstVel);
	GetDlgItem(IDC_DstVel)->SetWindowText(csTemp);

	csTemp.Format(_T("%0.8f"), m_com.m_syspara[0].StartVel);
	GetDlgItem(IDC_StartVel)->SetWindowText(csTemp);

	csTemp.Format(_T("%0.8f"), m_com.m_syspara[0].Acc);
	GetDlgItem(IDC_Acc)->SetWindowText(csTemp);


	csTemp.Format(_T("%0.8f"), m_com.m_syspara[1].DstVel);
	GetDlgItem(IDC_DstVel1)->SetWindowText(csTemp);

	csTemp.Format(_T("%0.8f"), m_com.m_syspara[1].StartVel);
	GetDlgItem(IDC_StartVel1)->SetWindowText(csTemp);

	csTemp.Format(_T("%0.8f"), m_com.m_syspara[1].Acc);
	GetDlgItem(IDC_Acc1)->SetWindowText(csTemp);


	csTemp.Format(_T("%d"), (int)m_com.m_userpara.Dalay1);
	GetDlgItem(IDC_Dalay1)->SetWindowText(csTemp);

	csTemp.Format(_T("%d"), (int)m_com.m_userpara.Dalay2);
	GetDlgItem(IDC_Dalay2)->SetWindowText(csTemp);

	csTemp.Format(_T("%d"), (int)m_com.m_userpara.Dalay3);
	GetDlgItem(IDC_Dalay3)->SetWindowText(csTemp);
}

void MainDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	BOOL bHandle = FALSE;
	CWnd *p = WindowFromPoint(point);
	//������갴���¼�
	if(p->GetDlgCtrlID()==IDC_DstVel)
	{
		bHandle = TRUE;
		
		CString m_UserInput;
		CString str;
		CInput key;

		GetDlgItemText(IDC_DstVel, str);
		key.m_str = str;

		if(key.DoModal()==IDOK)
		{
			m_UserInput = key.get_str();
			if(m_UserInput.Compare(L"") == 0)
				return;
			else
			{
			
				
				GetDlgItem(IDC_DstVel)->SetWindowText(m_UserInput);

				UpdateData(FALSE);
			}
		}
	}
	/*else if(p->GetDlgCtrlID()==IDC_EDIT_ENDNUM)
	{
		bHandle = TRUE;
		CString str;
		GetDlgItemText(IDC_EDIT_ENDNUM, str);
		CInputDialog   dlg;
		dlg.m_inputType = 0;	//���ü������� 0:���ּ��� 1:��ĸ����
		dlg.set_str(str);	//���ó�ʼ������������
		if(dlg.DoModal()==IDOK)   //�������ȷ��
		{
			str = dlg.get_str(); //��ȡ�����ַ���
			SetDlgItemText(IDC_EDIT_ENDNUM, str);
		}
	}
	else if(p->GetDlgCtrlID()==IDC_EDIT_VALUE)
	{
		bHandle = TRUE;
		CString str;
		GetDlgItemText(IDC_EDIT_VALUE, str);
		CInputDialog   dlg;
		dlg.m_inputType = 0;	//���ü������� 0:���ּ��� 1:��ĸ����
		dlg.set_str(str);	//���ó�ʼ������������
		if(dlg.DoModal()==IDOK)   //�������ȷ��
		{
			str = dlg.get_str(); //��ȡ�����ַ���
			SetDlgItemText(IDC_EDIT_VALUE, str);
		}
	}*/

	
	//return bHandle;
//	CDialog::OnLButtonDown(nFlags, point);
}

BOOL MainDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

		int control_id;
	control_id = ::GetDlgCtrlID(pMsg->hwnd);
	CString str,strbtn;
	
	if ((pMsg->message == WM_LBUTTONDOWN)||(pMsg->message == WM_LBUTTONDBLCLK))
	{
		if(control_id == IDC_DstVel )
		{
				CString m_UserInput;
			CString str;
			CInput key;

			GetDlgItemText(IDC_DstVel, str);
			key.m_str = str;

			if(key.DoModal()==IDOK)
			{
				m_UserInput = key.get_str();
				if(m_UserInput.Compare(L"") == 0);
					//return CDialog::PreTranslateMessage(pMsg);
				else
				{
				
					
					GetDlgItem(IDC_DstVel)->SetWindowText(m_UserInput);

					UpdateData(FALSE);
					return TRUE;
				}
			}
		}
		
		
	}
	/*else 
	{
		return CDialog::PreTranslateMessage(pMsg);
	}
*/
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL MainDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	LONG lStyle; 
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//��ȡ��ǰ����style 
	lStyle &= ~LVS_TYPEMASK; //�����ʾ��ʽλ 
	lStyle |= LVS_REPORT; //����style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//����style

	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl�� 
	dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl�� 
	dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�

	

	m_list.InsertColumn( 0, L"�û���", LVCFMT_LEFT, 100 );//������ 
	m_list.InsertColumn( 1, L"����", LVCFMT_LEFT, 100 ); 
	m_list.InsertColumn( 2, L"Ȩ��", LVCFMT_LEFT, 100 ); 
	
	m_com.ReadUser();
	int i;
	int nRow;
	CString csTemp;
	for(i=0;i<m_com.m_user.GetSize();i++)
	{
		nRow = m_list.InsertItem(i, m_com.m_user.GetAt(i).name);//������
		m_list.SetItemText(nRow, 1, m_com.m_user.GetAt(i).passwrd);// ��������������

		csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
		m_list.SetItemText(nRow, 2,csTemp);// ��������������

	}

	
	
	 



	int nIndex = 0; 
	//ѡ�� 
	m_list.SetItemState(nIndex, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED); 



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void MainDialog::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������


		CString str; 
       for(int i=0; i<m_list.GetItemCount(); i++) 
       { 
           if( m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED ) 
           { 
                 //str.Format(_T(" ѡ���˵�%d ��"), i); 
                 //AfxMessageBox(str); 

				GetDlgItem(IDC_user)->SetWindowText(m_com.m_user.GetAt(i).name);
				GetDlgItem(IDC_password)->SetWindowText(m_com.m_user.GetAt(i).passwrd);
				CString csTemp;
				csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
				GetDlgItem(IDC_level)->SetWindowText(csTemp);
           } 
       } 

	*pResult = 0;
}

//using namespace std;
void MainDialog::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString csTemp;
	GetDlgItem(IDC_user)->GetWindowTextW(csTemp);

	int i;
	for(i=0;i<m_com.m_user.GetSize();i++)
	{
		if(m_com.m_user.GetAt(i).name == csTemp)
		{
			AfxMessageBox(L"������ͬ��������"); 
			return;
		}
	}
	struct user user1;

	
	user1.name = csTemp;
	GetDlgItem(IDC_password)->GetWindowTextW(csTemp);
	user1.passwrd = csTemp;
	GetDlgItem(IDC_level)->GetWindowTextW(csTemp);
	user1.levle= _wtoi(csTemp);
	m_com.m_user.Add(user1);
	m_com.WriteUser();

	
	UpdateList();
	
	//list <int>  m_user;//�������
}

void MainDialog::UpdateList()
{
	//m_com.ReadUser();
	m_list.DeleteAllItems();
	int i;
	int nRow;
	CString csTemp;
	for(i=0;i<m_com.m_user.GetSize();i++)
	{
		nRow = m_list.InsertItem(i, m_com.m_user.GetAt(i).name);//������
		m_list.SetItemText(nRow, 1, m_com.m_user.GetAt(i).passwrd);// ��������������

		csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
		m_list.SetItemText(nRow, 2,csTemp);// ��������������

	}

	
}
void MainDialog::OnBnClickedmodify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CString csTemp;
	GetDlgItem(IDC_user)->GetWindowTextW(csTemp);

	int i;
	for(i=0;i<m_com.m_user.GetSize();i++)
	{
		if(m_com.m_user.GetAt(i).name == csTemp)
		{
			//AfxMessageBox(L"������ͬ��������"); 
			
			GetDlgItem(IDC_password)->GetWindowTextW(csTemp);
			m_com.m_user.GetAt(i).passwrd = csTemp;
			GetDlgItem(IDC_level)->GetWindowTextW(csTemp);
			m_com.m_user.GetAt(i).levle= _wtoi(csTemp);
			
			
			m_com.WriteUser();

			
			UpdateList();
			return;
		}
	}
	

}

void MainDialog::OnBnClickeddelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_list.DeleteAllItems();

	POSITION pos = m_list.GetFirstSelectedItemPosition();
      if (pos == NULL)
           TRACE0("No items were selected!\n");
      else
      {
           while (pos)
           {
                int nItem = m_list.GetNextSelectedItem(pos);
                TRACE1("Item %d was selected!\n", nItem);
				m_com.DeleteUser(m_com.m_user.GetAt(nItem).name);
				m_com.m_user.RemoveAt(nItem);

				m_com.WriteUser();
				UpdateList();
                // you could do your own processing on nItem here
           }
      }
}

void MainDialog::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFile mFile;
	
	if(GetFileAttributes(_T("\\HardDisk\\Setec\\Config\\User.ini")) != 0xFFFFFFFF)
   {
		AfxMessageBox(_T("���ļ��Ѵ��ڣ�"));
   }
   else
   {
		AfxMessageBox(_T("���ļ������ڣ�"));
   }
}
