// InputDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Input.h"
//#include "GunManage.h"
//#include "SIPAPI.H"
//#include "winuser.h"
//#include "afxdialogex.h"
using namespace std;

static int x1 = 0;
static int S_xy = 0;
// CInput �Ի���
//extern GunManage Gun;	
IMPLEMENT_DYNAMIC(CInput, CDialog)
const int		kEdit			= 1999;
const int		kOK				= 1998;
const int		kCancel			= 1997;
const int		kCapsLock		= 1996;
const int		kBackspace		= 1995;
const int		kClear			= 1994;
const int		kTab			= 1993;
const int		kButtonIdMin	= 2000;
const int		kButtonIdMax	= 2050;
CInput::CInput(CWnd* pParent /*=NULL*/)
	: CDialog(CInput::IDD, pParent)
{
	int i;
	for( i = 0; i < 51; i++)
	{
		m_charButton[i] = NULL;
	}
	i = 0;
	for(; i < 7; i++)
	{
		m_funButton[i] = NULL;
	}

	m_edit = NULL;

}

CInput::~CInput()
{
	int i;
	for( i = 0; i < 51; i++)
	{
		delete m_charButton[i];
	}
	i = 0;
	for(; i < 7; i++)
	{
		delete m_funButton[i];
	}

	delete m_edit;
}

void CInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInput, CDialog)
	//ON_BN_CLICKED(IDC_BUTTON1, &CInput::OnBnClickedButton1)
	//ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//ON_WM_ERASEBKGND()
END_MESSAGE_MAP()





