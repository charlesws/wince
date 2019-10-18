#pragma once
#include "afxcmn.h"
#include "Common.h"

// MainDialog 对话框

class MainDialog : public CDialog
{
	DECLARE_DYNAMIC(MainDialog)

public:
	MainDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MainDialog();

	Common m_com;
// 对话框数据
	enum { IDD = IDD_MAIN };
	void UpdateList();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedmodify();
	afx_msg void OnBnClickeddelete();
	afx_msg void OnBnClickedButton3();
};
