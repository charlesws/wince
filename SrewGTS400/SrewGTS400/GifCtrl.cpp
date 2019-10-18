#include "StdAfx.h"
#include <InitGuid.h>
#include "GifCtrl.h"

HANDLE CGifCtrl::m_hPlayThread=NULL;
HANDLE CGifCtrl::hPlayMutex=NULL;
DWORD WINAPI ThreadFunc(CGifCtrl* ptr);

//#pragma comment(lib, "ole32.lib")
//#pragma comment(lib, "Imaging.lib")

CGifCtrl::CGifCtrl(void)
{

}

CGifCtrl::CGifCtrl(HWND hWnd)
{
	GifStatus = GIF_IDLE;
	g_pImage = NULL;
	//g_pImagingFactory = NULL;

	pImagingFactory = NULL;
	pImageSink = NULL;
	pImageDecoder = NULL;
	pImageEncoder = NULL;
	//pIETemp = NULL;
	pBitmapImage = NULL;
	pStream = NULL;

	g_hWnd=hWnd;
}

CGifCtrl::~CGifCtrl(void)
{
    ReleaseImage();
}

BOOL CGifCtrl::LoadGIF(LPCTSTR filename)
{
	
	HRESULT hr = CoCreateInstance(CLSID_ImagingFactory,	NULL, 
		CLSCTX_INPROC_SERVER, IID_IImagingFactory, (void**) &pImagingFactory);

	if (FAILED(hr))
	{
		goto finish;
	}

	if (FAILED(hr = CreateStreamOnFile(filename, &pStream)))
	{
		goto finish;
	}

	//GetCodecCLSID(pImagingFactory, NULL, NULL, eDecoder);

	if (FAILED(hr = pImagingFactory->CreateImageDecoder(pStream, DecoderInitFlagBuiltIn1st, &pImageDecoder)))
	{
		goto finish;
	}


	pImageDecoder->GetImageInfo(&ii);

	if (FAILED(hr = pImageDecoder->GetFrameCount(&FrameDimensionTime, &count)))
	{
		return 0;
	}
	return TRUE;

finish:
    ReleaseImage();
	return FALSE;

}
void CGifCtrl::ReleaseImage(void)
{
	if (pBitmapImage)
		pBitmapImage->Release();
    pBitmapImage=NULL;

	if (pStream)
		pStream->Release();
	pStream=NULL;

	if (pImageSink)
		pImageSink->Release();
	pImageSink=NULL;

	if (pImageDecoder)
		pImageDecoder->Release();
	pImageDecoder=NULL;

	if (pImageEncoder)
		pImageEncoder->Release();
	pImageEncoder=NULL;

	if (g_pImage)
		g_pImage->Release();
	g_pImage=NULL;

	if (pImagingFactory)
		pImagingFactory->Release();
	pImagingFactory=NULL;
}
void CGifCtrl::Play(void)
{

	DWORD ThreadId;
	DWORD res;

	res=WaitForSingleObject(hPlayMutex,INFINITE);

	//Release
	if(WAIT_OBJECT_0==res)
	{
		ReleaseMutex(hPlayMutex);
		CloseHandle(hPlayMutex);
	}

	//if (NULL==m_hPlayThread)
	{
		m_hPlayThread=CreateThread(NULL,0,(unsigned long(_stdcall*)(void*))ThreadFunc,this,0,&ThreadId);
		hPlayMutex=CreateMutex(0,FALSE,NULL);
	}
	GifStatus=GIF_PLAY;
	//CloseHandle(m_hPlayThread);
}


void CGifCtrl::Stop(void)
{
	GifStatus=GIF_STOP;
}

DWORD WINAPI ThreadFunc(CGifCtrl* ptr)
{
	ptr->PlayActive();
	return 0;
}

