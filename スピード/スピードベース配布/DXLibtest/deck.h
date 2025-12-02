#pragma once
#include "function.h"

class Deck
{
private:
	vector<CARD> cards;
public:
	Deck();
	void DeckSet(int, int);
	CARD CardGet();
};