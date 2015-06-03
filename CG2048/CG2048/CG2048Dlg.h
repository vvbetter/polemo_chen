
// CG2048Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "DataDef.h"


// CCG2048Dlg 对话框
class CCG2048Dlg : public CDialogEx
{
// 构造
public:
	CCG2048Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CG2048_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void InitDataModel();
	void UserLeft();
	void UserRight();
	void UserUp();
	void UserDown();
private:
	CArray<strData> m_pData;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
