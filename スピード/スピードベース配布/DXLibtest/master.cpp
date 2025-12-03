#pragma once
#include "master.h"

Master::Master()
{
	gh_back = LoadGraph("image\\back.png");
}

void Master::Action(Area& a, Player& p, Cpu& c)
{
	//プレイヤーとＣＰＵがエリアにトランプを置けるか
	CheckRightArea(a, p, c);
	CheckLeftArea(a, p, c);
}

void Master::Draw()
{
	DrawGraph(0, 0, gh_back, true);
}

void Master::CheckRightArea(Area& a, Player& p, Cpu& c)
{
	int tmp = 0;
	int areanum = a.RightAreaNumGet();
	for (int i = 0; i < 4; i++)
	{
		int handnum = p.HandsCardNum(i);
		if (handnum + 1 != areanum && handnum - 1 != areanum && (handnum == 12 && areanum != 0) && (handnum == 0 && areanum != 12))
		{
			tmp++;
		}
	}

	if (tmp == 8)
	{

	}

}

void Master::CheckLeftArea(Area& a, Player& p, Cpu& c)
{
	int tmp = 0;
	int areanum = a.LeftAreaNumGet();
	for (int i = 0; i < 4; i++)
	{
		int handnum = p.HandsCardNum(i);
		if (handnum + 1 != areanum && handnum - 1 != areanum && (handnum == 12 && areanum != 0) && (handnum == 0 && areanum != 12))
		{
			tmp++;
		}
	}

	if (tmp == 4)
	{

	}
}

Master::~Master()
{
	DeleteGraph(gh_back);
}