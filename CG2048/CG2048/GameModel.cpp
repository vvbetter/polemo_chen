#include "stdafx.h"
#include "GameModel.h"


CGameModel::CGameModel()
{
	showCount = 0;
	m_strData.RemoveAll();
}


CGameModel::~CGameModel()
{
}

int CGameModel::AddData(strData md)
{
	int ret = -1;
	ret = m_strData.Add(md);
	if (ret != -1)
	{
		showCount++;
	}
	return ret;
}

void CGameModel::showBoxByRand()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 2; i++)
	{
		int randId = rand()%getShowCount();
		bool ret = initRandomData(randId);
	}
}

bool CGameModel::initRandomData(int index)
{
	int dataCount = m_strData.GetCount();
	int tempIndex = 0;
	for (int i = 0; i < dataCount; i++)
	{
		if (m_strData[i].grade == 0)
		{
			tempIndex++;
			if (tempIndex == index)
			{
				m_strData[i].grade = 2;
				m_strData[i].r = 255;
				m_strData[i].g = 0;
				m_strData[i].b = 0;
			}			
		}
	}
	UpdateData();
	return true;
}

bool CGameModel::UpdateData()
{
	CString ss;
	int dataCount = m_strData.GetCount();
	for (int i = 0; i < dataCount; i++)
	{
		if (m_strData[i].grade != 0)
		{
			m_strData[i].pButton->ShowWindow(SW_SHOW);
			ss.Format(L"%d", m_strData[i].grade);
			m_strData[i].pButton->SetWindowTextW(ss);
		}
		else
		{
			m_strData[i].pButton->ShowWindow(SW_HIDE);
		}
	}
	InvalidateRect(AfxGetMainWnd()->m_hWnd, NULL, false);
	return true;
}

int CGameModel::getShowCount()
{
	int dataCount = m_strData.GetCount();
	int tempCount = 0;
	for (int i = 0; i < dataCount; i++)
	{
		if (m_strData[i].grade == 0)
		{
			tempCount++;
		}
	}
	showCount = tempCount;
	return tempCount;
}