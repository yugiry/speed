#pragma once
#include "function.h"
#include "deck.h"
#include "area.h"

class Cpu :public Deck
{
private:
	int gh_card{ -1 };

	CARD hands[4];
public:
	Cpu();
	~Cpu();
	void Action(Area&);
	void CardDraw();
	int HandsCardNum(int);
};