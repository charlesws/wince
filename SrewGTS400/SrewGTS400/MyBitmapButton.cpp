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
    //得到用于绘制按钮的DC
    ButtonDC.Attach(lpDrawItemStruct->hDC);
    //准备用于向按钮区域传输位图
    mem.CreateCompatibleDC(&ButtonDC);
    //获取按钮所占的矩形大小
    rc=lpDrawItemStruct->rcItem;
    //获取按钮目前所处的状态，根据不同的状态绘制不同的按钮*/
    UINT state = lpDrawItemStruct->itemState;
	
    //如果按钮已经得到焦点，绘制选中状态下的按钮
	CClientDC dc(this);
	
	
    if(state & ODS_FOCUS)//ODS_SELECTED   ODS_FOCUS
    {
		HBITMAP m_hBitmap= SHLoadDIBitmap(m_down_bitmap);//(L"\\HardDisk\\Setec\\Resource\\CCS.bmp");
		
		/*CBitmap bitmap;    
		bitmap.Attach(m_hBitmap); //关联位图对象
		BITMAP bmp;
		bitmap.GetBitmap(&bmp); //获取位图信息*/
		
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
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&MemDC, 0,0, bmInfo.bmWidth,bmInfo.bmHeight, SRCCOPY);//利用StretchBlt（）贴图实现自动拉伸
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
		dc.StretchBlt(0,0,rect.Width(), rect.Height(), &MemDC, 0,0, bmInfo.bmWidth,bmInfo.bmHeight, SRCCOPY);//利用StretchBlt（）贴图实现自动拉伸
		MemDC.SelectObject(OldBitmap);
		DeleteObject(pBitmap);
		DeleteObject(OldBitmap);
		DeleteObject(m_hBitmap);
		MemDC.DeleteDC();
	}
    //CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

BOOL CMyBitmapButton::PreTranslateMessage(MSG* pMsg)
{//重载函数，实现不管点击点击快Hour两次算一次的问题。
// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_LBUTTONDBLCLK)
		pMsg->message = WM_LBUTTONDOWN;
	return CButton::PreTranslateMessage(pMsg);
}