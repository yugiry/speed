#pragma once
#include "function.h"
#include "deck.h"
#include "area.h"

class Area;
class Player:public Deck
{
private:
	int gh_card{ -1 };
	int grab_num{ -1 };
	bool grab_hand{ false };

	CARD hands[4];
	Point mouse{ 0,0 };
	Vector mc_vec{ 0,0 };
public:
	Player();
	~Player();
	void Action(Area& );
	void CardDraw();
	int HandsCardNum(int);
	CARD GetHandCard();
	bool CheckHands();
};