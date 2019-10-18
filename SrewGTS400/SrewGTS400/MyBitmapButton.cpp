#include "StdAfx.h"
#include "MyBitmapButton.h"

CMyBitmapButton::CMyBitmapButton(void)
{
	down = false;
}

CMyBitmapButton::~CMyBitmapButton(void)
{
	
}
/*
CMyBitmapButton::set_bmp(CBitmap& bmp)
{
	m_bitmap = bmp;
}
*/
void CMyBitmapButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	 // TODO: Add your message handler code here and/or call default
    /*CDC ButtonDC;
    CBitmap bitmapTrans;
    BITMAP bmp;

	HBITMAP   hBitmap   =   NULL;     

    CDC mem;
    CRect rc;
    //�õ����ڻ��ư�ť��DC
    ButtonDC.Attach(lpDrawItemStruct->hDC);
    //׼��������ť������λͼ
    mem.CreateCompatibleDC(&ButtonDC);
    //��ȡ��ť��ռ�ľ��δ�С
    rc=lpDrawItemStruct->rcItem;
    //��ȡ��ťĿǰ������״̬�����ݲ�ͬ��״̬���Ʋ�ͬ�İ�ť*/
    UINT state = lpDrawItemStruct->itemState;
	
    //�����ť�Ѿ��õ����㣬����ѡ��״̬�µİ�ť
	CClientDC dc(this);
	
	
    if(state & ODS_FOCUS)//ODS_SELECTED   ODS_FOCUS
    {
		HBITMAP m_hBitmap= SHLoadDIBitmap(m_down_bitmap);//(L"\\HardDisk\\Setec\\Resource\\CCS.bmp");
		
		/*CBitmap bitmap;    
		bitmap.Attach(m_hBitmap); //����λͼ����
		BITMAP bmp;
		bitmap.GetBitmap(&bmp); //��ȡλͼ��Ϣ*/
		
		HBITMAP OldBitmap; 
		CDC MemDC; 
		CBitmap* pBitmap;

		MemDC.CreateCompatibleDC(&dc); 
		OldBitmap=(HBITMAP)MemDC.SelectObject(m_hBitmap); 
		pBitmap = CBitmap::FromHandle(m_hBitmap); 
			
		CRect rect; 
		GetClientRect(&rect);    
			
		BITMAP bmInfo;
		pBitmap->GetObject(sizeof(bmInfo),&bmInfo);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&MemDC, 0,0, bmInfo.bmWidth,bmInfo.bmHeight, SRCCOPY);//����StretchBlt������ͼʵ���Զ�����
		MemDC.SelectObject(OldBitmap);
		DeleteObject(pBitmap);
		DeleteObject(OldBitmap);
		DeleteObject(m_hBitmap);
		MemDC.DeleteDC();	
	}
	else
	{
		HBITMAP m_hBitmap= SHLoadDIBitmap(m_normal_bitmap);//(L"\\HardDisk\\Setec\\Resource\\CCS.bmp");
				
		HBITMAP OldBitmap; 
		CDC MemDC; 
		CBitmap* pBitmap;
		MemDC.CreateCompatibleDC(&dc); 
		OldBitmap=(HBITMAP)MemDC.SelectObject(m_hBitmap); 
		pBitmap = CBitmap::FromHandle(m_hBitmap); 
			
		CRect rect; 
		GetClientRect(&rect);    
			
		BITMAP bmInfo;
		pBitmap->GetObject(sizeof(bmInfo),&bmInfo);
		dc.StretchBlt(0,0,rect.Width(), rect.Height(), &MemDC, 0,0, bmInfo.bmWidth,bmInfo.bmHeight, SRCCOPY);//����StretchBlt������ͼʵ���Զ�����
		MemDC.SelectObject(OldBitmap);
		DeleteObject(pBitmap);
		DeleteObject(OldBitmap);
		DeleteObject(m_hBitmap);
		MemDC.DeleteDC();
	}
    //CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

BOOL CMyBitmapButton::PreTranslateMessage(MSG* pMsg)
{//���غ�����ʵ�ֲ��ܵ�������Hour������һ�ε����⡣
// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_LBUTTONDBLCLK)
		pMsg->message = WM_LBUTTONDOWN;
	return CButton::PreTranslateMessage(pMsg);
}