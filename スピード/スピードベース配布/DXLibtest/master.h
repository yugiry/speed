#pragma once
#include "function.h"
#include "player.h"
#include "cpu.h"
#include "area.h"

class Master
{
private:
	int gh_back{ -1 };
public:
	Master();
	~Master();
	void Action(Area&, Player&, Cpu&);
	void Draw();
	void CheckRightArea(Area&, Player&, Cpu&);
	void CheckLeftArea(Area&, Player&, Cpu&);
};