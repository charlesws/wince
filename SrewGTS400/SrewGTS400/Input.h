#pragma once


// CInput 对话框
#include "Resource.h"
#include "MyBitmapButton.h"
#include "paintpic.h"
class CInput : public CDialog
{
	DECLARE_DYNAMIC(CInput)

public:
	CInput(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInput();
	int key;
	int key1;
	int m_inputType;
	paintpic drawpic;
	CString m_str;
	BOOL m_capsLock;
	//CButton m_numberButton[10];
	CMyBitmapButton* m_charButton[51];
	CMyBitmapButton* m_funButton[7];
	CMyBitmapButton	m_testbutton;
	//CStatic*	m_edit;
	CEdit*	m_edit;
	CBitmap bitmap;
// 对话框数据
	enum { IDD = IDD_INPUTDIALOG };

private:
	bool m_isPassword;

	void setDisplayInformation(const CString &str);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	inline void set_str(CString str){m_str = str;}
	inline CString get_str(){return m_str;}
	void Init(void);
	void DeInit(void);
	void setPasswordType(bool isPassword) { m_isPassword = isPassword; }
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void point_analysis(POINT point);
};
