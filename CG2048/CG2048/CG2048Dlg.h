
// CG2048Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "DataDef.h"
#include "GameModel.h"


// CCG2048Dlg �Ի���
class CCG2048Dlg : public CDialogEx
{
// ����
public:
	CCG2048Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CG2048_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	CGameModel m_gm;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
