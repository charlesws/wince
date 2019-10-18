// MainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "SrewGTS400.h"
#include "MainDialog.h"
#include "Common.h"
#include "Input.h"
// MainDialog 对话框

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


// MainDialog 消息处理程序

void MainDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	BOOL bHandle = FALSE;
	CWnd *p = WindowFromPoint(point);
	//捕获鼠标按下事件
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
		dlg.m_inputType = 0;	//设置键盘种类 0:数字键盘 1:字母键盘
		dlg.set_str(str);	//设置初始键盘输入数字
		if(dlg.DoModal()==IDOK)   //如果按下确定
		{
			str = dlg.get_str(); //获取按键字符串
			SetDlgItemText(IDC_EDIT_ENDNUM, str);
		}
	}
	else if(p->GetDlgCtrlID()==IDC_EDIT_VALUE)
	{
		bHandle = TRUE;
		CString str;
		GetDlgItemText(IDC_EDIT_VALUE, str);
		CInputDialog   dlg;
		dlg.m_inputType = 0;	//设置键盘种类 0:数字键盘 1:字母键盘
		dlg.set_str(str);	//设置初始键盘输入数字
		if(dlg.DoModal()==IDOK)   //如果按下确定
		{
			str = dlg.get_str(); //获取按键字符串
			SetDlgItemText(IDC_EDIT_VALUE, str);
		}
	}*/

	
	//return bHandle;
//	CDialog::OnLButtonDown(nFlags, point);
}

BOOL MainDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

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

	// TODO:  在此添加额外的初始化

	LONG lStyle; 
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style

	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件

	

	m_list.InsertColumn( 0, L"用户名", LVCFMT_LEFT, 100 );//插入列 
	m_list.InsertColumn( 1, L"密码", LVCFMT_LEFT, 100 ); 
	m_list.InsertColumn( 2, L"权限", LVCFMT_LEFT, 100 ); 
	
	m_com.ReadUser();
	int i;
	int nRow;
	CString csTemp;
	for(i=0;i<m_com.m_user.GetSize();i++)
	{
		nRow = m_list.InsertItem(i, m_com.m_user.GetAt(i).name);//插入行
		m_list.SetItemText(nRow, 1, m_com.m_user.GetAt(i).passwrd);// 设置其它列数据

		csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
		m_list.SetItemText(nRow, 2,csTemp);// 设置其它列数据

	}

	
	
	 



	int nIndex = 0; 
	//选中 
	m_list.SetItemState(nIndex, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED); 



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void MainDialog::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码


		CString str; 
       for(int i=0; i<m_list.GetItemCount(); i++) 
       { 
           if( m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED ) 
           { 
                 //str.Format(_T(" 选中了第%d 行"), i); 
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
	// TODO: 在此添加控件通知处理程序代码
	CString csTemp;
	GetDlgItem(IDC_user)->GetWindowTextW(csTemp);

	int i;
	for(i=0;i<m_com.m_user.GetSize();i++)
	{
		if(m_com.m_user.GetAt(i).name == csTemp)
		{
			AfxMessageBox(L"已有相同名字数据"); 
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
	
	//list <int>  m_user;//定义变量
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
		nRow = m_list.InsertItem(i, m_com.m_user.GetAt(i).name);//插入行
		m_list.SetItemText(nRow, 1, m_com.m_user.GetAt(i).passwrd);// 设置其它列数据

		csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
		m_list.SetItemText(nRow, 2,csTemp);// 设置其它列数据

	}

	
}
void MainDialog::OnBnClickedmodify()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CString csTemp;
	GetDlgItem(IDC_user)->GetWindowTextW(csTemp);

	int i;
	for(i=0;i<m_com.m_user.GetSize();i++)
	{
		if(m_com.m_user.GetAt(i).name == csTemp)
		{
			//AfxMessageBox(L"已有相同名字数据"); 
			
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CFile mFile;
	
	if(GetFileAttributes(_T("\\HardDisk\\Setec\\Config\\User.ini")) != 0xFFFFFFFF)
   {
		AfxMessageBox(_T("此文件已存在！"));
   }
   else
   {
		AfxMessageBox(_T("此文件不存在！"));
   }
}
