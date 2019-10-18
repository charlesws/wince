#pragma once
#include "afxext.h"

class CMyBitmapButton :
	public CBitmapButton
{
public:
	CMyBitmapButton(void);
	~CMyBitmapButton(void);
	
	bool down;
	CBitmapButton *btn;
	CString m_normal_bitmap;
	CString m_down_bitmap;
	
public:
    CMyBitmapButton(CBitmapButton *button)
    {
        btn=button;
    }
	inline void set_normal_bitmap(CString str){
		m_normal_bitmap = str;
	}
	inline void set_down_bitmap(CString str){
		m_down_bitmap = str;
	}
	//set_bmp(CBitmap& bmp);
    inline CBitmap * Nor(){ //normal image (REQUIRED)
        return (CBitmap *)(PCHAR(btn)+(ULONG)(PCHAR (&m_bitmap)-PCHAR(this)));//not PTCHAR, butPCHAR
    }
    inline CBitmap * Sel(){ // selected image (OPTIONAL)
        return (CBitmap *)(PCHAR(btn)+(ULONG)(PCHAR (&m_bitmapSel)-PCHAR(this)));//not PTCHAR, butPCHAR
    }
    inline CBitmap * Foc(){ // focused but not selected (OPTIONAL)
        return (CBitmap *)(PCHAR(btn)+(ULONG)(PCHAR (&m_bitmapFocus)-PCHAR(this)));//not PTCHAR, butPCHAR
    }
    inline CBitmap * Dis(){ // disabled bitmap (OPTIONAL)
        return (CBitmap *)(PCHAR(btn)+(ULONG)(PCHAR (&m_bitmapDisabled)-PCHAR(this)));//not PTCHAR, butPCHAR
    }
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
