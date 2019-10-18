#pragma once
#include "GifCtrl.h"
class paintpic
{
public:
	paintpic(void);

	HGDIOBJ m_ImageMemery;			//ªÊÕº
	HDC m_dc;										//ªÊÕº…Ë±∏
	IImagingFactory *m_pImgFactory;
    IImage *m_pImage;
	CString m_url;
	void   DrawImage(HDC   hdc,int weight,int height); 
	bool LoadJpgImage(LPCTSTR szFileName,int weight,int height);
	
	bool DrawPictureInit(int weight,int height);

	~paintpic(void);
};
