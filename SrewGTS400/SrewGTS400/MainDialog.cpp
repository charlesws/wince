// MainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "SrewGTS400.h"
#include "MainDialog.h"
#include "Common.h"
#include "Input.h"
#include <time.h>


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
	DDX_Control(pDX, IDC_LIST2, m_list1);
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
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &MainDialog::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON8, &MainDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &MainDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_delete2, &MainDialog::OnBnClickeddelete2)
	ON_BN_CLICKED(IDC_delete3, &MainDialog::OnBnClickeddelete3)
	ON_BN_CLICKED(IDC_BUTTON9, &MainDialog::OnBnClickedButton9)
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


#if 1
	/*HWND lpClassName;
	lpClassName = ::FindWindow(TEXT("HHTaskBar"), NULL); 
	 ::ShowWindow(lpClassName, SW_HIDE); // 只隐藏Taskbar还不行，你得把work area 设为整个屏幕： 
	int screenx = GetSystemMetrics(SM_CXSCREEN); 
	int screeny = GetSystemMetrics(SM_CYSCREEN);
	 CRect rcWorkArea; 
	rcWorkArea.left   = -1; 
	 rcWorkArea.right  = 1024; 
	 rcWorkArea.top    = -24; 
	 rcWorkArea.bottom = 800; 
	 ::SystemParametersInfo(SPI_SETWORKAREA, 0, &rcWorkArea, SPIF_SENDCHANGE);*/


	// int m_nMaxX = GetSystemMetrics(SM_CXSCREEN); int m_nMaxY = GetSystemMetrics(SM_CYSCREEN);

// CRect rcTemp; rcTemp.BottomRight() = CPoint(m_nMaxX, m_nMaxY); rcTemp.TopLeft() = CPoint(0, 0); MoveWindow(&rcTemp);
#endif



	LONG lStyle; 
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style

	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件

	

	m_list.InsertColumn( 0, L"用户名", LVCFMT_LEFT, 150 );//插入列 
	m_list.InsertColumn( 1, L"密码", LVCFMT_LEFT, 150 ); 
	m_list.InsertColumn( 2, L"权限", LVCFMT_LEFT, 150 ); 
	
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



//	LONG lStyle; 
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list1.m_hWnd, GWL_STYLE, lStyle);//设置style

	 dwStyle = m_list1.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件

	

	m_list1.InsertColumn( 0, L"序号", LVCFMT_LEFT, 50 );//插入列 
	m_list1.InsertColumn( 1, L"文件名", LVCFMT_LEFT, 150 ); 
	m_list1.InsertColumn( 2, L"时间", LVCFMT_LEFT, 150 ); 

	//LPSYSTEMTIME st; 　
	m_com.find(L"\\HardDisk\\Setec\\Config",m_files);


	//int i;
	//int nRow;
	//CString csTemp;
	SYSTEMTIME st;
	FILETIME st1;
	CString timeStr;
	for(i=0;i<m_files.GetSize();i++)
	{
		timeStr.Format(L"%d",i+1);
		nRow = m_list1.InsertItem(i, timeStr);//插入行

		m_list1.SetItemText(nRow, 1, m_files.GetAt(i).cFileName);// 设置其它列数据
		
		FILETIME t1= m_files.GetAt(i).ftCreationTime;
		FileTimeToSystemTime(&m_files.GetAt(i).ftCreationTime,&st);
	//	FileTimeToLocalFileTime(&t1,st1);
		timeStr.Format(L"%d-%d-%d  %d:%d:%d",st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
		//timeStr.Format(L"%d:%d:%d",st->wHour,st->wMinute,st->wSecond);
		//timeStr.Format(_T("%d"), (int)st->wHour);
		//FileTimeToSystemTime(m_files.GetAt(i).ftCreationTime,st);
		//timeStr.Format(L"%d-%d-%d  %d:%d:%d",st.wYear,st.wMonth,st.wDay，st.wHour,st.wMinute,st.wSecond);
		m_list1.SetItemText(nRow, 2, timeStr);// 设置其它列数据
		//m_list.SetItemText(nRow, 1, files.GetAt(i));// 设置其它列数据

		//csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
		//m_list.SetItemText(nRow, 2,csTemp);// 设置其它列数据

	}

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
	m_files.RemoveAll();
	m_list1.DeleteAllItems();

	m_com.find(L"\\HardDisk\\Setec\\Config",m_files);
	
	int i;
	int nRow;
	CString csTemp;
	for(i=0;i<m_files.GetSize();i++)
	{
		nRow = m_list1.InsertItem(i, m_files.GetAt(i).cFileName);//插入行
		//m_list.SetItemText(nRow, 1, files.GetAt(i));// 设置其它列数据

		//csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
		//m_list.SetItemText(nRow, 2,csTemp);// 设置其它列数据

	}

	/*CFile mFile;
	
	if(GetFileAttributes(_T("\\HardDisk\\Setec\\Config\\User.ini")) != 0xFFFFFFFF)
   {
		AfxMessageBox(_T("此文件已存在！"));
   }
   else
   {
		AfxMessageBox(_T("此文件不存在！"));
   }

	DeleteFile(L"\\My Documents\\MyFile.dat");*/
	//CString filePathName = L"";
	//CFileDialog dlg(TRUE);
	//if(dlg.DoModal() == IDOK){
	//	filePathName = dlg.GetPathName();
	//	//this->m_Ring.SetWindowTextW(filePathName);
	//}
}



