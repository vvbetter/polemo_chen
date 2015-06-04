#pragma once

#include"stdafx.h"
struct strData
{
	CButton* pButton;
	int grade;
	WORD r;
	WORD g;
	WORD b;
	strData(){
		pButton = NULL;
		grade = 0;
		r = 0;
		g = 0;
		b = 0;
	}
	strData(CButton* p, int gt = 0, int tr = 0, int tg = 0, int tb = 0)
	{
		pButton = p;
		grade = gt;
		r = tr;
		g = tg;
		b = tb;
	}
};