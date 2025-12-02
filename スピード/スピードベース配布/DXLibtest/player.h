#pragma once
#include "function.h"
#include "deck.h"

class Player:public Deck
{
private:
	int gh_card;
	int grab_num;
	bool grab_hand;

	CARD hands[4];
	Point mouse;
public:
	Player();
	void Action();
	void CardDraw();
};