#pragma once
#include "deck.h"
#include <random>

Deck::Deck()
{

}

void Deck::DeckSet(int num, int s = 0)
{
	CARD tmp;
	//numの数だけデッキに追加する
	for (int i = s; i < s + num; i++)
	{
		tmp.num = i;
		cards.push_back(tmp);
	}

	//デッキをランダムにする
	int a = GetRand(num);
	mt19937 rd(a);
	shuffle(cards.begin(), cards.end(), rd);
}

CARD Deck::CardGet()
{
	CARD tmp;

	tmp = cards[0];
	cards.erase(cards.begin());

	return tmp;
}

bool Deck::DeckCheck()
{
	if (cards.size() > 0)
	{
		return true;
	}

	return false;
}