#include "StdAfx.h"
#include "paintpic.h"

paintpic::paintpic(void)
{
	//DrawPictureInit();
}

paintpic::~paintpic(void)
{
	DeleteObject(m_dc);
	DeleteObject(m_ImageMemery);
}
bool paintpic::DrawPictureInit(int weight,int height)
{
	m_pImgFactory = NULL;
    m_pImage = NULL;

	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	m_dc = CreateCompatibleDC(NULL);
	m_ImageMemery = CreateBitmap(weight, height, 1, 16, NULL);
	HRESULT ret = CoCreateInstance(CLSID_ImagingFactory, NULL, CLSCTX_INPROC_SERVER,
				IID_IImagingFactory, (void **)&m_pImgFactory);
	SelectObject(m_dc, m_ImageMemery);
	
	return false;
}

bool paintpic::LoadJpgImage(LPCTSTR szFileName,int weight,int height)
{
    // Create the imaging factory.  
        // Load the image from the JPG file.
	IImagingFactory *pImgFactory = NULL;
    IImage *pImage = NULL;

//	if (SUCCEEDED(CoCreateInstance (CLSID_ImagingFactory, NULL, CLSCTX_INPROC_SERVER,
//				IID_IImagingFactory, (void **)&pImgFactory)))
    {
        // Load the image from the JPG file.
        if ( SUCCEEDED(m_pImgFactory->CreateImageFromFile(szFileName, &m_pImage)) )
        {
            RECT temprect={0, 0, weight, height};
            m_pImage->Draw(m_dc, &temprect, NULL);
            m_pImage->Release();

            return TRUE;
        }
        else
            m_pImgFactory->Release();
            return FALSE;
    }
}
void   paintpic::DrawImage(HDC   hdc,int weight,int height) 
{ 
//	if ( m_ImageMemery != NULL )    ¿œ
    
        BitBlt(hdc, 0, 0, weight, height, m_dc, 0, 0, SRCCOPY);
}