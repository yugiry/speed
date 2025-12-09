#pragma once
#include "cpu.h"

Cpu::Cpu()
{
	gh_card = LoadGraph("image\\card.png");

	//ＣＰＵのデッキをセット
	DeckSet(DECK_MAX, 26);

	for (int i = 0; i < 4; i++)
	{
		hands[i] = CardGet();
		hands[i].pos = { CPU_CARD_START_X + (CARD_WIDTH + CARD_SPACE) * i,CPU_CARD_START_Y };
	}
}

void Cpu::Action(Area& area)
{
	action_time++;

	if (action_time > 120)
	{
		//手札のトランプがエリアに置けるか調べる
		for (int i = 0; i < 4; i++)
		{
			int left = area.LeftAreaNumGet();
			int right = area.RightAreaNumGet();
			left = left % 13;
			right = right % 13;
			int tmp = hands[i].num % 13;

			//
			if ((tmp == left + 1 || tmp == left - 1 || (tmp == 12 && left == 0) || (tmp == 0 && left == 12)) && !draw_card)
			{
				area.LeftAreaSet(hands[i]);
				hands[i] = CardGet();
				hands[i].pos = { CPU_CARD_START_X + (CARD_WIDTH + CARD_SPACE) * i,CPU_CARD_START_Y };
				draw_card = true;
			}
			if ((tmp == right + 1 || tmp == right - 1 || (tmp == 12 && right == 0) || (tmp == 0 && right == 12)) && !draw_card)
			{
				area.RightAreaSet(hands[i]);
				hands[i] = CardGet();
				hands[i].pos = { CPU_CARD_START_X + (CARD_WIDTH + CARD_SPACE) * i,CPU_CARD_START_Y };
				draw_card = true;
			}

			if (draw_card)break;
		}
		draw_card = false;
		action_time = 0;
	}
}

void Cpu::CardDraw()
{
	for (int i = 0; i < 4; i++)
	{
		if (hands[i].num != -1)
			DrawRectGraph(hands[i].pos.x, hands[i].pos.y, (hands[i].num % 13) * CARD_WIDTH, (hands[i].num / 13) * CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, gh_card, true);
	}

	if (DeckCheck())
	{
		DrawRectGraph(CPU_DECK_X, CPU_DECK_Y, 0, CARD_HEIGHT * 4, CARD_WIDTH, CARD_HEIGHT, gh_card, true);
	}
}

int Cpu::HandsCardNum(int n)
{
	return hands[n].num;
}

Cpu::~Cpu()
{
	DeleteGraph(gh_card);
}