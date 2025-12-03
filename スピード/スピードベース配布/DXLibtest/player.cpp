#pragma once
#include "player.h"

Player::Player()
{
	gh_card = LoadGraph("image\\card.png");

	//プレイヤーのデッキをセット
	DeckSet(DECK_MAX, 0);

	for (int i = 0; i < 4; i++)
	{
		hands[i] = CardGet();
		hands[i].pos = { PLAYER_CARD_START_X + (CARD_WIDTH + CARD_SPACE) * i,PLAYER_CARD_START_Y };
	}
}

void Player::Action(Area& area)
{
	//マウスカーソルの位置を取得
	GetMousePoint(&mouse.x, &mouse.y);

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			//クリック中にマウスがトランプの上ならトランプを掴む
			if (mouse.x > hands[i].pos.x && mouse.x < hands[i].pos.x + CARD_WIDTH && mouse.y > hands[i].pos.y && mouse.y < hands[i].pos.y + CARD_HEIGHT && grab_num == -1)
			{
				grab_hand = true;
				grab_num = i;
				mc_vec = { hands[i].pos.x - mouse.x,hands[i].pos.y - mouse.y };
			}
		}
	}
	else if(grab_num >= 0)
	{
		//エリアの範囲で離したら
		//右側
		if (mouse.x > RIGHTAREA_POSITION_X && mouse.x < RIGHTAREA_POSITION_X + AREA_WIDTH && mouse.y > RIGHTAREA_POSITION_Y && mouse.y < RIGHTAREA_POSITION_Y + AREA_HEIGHT)
		{
			int areanum = area.RightAreaNumGet() % 13;
			int grabnum = hands[grab_num].num % 13;
			//持っているトランプがエリアにあるトランプの数字の前後であるか
			if (grabnum + 1 == areanum || grabnum - 1 == areanum || (areanum == 12 && grabnum == 0) || (areanum == 0 && grabnum == 12))
			{
				area.RightAreaSet(hands[grab_num]);
				if (DeckCheck())
					hands[grab_num] = CardGet();
				else
					hands[grab_num].num = -1;
			}
		}
		//左側
		if (mouse.x > LEFTAREA_POSITION_X && mouse.x < LEFTAREA_POSITION_X + AREA_WIDTH && mouse.y > LEFTAREA_POSITION_Y && mouse.y < LEFTAREA_POSITION_Y + AREA_HEIGHT)
		{
			int areanum = area.LeftAreaNumGet() % 13;
			int grabnum = hands[grab_num].num % 13;
			//持っているトランプがエリアにあるトランプの数字の前後であるか
			if (grabnum + 1 == areanum || grabnum - 1 == areanum || (areanum == 12 && grabnum == 0) || (areanum == 0 && grabnum == 12))
			{
				area.LeftAreaSet(hands[grab_num]);
				if (DeckCheck())
					hands[grab_num] = CardGet();
				else
					hands[grab_num].num = -1;
			}
		}

		//トランプを元の場所に戻す
		hands[grab_num].pos = { PLAYER_CARD_START_X + (CARD_WIDTH + CARD_SPACE) * grab_num,PLAYER_CARD_START_Y };
		grab_hand = false;
		grab_num = -1;
	}

	if (grab_hand && grab_num >= 0)
	{
		hands[grab_num].pos.x = mouse.x + mc_vec.x;
		hands[grab_num].pos.y = mouse.y + mc_vec.y;
	}
}

void Player::CardDraw()
{
	for (int i = 0; i < 4; i++)
	{
		if (hands[i].num != -1)
			DrawRectGraph(hands[i].pos.x, hands[i].pos.y, (hands[i].num % 13) * CARD_WIDTH, (hands[i].num / 13) * CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, gh_card, true);
	}

	if (DeckCheck())
	{
		DrawRectGraph(PLAYER_DECK_X, PLAYER_DECK_Y, 0, CARD_HEIGHT * 4, CARD_WIDTH, CARD_HEIGHT, gh_card, true);
	}
}

int Player::HandsCardNum(int n)
{
	return hands[n].num;
}

Player::~Player()
{
	DeleteGraph(gh_card);
}