void CInput::DeInit(void)
{
	int i;
	for( i = 0; i < 51; i++)
	{
		if(m_charButton[i] != NULL)
		{
			delete m_charButton[i];
			m_charButton[i] = NULL;
		}
	}
	for( i = 0; i < 7; i++)
	{
		if(m_funButton[i] != NULL)
		{
			delete m_funButton[i];
			m_funButton[i] = NULL;
		}
	}
	if(m_edit != NULL)
	{
		delete m_edit;
		m_edit = NULL;
	}

}
void CInput::Init(void)
{
	int i,j;
	CString str;
	CRect rect_button;
	float horizontal_gap, vertical_gap;		//��ť������,������ ��СΪ��ť��1/4
	float horizontal_button, vertical_button;	//��ť���򳤶�,������ ��СΪ
	int id = kButtonIdMin;
	int k = 0;
	CFont *pFont = new CFont;
	CFont *pFont1 = new CFont;
	CFont *pFont0 = new CFont;

	int font_zoom = 25;
	float lt = 0;
	float rt = 0;
	char* s = NULL;

	
	//vertical_gap = vertical_gap = cell/4
	
		S_xy = 0;
		::SetWindowPos(this->m_hWnd,HWND_BOTTOM,0,0,800,480,SWP_NOZORDER);  //���ô��ڴ�С
		CenterWindow();//������ʾ
		CRect rect; 
		GetWindowRect(rect);	//��ȡ�ͻ��˳ߴ�
		
		//     �����
		//  1	2	3	4
		//	5	6	7
		//	9	0	-	=
		// caplock <-  ����
		// OK	  CANCEL  =
		
		//���� 5gap + 4*4gap= 21gap
		//���� 7gap + 7*4gap = 35gap
		horizontal_gap = (float)rect.Width()/71;///21.0;
		vertical_gap = (float)rect.Height()/35;///31.0;
		horizontal_button = horizontal_gap*4;
		vertical_button = vertical_gap*4;
		//��һ��
		rect_button.top =  vertical_gap;
		rect_button.bottom = rect_button.top + vertical_gap*8 ;
		rect_button.left =  horizontal_gap*(71/21);
		rect_button.right = rect.Width() - rect_button.left;

		m_edit = new CEdit();
		m_edit->Create( ES_MULTILINE  | WS_VISIBLE , rect_button, this, kEdit);
		//bitmap.LoadBitmap(IDB_keypan);
	   // m_edit->ModifyStyle(0xF,SS_BITMAP); //��������١�
		//m_edit->SetBitmap((HBITMAP)bitmap);
		pFont->CreatePointFont(vertical_gap*18,_T("Arial"),NULL);
		pFont1->CreatePointFont(vertical_gap*12,_T("Arial"),NULL);
		pFont0->CreatePointFont(vertical_gap*15,_T("Arial"),NULL);
		m_edit->SetFont(pFont);
		//m_edit->SetFocus();
		m_edit->SetWindowText(m_str);
			
		//�ڶ���������
		for (i=1;i<6;i++)
		{
			char s[]= "`1234567890qwertyuiop[]asdfghjkl;\:zxcvbnm,-=\\/ .\"'";
			
			rect_button.top = /*rect.top +*/ vertical_gap*(i+1) + vertical_button*i +vertical_button;
			rect_button.bottom = rect_button.top + vertical_button;
			
			//�ڶ���
			if(i == 1)
			{
				for(j = 0; j < 12; j++)
				{
					rect_button.left =/* rect.left + */horizontal_gap*(j+1) + horizontal_button*j ;
					rect_button.right = rect_button.left + horizontal_button;

					
					if(j == 11)
					{
					rect_button.right = rect.Width() - horizontal_gap;
					m_funButton[1] = new CMyBitmapButton();
					m_funButton[1]->Create(_T("Backspace"), WS_VISIBLE, rect_button, this, kBackspace);
					m_funButton[1]->SetFont(pFont1);
					m_funButton[1]->SetWindowText(_T("Backspace"));
					}
					else
					{
					str.Format(_T("%c"),s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
				}
			}

			//������
			if(i == 2)
			{
				for(j = 0; j < 13; j++)
				{
					if(j ==0)
					{
					rect_button.left =/* rect.left + */horizontal_gap*(j+1) + horizontal_button*j ;
					rect_button.right = rect_button.left + horizontal_button + horizontal_gap*(1.64);
					lt = rect_button.left;
					rt = rect_button.right;
					}
					else
					{
					rect_button.left =rt + horizontal_gap*(j) + (horizontal_button + horizontal_gap*(0.28))*(j - 1);
					rect_button.right = rect_button.left + horizontal_button + horizontal_gap*(0.28);;
					}

					if(j == 0)	{
					
					m_funButton[2] = new CMyBitmapButton();
					m_funButton[2]->Create(_T("Tab"), WS_VISIBLE, rect_button, this, kTab);
					m_funButton[2]->SetFont(pFont1);
					m_funButton[2]->SetWindowText(_T("Tab"));
					
					
					/*
					str.Format(_T("%c"), s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					*/
					}
					else
					{
					str.Format(_T("%c"),s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
				}
			}
			//������
			if(i == 3)
			{
			for(j = 0; j < 12; j++)
			{
					if(j ==0)
					{
					rect_button.left =/* rect.left + */horizontal_gap*(j+1) + horizontal_button*j ;
					rect_button.right = rect_button.left + horizontal_button + horizontal_gap*(5.2);
					lt = rect_button.left;
					rt = rect_button.right;
					}
					else
					{
					rect_button.left =rt + horizontal_gap*(j) + (horizontal_button + horizontal_gap*(0.38))*(j - 1);
					rect_button.right = rect_button.left + horizontal_button + horizontal_gap*(0.38);
					}

					if(j == 0)
					{
					m_funButton[0] = new CMyBitmapButton();
					m_funButton[0]->Create(_T("CapsLock"), WS_VISIBLE, rect_button, this, kCapsLock);
					m_funButton[0]->SetFont(pFont1);
					m_funButton[0]->SetWindowText(_T("CapsLock"));
					}
					else
					{
						str.Format(_T("%c"),s[k]);
						m_charButton[k] = new CMyBitmapButton();
						m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
						m_charButton[k]->SetFont(pFont0);
						m_charButton[k]->SetWindowText(str);
						k++;
						}
						
					}
			}			
			
			
			//������
			if(i == 4)
			{
			for(j = 0; j < 9; j++)
			{
					if(j ==0)
					{
					rect_button.left =/* rect.left + */horizontal_gap*(j+1) + horizontal_button*j ;
					rect_button.right = rect_button.left + horizontal_button + horizontal_gap*(7.8);
					lt = rect_button.left;
					rt = rect_button.right;
					}
					else
					{
					rect_button.left =rt + horizontal_gap*(j) + (horizontal_button + horizontal_gap*(0.28))*(j - 1);
					rect_button.right = rect_button.left + horizontal_button + horizontal_gap*(0.28);
					}

					if(j == 0)
					{
					m_funButton[5] = new CMyBitmapButton();
					m_funButton[5]->Create(_T("Clear"), WS_VISIBLE, rect_button, this, kClear);
					m_funButton[5]->SetFont(pFont1);
					m_funButton[5]->SetWindowText(_T("Clear"));
					}
					else
					{
					str.Format(_T("%c"),s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}

			}
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect.Width() - horizontal_gap;
					m_funButton[3] = new CMyBitmapButton();
					m_funButton[3]->Create(_T("Enter"), WS_VISIBLE, rect_button, this, kOK);
					m_funButton[3]->SetFont(pFont1);
					m_funButton[3]->SetWindowText(_T("Enter"));
			}

			
			//������
			if(i == 5)
			{
			for(j = 0; j < 9; j++)
			{
					

					if(j == 0)
					{
						
					//rect_button.left =/* rect.left + */horizontal_gap*(j+1) + horizontal_button*j ;
					/*rect_button.right = rect_button.left + horizontal_button + horizontal_gap*(3.2);
					m_funButton[6] = new CMyBitmapButton();
					m_funButton[6]->Create(_T("\\"), WS_VISIBLE, rect_button, this, kCancel);
					m_funButton[6]->SetFont(pFont1);
					m_funButton[6]->SetWindowText(_T("\\"));
					*/
					rect_button.left = /*rect_button.right*/ horizontal_gap;
					rect_button.right = rect_button.left + horizontal_button - horizontal_gap*0.5;
					str.Format(_T("%c"),s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
					if(j == 1)
					{
					rect_button.left = rect_button.right + horizontal_gap - horizontal_gap*0.5;
					rect_button.right = rect_button.left + horizontal_button - horizontal_gap*0.5;
					str.Format(_T("%c"),s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
					if(j == 2)
					{
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect_button.left + horizontal_button - horizontal_gap*0.5;
					str.Format(_T("%c"), s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}

					if(j == 3)
					{
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect_button.left + horizontal_button - horizontal_gap*0.5;
					str.Format(_T("%c"), s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
					
					if(j == 4)
					{
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect_button.left + horizontal_button*7;
					str.Format(_T("%c"),s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}

					if(j == 5)
					{
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect_button.left + horizontal_button - horizontal_gap*0.5;
					str.Format(_T("%c"),s[k]);
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
					if(j == 6)
					{
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect_button.left + horizontal_button - horizontal_gap*0.5;
					str.Format(_T("%c"),s[k]);
					
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
					if(j == 7)
					{
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect_button.left + horizontal_button - horizontal_gap*0.5;
					str.Format(_T("%c"), s[k]);
					
					m_charButton[k] = new CMyBitmapButton();
					m_charButton[k]->Create(str, WS_VISIBLE, rect_button, this, id++);
					m_charButton[k]->SetFont(pFont0);
					m_charButton[k]->SetWindowText(str);
					k++;
					}
					if(j == 8)
					{
					rect_button.left = rect_button.right + horizontal_gap;
					rect_button.right = rect.Width() - horizontal_gap;
					m_funButton[4] = new CMyBitmapButton();
					m_funButton[4]->Create(_T("Cancel"), WS_VISIBLE, rect_button, this, kCancel);
					m_funButton[4]->SetFont(pFont1);
					m_funButton[4]->SetWindowText(_T("Cancel"));
					}
					
			}	

			}
					
			}

			}
	 
		


BOOL CInput::OnInitDialog()
{
	CDialog::OnInitDialog();
	key = 0;
	drawpic.DrawPictureInit(800,480);
	x1 = 0;
	drawpic.LoadJpgImage(L"\\HardDisk\\Setec\\Resource\\������.jpg",800,480);

	Init();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CInput::PreTranslateMessage(MSG* pMsg)
{
	int control_id;
	control_id = ::GetDlgCtrlID(pMsg->hwnd);
	CString str,strbtn;
	// TODO: �ڴ����ר�ô����/����û���
					/*const int		kOK				= 1998;
				const int		kCancel			= 1997;
				const int		kCapsLock		= 1996;
				const int		kBackspace		= 1995;
				const int		kSwitch			= 1994;*/
/**************************************************************************************/
			//if(pMsg->message == WM_LBUTTONUP)
	//�жϱ༭�����ǲ����������

	if(pMsg->message == WM_LBUTTONDOWN)
	{
				
				if(pMsg->hwnd == m_edit->m_hWnd)    //�༭��
				{
					point_analysis(pMsg->pt);
				}
	}
		

/******************************************************************************************/

	if ((pMsg->message == WM_LBUTTONDOWN)||(pMsg->message == WM_LBUTTONDBLCLK))
	{
		if (control_id == kOK)
		{
			x1 = 0;
			CInput::OnOK();
			return TRUE;
		} 
		else if (control_id == kClear)
		{
		
			//m_edit->Clear();
			x1 = 0;
			m_str = "";
			GetDlgItem(kEdit)->SetWindowText(m_str);
			return TRUE;
		}
		else if(control_id == kTab)
		{
			for(int i = 0; i < 3; i++)
			{
			GetDlgItemText(kEdit, str);
			//GetDlgItemText(control_id, strbtn); 

			CString str1, str2;
			strbtn = " ";

			if(x1 < 0)
			{
				str1 = m_str.Left(-x1)+strbtn;
				str2 = m_str.Right(m_str.GetLength()+x1);
			}
			else
			{
				str1 = m_str.Left(x1)+strbtn;
				str2 = m_str.Right(m_str.GetLength()-x1);
			}

			m_str = str1 + str2;
				
			GetDlgItem(kEdit)->SetWindowText(m_str);
			if(x1 >= 0)
			{
				x1++;
				m_edit->SetSel((x1), (x1));
				m_edit->SetFocus();
			}
			else
			{
				x1--;
				m_edit->SetSel((-x1), (-x1));
				m_edit->SetFocus();
			}
		}
			return TRUE;		
		}
		else if (control_id == kCancel)
		{
			x1 = 0;
			//CInput::OnCancel();
			CInput::OnOK();
			return TRUE;
		}
		else if (control_id == kCapsLock)
		{
			if (m_capsLock == TRUE){
				m_capsLock = FALSE;
			}
			else{
				m_capsLock = TRUE;
			}
			int i;
			CString str;
			 //"`1234567890'qwertyuiop[]asdfghjkl;zxcvbnm,-=/ .
			char s[] = "`1234567890qwertyuiop[]asdfghjkl;\:zxcvbnm,-=\\/ .\"'";
			char S[] = "`1234567890QWERTYUIOP[]ASDFGHJKL;\:ZXCVBNM,-=\\/ .\"'";
			if (m_capsLock == TRUE)
			{
				for (i=0;i < strlen(S);i++)
				{
				str.Format(_T("%c"),S[i]);
				GetDlgItem(kButtonIdMin + i)->SetWindowText(str);
				}
				int n = strlen(s);
				int y;
			}
			else
			{
				for (i=0;i < strlen(s);i++)
				{
				str.Format(_T("%c"),s[i]);
				GetDlgItem(kButtonIdMin + i)->SetWindowText(str);
				}
			}

			return TRUE;
		} 
		else if (control_id == kBackspace)
		{			
			GetDlgItemText(kEdit, str);
			
			if(x1 > 0)
			{
				CString str1, str2;
				str1 = m_str.Left(x1 - 1);
				str2 = m_str.Right(m_str.GetLength()-x1);
				m_str = str1 + str2;
			}
			else
			{
				if((x1 != 0))
				{
				CString str1, str2;
				str1 = m_str.Left( -x1 - 1);
				str2 = m_str.Right(m_str.GetLength()+x1);
				m_str = str1 + str2;
				}			
			}
			
			GetDlgItem(kEdit)->SetWindowText(m_str);
			if(x1 > 0)
			{
				x1--;
				m_edit->SetSel((x1), (x1));
				m_edit->SetFocus();
			}

			else
			{
				if((x1 != 0))
				{
				x1++;
				m_edit->SetSel((-x1), (-x1));
				m_edit->SetFocus();
				}
			}	
			return TRUE;
		}
		else
		{
			if ((control_id >= kButtonIdMin && control_id < kButtonIdMax))
			{	
				GetDlgItemText(kEdit, str);
				GetDlgItemText(control_id, strbtn); 

				CString str1, str2;

				if(x1 < 0)
				{
					str1 = m_str.Left(-x1)+strbtn;
					str2 = m_str.Right(m_str.GetLength()+x1);
				}
				else
				{
					str1 = m_str.Left(x1)+strbtn;
					str2 = m_str.Right(m_str.GetLength()-x1);
				}

				m_str = str1 + str2;
				
				GetDlgItem(kEdit)->SetWindowText(m_str);
				if(x1 >= 0)
				{
					x1++;
					m_edit->SetSel((x1), (x1));
					m_edit->SetFocus();
				}
				else
				{
					x1--;
					m_edit->SetSel((-x1), (-x1));
					m_edit->SetFocus();
				}

				return TRUE;
			} 
		}		
	}
	else 
	{
		return CDialog::PreTranslateMessage(pMsg);
	}
	//return CDialog::PreTranslateMessage(pMsg);
}

/*void CInput::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	drawpic.DrawImage(dc);	
}*/

HBRUSH CInput::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	switch(pWnd->GetDlgCtrlID())
	{
     case kEdit:
			pDC->SetBkColor(RGB(0,0,0));
			hbr=CreateSolidBrush(RGB(0,0,0));
            pDC->SetTextColor(RGB(255,255,255));break;
	}
	
	return hbr;
}

/*BOOL CInput::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return TRUE;
}*/


/*
������ʹ�ã�
��1��֪��ÿ����ռ���ٸ�x����x_font_size��ʶ�����Ǹ��ݱ༭��ĳ���/��һ���ܹ��������ַ���
	 ͬ��y����Ҳ����������y_font_size
 (2) ֪���༭�����Ͻǵĵ�����lx,ly
��3��ÿ�д�ŵ������ַ���row_size
 (4) ������ڵڶ���Hour������൱�ڱ༭��ĵ�һ��λ������Ϊ2^8+row_size
     �����ڲ�ȷ���ǲ�����Ӧ���б༭��ʹ��Hour��Ҫȥ����
 (5) jΪ����
 (6) ʹ��Hourȥ��ʼ����Ӧ�����Ă������ݽ���ʵ�����

*/

void CInput::point_analysis(POINT point)
{
	CRect rect; 
	GetWindowRect(rect);	//��ȡ�ͻ��˳ߴ�

	float horizontal_gap;		//��ť������,������ ��СΪ��ť��1/4
	horizontal_gap = (float)rect.Width()/71;///21.0;

	int nLeft = 0, nTop = 0;
	nLeft = horizontal_gap*(71/21);//rect.Width() / 21;
	nTop = rect.Height()/35;

	if ( point.x >= nLeft )
		point.x = point.x - nLeft;
	if ( point.y >= nLeft )
		point.y = point.y - nTop;

	CPoint cPoint(point.x, point.y);
	int nIndex = 0, nLine = 0;
	WORD wRet = m_edit->CharFromPos(cPoint);
	int nTotalIndex = LOWORD(wRet);

	m_edit->SetSel(nTotalIndex, nTotalIndex);
	m_edit->SetFocus();
	x1 = nTotalIndex;
}

/*
���˼·��
�ο�����ע��ȥ�Ĵ���
*/