#pragma once
#include "function.h"

class Area
{
private:
	int gh_area{ -1 };
	int gh_card{ -1 };
	CARD areas[2];
public:
	Area();
	~Area();
	void AreaDraw();
	int RightAreaNumGet();
	int LeftAreaNumGet();
	void RightAreaSet(CARD);
	void LeftAreaSet(CARD);
};