#pragma once
#include "function.h"
#include "player.h"
#include "cpu.h"
#include "area.h"

class Master
{
private:
	int gh_back{ -1 };
	int restart_time{ 0 };
	bool game_stop{ false };
	int win{ 0 };//1->ƒvƒŒƒCƒ„[A2->‚b‚o‚t

	enum WIN
	{
		PLAYER = 1,
		CPU
	};
public:
	Master();
	~Master();
	bool Action(Area&, Player&, Cpu&);
	void Draw();
	bool CheckRightArea(Area&, Player&, Cpu&);
	bool CheckLeftArea(Area&, Player&, Cpu&);
	void PlayerWin();
	void CpuWin();
	void DrawWin();
};