void MainDialog::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString str; 
       for(int i=0; i<m_list1.GetItemCount(); i++) 
       { 
           if( m_list1.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED ) 
           { 
                 //str.Format(_T(" 选中了第%d 行"), i); 
                 //AfxMessageBox(str); 

			   GetDlgItem(IDC_filename)->SetWindowText(m_files.GetAt(i).cFileName);
			   m_selectedFile = m_files.GetAt(i).cFileName;
				/*GetDlgItem(IDC_password)->SetWindowText(m_com.m_user.GetAt(i).passwrd);
				CString csTemp;
				csTemp.Format(_T("%d"), (int)m_com.m_user.GetAt(i).levle);
				GetDlgItem(IDC_level)->SetWindowText(csTemp);*/
           } 
       } 


	*pResult = 0;
}

void MainDialog::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CString creatfile:
	GetDlgItem(IDC_filename)->GetWindowTextW(creatfile);
	for(i=0;i<m_files.GetSize();i++)
	{
		if(m_files.GetAt(i) == creatfile)
		{
			AfxMessageBox(_T("此文件已存在！"));
			return;
		}
	}*/
	//creat file,
	CFile mFile;
	CString creatfile;
	CString creatfileFull;
	GetDlgItem(IDC_filename)->GetWindowTextW(creatfile);
	creatfileFull = _T("\\HardDisk\\Setec\\Config\\") + creatfile;
	if(GetFileAttributes(creatfileFull) != 0xFFFFFFFF)
	{
		AfxMessageBox(_T("此文件已存在！"));
	}
	else
	{
		//AfxMessageBox(_T("此文件不存在！"));
		if (!mFile.Open(creatfileFull,CFile::modeCreate|CFile::modeWrite))//创建失败
		  {
		   AfxMessageBox(_T("创建数据库失败"));
		   return;
		  }
		mFile.Close();

		m_com.WriteConfig(creatfileFull);
		
	}

	OnBnClickedButton3();
}

void MainDialog::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString creatfile;
	CString directory;
	CString creatfileFull;
	GetDlgItem(IDC_filename)->GetWindowTextW(creatfile);
	directory = _T("\\HardDisk\\Setec\\Config\\");
	creatfileFull = _T("\\HardDisk\\Setec\\Config\\") + creatfile;
	if(GetFileAttributes(creatfileFull) != 0xFFFFFFFF)
	{
		AfxMessageBox(_T("此文件已存在！"));
	}
	else
	{
		//AfxMessageBox(_T("此文件不存在！"));
		//m_com.WriteConfig(creatfileFull);
		//复制文件
		bool file_copy_flag;
		file_copy_flag = CopyFile(directory+m_selectedFile,directory+creatfile,false);
		if(file_copy_flag){
		//删除原文件
			
			DeleteFile(directory+m_selectedFile);
		}else{
			AfxMessageBox(_T("删除原文件失败！"));
		}

	}

	OnBnClickedButton3();
}

void MainDialog::OnBnClickeddelete2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString creatfile;
	CString directory;
	CString creatfileFull;
	GetDlgItem(IDC_filename)->GetWindowTextW(creatfile);
	directory = _T("\\HardDisk\\Setec\\Config\\");
	creatfileFull = _T("\\HardDisk\\Setec\\Config\\") + creatfile;
	
	/*if(DeleteFile(directory+m_selectedFile))
		AfxMessageBox(_T("删除成功！"));
	else
		AfxMessageBox(_T("删除失败！"));
	OnBnClickedButton3();*/



	HANDLE   hFile;   
	WIN32_FIND_DATA   wfd;   
	SYSTEMTIME   systime;   
	FILETIME   localtime;   
	  
	memset(&wfd,   0,   sizeof(wfd));   
	    
	if((hFile=FindFirstFile(directory+m_selectedFile,   &wfd))==INVALID_HANDLE_VALUE)   
	{   

	return   ;//失败   
	}   
	//ok,转换时间   
	FileTimeToLocalFileTime(&wfd.ftLastWriteTime,&localtime);   
	FileTimeToSystemTime(&localtime,&systime);  

}

void MainDialog::OnBnClickeddelete3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString creatfile;
	CString directory;
	CString creatfileFull;
	GetDlgItem(IDC_filename)->GetWindowTextW(creatfile);
	directory = _T("\\HardDisk\\Setec\\Config\\");
	creatfileFull = _T("\\HardDisk\\Setec\\Config\\") + creatfile;
	//复制文件
	bool file_copy_flag;
	file_copy_flag = CopyFile(directory+m_selectedFile,L"USB HardDisk\\"+creatfile,false);
	if(file_copy_flag){
		//删除原文件
			AfxMessageBox(_T("拷贝成功！"));
		}else{
			AfxMessageBox(_T("拷贝失败！"));
		}

}

void MainDialog::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码

	CFile mFile;
	CString creatfile;
	CString creatfileFull;
	GetDlgItem(IDC_filename)->GetWindowTextW(creatfile);
	creatfileFull = _T("\\HardDisk\\Setec\\Config\\") + creatfile;
		
	m_com.ReadConfig(creatfileFull);
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
