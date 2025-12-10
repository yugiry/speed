#pragma once
#include "area.h"

Area::Area()
{
	gh_area = LoadGraph("image\\area.png");
	gh_card = LoadGraph("image\\card.png");
}

void Area::AreaSet(Player& p, Cpu& c)
{
	areas[0] = p.CardGet();
	areas[1] = c.CardGet();
	areas[0].pos = { RIGHTAREACARD_POSITION_X, RIGHTAREACARD_POSITION_Y };
	areas[1].pos = { LEFTAREACARD_POSITION_X, LEFTAREACARD_POSITION_Y };
}

void Area::AreaDraw()
{
	//‰E‘¤
	DrawGraph(RIGHTAREA_POSITION_X, RIGHTAREA_POSITION_Y, gh_area, true);
	//¶‘¤
	DrawGraph(LEFTAREA_POSITION_X, LEFTAREA_POSITION_Y, gh_area, true);

	if (areas[0].num >= 0)
		DrawRectGraph(areas[0].pos.x, areas[0].pos.y, (areas[0].num % 13) * CARD_WIDTH, (areas[0].num / 13) * CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, gh_card, true);
	if (areas[1].num >= 0)
		DrawRectGraph(areas[1].pos.x, areas[1].pos.y, (areas[1].num % 13) * CARD_WIDTH, (areas[1].num / 13) * CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, gh_card, true);

}

int Area::RightAreaNumGet()
{
	return areas[0].num;
}

int Area::LeftAreaNumGet()
{
	return areas[1].num;
}

void Area::RightAreaSet(CARD c)
{
	areas[0].num = c.num;
}

void Area::LeftAreaSet(CARD c)
{
	areas[1].num = c.num;
}

bool Area::CheckPutFlag()
{
	return card_put;
}

void Area::OnPutFlag()
{
	card_put = true;
}

void Area::OffPutFlag()
{
	card_put = false;
}

Area::~Area()
{
	DeleteGraph(gh_card);
	DeleteGraph(gh_area);
}