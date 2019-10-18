#pragma once
#define INITGUID 
#include <windows.h>
//#include <InitGuid.h>
//#include <imgguids.h>
#include <imaging.h>
enum GIFState
{
	GIF_IDLE,
	GIF_PLAY,
	GIF_STOP,
};
enum CodecType
{
	eDecoder, 
	eEncoder
};
class CGifCtrl
{
public:
	CGifCtrl(void);
	CGifCtrl(HWND hWnd);
	~CGifCtrl(void);
	BOOL LoadGIF(LPCTSTR filename);
	void Stop(void);
	void Play(void);
	BOOL PlayActive(void);
public:
	static HANDLE m_hPlayThread;
	static HANDLE hPlayMutex;
	GIFState GifStatus; 
private:
	UINT count;
	HWND g_hWnd;
	ImageInfo ii;
	IImage * g_pImage;
	//IImagingFactory * g_pImagingFactory ;
	IImagingFactory *pImagingFactory ;
	IImageSink *pImageSink ;
	IImageDecoder *pImageDecoder ;
	IImageEncoder *pImageEncoder;
	//IImageEncoder *pIETemp;
	IBitmapImage *pBitmapImage ;
	IStream *pStream ;
private:
	HRESULT CreateStreamOnFile(const TCHAR * tszFilename, IStream** ppStream);
	BOOL GetCodecCLSID(IImagingFactory* pImagingFactory, CLSID * clsid, WCHAR * wszMimeType, CodecType ctCodec);
	void DisplayEncoder(IImageEncoder * pImageEncoder);
	void UserCodecTest(IImagingFactory* pImagingFactory);
	void ReleaseImage(void);
};

