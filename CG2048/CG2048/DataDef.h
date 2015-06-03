#include"stdafx.h"
struct strData
{
	CButton* pButton;
	int grade;
	WORD r;
	WORD g;
	WORD b;
	strData(){}
	strData(CButton*p, int ig=0, WORD wr=0, WORD wg=0, WORD wb=0){
		pButton = p;
		grade = ig;
		r = wr;
		g = wg;
		b = wb;
	}
};