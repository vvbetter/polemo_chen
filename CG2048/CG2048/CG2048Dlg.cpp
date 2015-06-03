
// CG2048Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CG2048.h"
#include "CG2048Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCG2048Dlg �Ի���



CCG2048Dlg::CCG2048Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCG2048Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCG2048Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCG2048Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CHAR()
END_MESSAGE_MAP()


// CCG2048Dlg ��Ϣ�������

BOOL CCG2048Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	InitDataModel();
	this->SetFocus();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCG2048Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCG2048Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCG2048Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCG2048Dlg::InitDataModel()
{
	int ret = -1;
	for (int i = IDC_1; i <= IDC_16; i++)
	{
		CButton* pButton = (CButton*)GetDlgItem(i);
		ASSERT(pButton != NULL);
		strData m_data(pButton);
		pButton->SetWindowTextW(L"0");
		pButton->ShowWindow(SW_SHOW);
		m_data.pButton = pButton;
		m_pData.Add(m_data);
	}
}


void CCG2048Dlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString ss=L"abcdefg";
	switch (nChar)
	{
	case 'a':
	case 'A':
		UserLeft();
		break;
	case 's':
	case 'S':
		UserDown();
		break;
	case 'd':
	case 'D':
		UserRight();
		break;
	case 'w':
	case 'W':
		UserUp();
		break;
	default:
		break;
	}

	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
}


BOOL CCG2048Dlg::PreTranslateMessage(MSG* pMsg)
{
	 //todo:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_CHAR)
	{
		pMsg->hwnd = m_hWnd;

		return false;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CCG2048Dlg::UserDown()
{

}

void CCG2048Dlg::UserUp()
{

}

void CCG2048Dlg::UserRight()
{

}

void CCG2048Dlg::UserLeft()
{

}