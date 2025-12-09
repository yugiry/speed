#pragma once
#include "function.h"
#include "player.h"
#include "cpu.h"

class Player;
class Cpu;

class Area
{
private:
	int gh_area{ -1 };
	int gh_card{ -1 };
	CARD areas[2];
public:
	Area();
	~Area();
	void AreaSet(Player&, Cpu&);
	void AreaDraw();
	int RightAreaNumGet();
	int LeftAreaNumGet();
	void RightAreaSet(CARD);
	void LeftAreaSet(CARD);
};