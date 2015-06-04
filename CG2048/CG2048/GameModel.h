#pragma once
#include"stdafx.h"
#include"DataDef.h"

class CGameModel
{
public:
	CGameModel();
	~CGameModel();
public:
	int AddData(strData md);
	void showBoxByRand();
	bool initRandomData(int index);
	bool UpdateData();
	int getShowCount();
private:
	CArray<strData> m_strData;
	int showCount;
};