BOOL CGifCtrl::PlayActive(void)
{
	HDC hdc;
	RECT rc;
	HRESULT hr;
	UINT index = 0;

	while(GIF_PLAY==GifStatus)
	{
		//Sleep(100);
		hdc = GetDC(g_hWnd);
		GetClientRect(g_hWnd, &rc);
		
		if (FAILED(hr = pImagingFactory->CreateNewBitmap(ii.Width, ii.Height, ii.PixelFormat, &pBitmapImage)))
		{
			return 0;
		}

		if (FAILED(hr = pBitmapImage->QueryInterface(IID_IImageSink, (void**)&pImageSink)))
		{
			return 0;
		}

		if (FAILED(hr = pBitmapImage->QueryInterface(IID_IImage, (void**)&g_pImage)))
		{
			return 0;
		}
		if (FAILED(hr = pImageDecoder->SelectActiveFrame(&FrameDimensionTime, index)))
		{
			return 0;
		}

		if (FAILED(hr = pImageDecoder->BeginDecode(pImageSink, NULL)))
		{
			return 0;
		}

		while (E_PENDING == (hr = pImageDecoder->Decode()))
		{
			Sleep(0);
		}

		hr = pImageDecoder->EndDecode(hr);

		if (FAILED(hr))
		{
			return 0;
		}
		
		index ++;
		if(index == count)
		{
		    index = 0;
		}

		g_pImage->Draw(hdc, &rc, NULL);

		ReleaseDC(g_hWnd,hdc);
		if (pBitmapImage)
			pBitmapImage->Release();
		if (pImageSink)
			pImageSink->Release();
		if (g_pImage)
			g_pImage->Release();
		Sleep(150);
	}

    CloseHandle(m_hPlayThread);
	m_hPlayThread=NULL;
	ReleaseMutex(hPlayMutex);
	CloseHandle(hPlayMutex);
	hPlayMutex=NULL;

	return 0;
}

HRESULT  CGifCtrl::CreateStreamOnFile(const TCHAR * tszFilename, IStream ** ppStream)
{
	HRESULT hrRet = S_OK;
	HGLOBAL hg = NULL;
	HANDLE hFile = NULL;
	DWORD dwSize, dwRead;
	BYTE* pbLocked = NULL;

	// Open the file
	hFile = CreateFile(_T("\\ResidentFlash\\sptm0.gif"), GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{		
		goto error;
	}

	dwSize = GetFileSize(hFile, NULL);
	printf("size = %d\n", dwSize);
	if (0xffffffff == dwSize)
	{
		goto error;
	}

	// Open a memory object
	hg = GlobalAlloc(GMEM_MOVEABLE, dwSize);
	if (NULL == hg)
	{
		goto error;
	}

	// Ge a pointer to the memory we just allocated
	pbLocked = (BYTE*) GlobalLock(hg);
	if (NULL == pbLocked)
	{
		goto error;
	}

	// copy the file
	if (!ReadFile(hFile, pbLocked, dwSize, &dwRead, NULL))
	{
		goto error;
	}

	GlobalUnlock(hg);

	// Create the stream
	hrRet = CreateStreamOnHGlobal(hg, TRUE, ppStream);

	CloseHandle(hFile);
	return true;
error:
	if (pbLocked)
		GlobalUnlock(hg);
	if (hg)
		GlobalFree(hg);
	if (hFile)
		CloseHandle(hFile);
	return false;
}

BOOL  CGifCtrl::GetCodecCLSID(IImagingFactory* pImagingFactory, CLSID * pclsid, WCHAR * wszMimeType, CodecType ctCodec)
{
	UINT uiCount;
	ImageCodecInfo * codecs;
	HRESULT hr;
	BOOL fRet = FALSE;

	if (eEncoder == ctCodec)
	{
		hr = pImagingFactory->GetInstalledEncoders(&uiCount, &codecs);
	}
	else
	{
		hr = pImagingFactory->GetInstalledDecoders(&uiCount, &codecs);
	}
	if (FAILED(hr))
	{
		return FALSE;
	}

	for (UINT i = 0; i < uiCount; i++)
	{
		if (wszMimeType && !wcscmp(wszMimeType, codecs[i].MimeType))
		{
			*pclsid = codecs[i].Clsid;
			fRet = TRUE;
			break;
		}
	}
	CoTaskMemFree(codecs);
	return fRet;
}
