#pragma once
#include "master.h"

Master::Master()
{
	gh_back = LoadGraph("image\\back.png");
}

void Master::Action(Area& a, Player& p, Cpu& c)
{
	//勝敗判定
	{
		if (p.CheckHands())
		{
			//プレイヤー勝利
			PlayerWin();
		}
		if (c.CheckHands())
		{
			//ＣＰＵ勝利
			CpuWin();
		}
	}

	if (game_stop)
	{
		
	}
	if (!game_stop)
	{
		//プレイヤーとＣＰＵが手札からトランプを出せるか
		if (CheckRightArea(a, p, c) && CheckLeftArea(a, p, c))
		{
			restart_time++;
		}

		if (restart_time > 300)
		{
			//プレイヤーのデッキが残っているか
			if (p.DeckCheck())
			{
				//デッキからトランプを取る
				a.RightAreaSet(p.CardGet());
			}
			else
			{
				//手札からトランプを取る
				a.RightAreaSet(p.GetHandCard());
			}
			//ＣＰＵのデッキが残っているか
			if (c.DeckCheck())
			{
				//デッキからトランプを取る
				a.LeftAreaSet(c.CardGet());
			}
			else
			{
				//手札からトランプを取る
				a.LeftAreaSet(c.GetHandCard());
			}
			restart_time = 0;
			a.OnPutFlag();
		}
	}
}

void Master::Draw()
{
	DrawGraph(0, 0, gh_back, true);
}

bool Master::CheckRightArea(Area& a, Player& p, Cpu& c)
{
	int tmp = 0;
	int areanum = a.RightAreaNumGet() % 13;
	for (int i = 0; i < 4; i++)
	{
		int handnum = p.HandsCardNum(i) % 13;
		if (handnum + 1 == areanum || handnum - 1 == areanum || (handnum == 12 && areanum == 0) || (handnum == 0 && areanum == 12))
		{
			tmp++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int handnum = c.HandsCardNum(i) % 13;
		if (handnum + 1 == areanum || handnum - 1 == areanum || (handnum == 12 && areanum == 0) || (handnum == 0 && areanum == 12))
		{
			tmp++;
		}
	}

	if (tmp > 0)
	{
		//まだ出せる
		return false;
	}
	else
	{
		//出せない
		return true;
	}
}

bool Master::CheckLeftArea(Area& a, Player& p, Cpu& c)
{
	int tmp = 0;
	int areanum = a.LeftAreaNumGet() % 13;
	for (int i = 0; i < 4; i++)
	{
		int handnum = p.HandsCardNum(i) % 13;
		if (handnum + 1 == areanum || handnum - 1 == areanum || (handnum == 12 && areanum == 0) || (handnum == 0 && areanum == 12))
		{
			tmp++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int handnum = c.HandsCardNum(i) % 13;
		if (handnum + 1 == areanum || handnum - 1 == areanum || (handnum == 12 && areanum == 0) || (handnum == 0 && areanum == 12))
		{
			tmp++;
		}
	}

	if (tmp > 0)
	{
		//まだ出せる
		return false;
	}
	else
	{
		//出せない
		return true;
	}
}

void Master::PlayerWin()
{
	game_stop = true;
}

void Master::CpuWin()
{
	game_stop = true;
}

Master::~Master()
{
	DeleteGraph(gh_back);
}