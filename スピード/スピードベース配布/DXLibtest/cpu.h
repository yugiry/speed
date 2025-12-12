#pragma once
#include "function.h"
#include "deck.h"
#include "area.h"

class Area;
class Cpu :public Deck
{
private:
	int gh_card{ -1 };
	int action_time{ 0 };
	bool draw_card{ false };

	CARD hands[4];
public:
	Cpu();
	~Cpu();
	void Action(Area&);
	void CardDraw();
	int HandsCardNum(int);
	CARD GetHandCard();
	bool CheckHands();
};