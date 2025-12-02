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

void Player::Action()
{
	//マウスカーソルの位置を取得
	GetMousePoint(&mouse.x, &mouse.y);

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (mouse.x > hands[i].pos.x && mouse.x < hands[i].pos.x + CARD_WIDTH && mouse.y > hands[i].pos.y && mouse.y < hands[i].pos.y + CARD_HEIGHT)
			{
				grab_hand = true;
				grab_num = i;
			}
		}
	}
	else
	{
		grab_hand = false;
	}

	if (grab_hand)
	{

	}
}

void Player::CardDraw()
{
	for (int i = 0; i < 4; i++)
		DrawRectGraph(hands[i].pos.x, hands[i].pos.y, (hands[i].num % 13) * CARD_WIDTH, (hands[i].num / 13) * CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, gh_card, true);
}