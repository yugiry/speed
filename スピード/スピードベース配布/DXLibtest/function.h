#pragma once

#pragma region íËêî
constexpr int WINDOW_WIDTH = 720;
constexpr int WINDOW_HEIGHT = 640;
constexpr int CARD_WIDTH = 64;
constexpr int CARD_HEIGHT = 92;
constexpr int AREA_WIDTH = 70;
constexpr int AREA_HEIGHT = 98;
constexpr int PLAYER_CARD_START_X = WINDOW_WIDTH / 2 - AREA_WIDTH * 2;
constexpr int PLAYER_CARD_START_Y = WINDOW_HEIGHT / 2 + CARD_HEIGHT;
constexpr int CPU_CARD_START_X = 0;
constexpr int CPU_CARD_START_Y = 0;
constexpr int CARD_SPACE = 10;

#pragma endregion

#pragma region ç\ë¢ëÃ
typedef struct Point
{
	int x;
	int y;
};

typedef struct CARD
{
	Point pos;
	int num;
};

#pragma endregion
