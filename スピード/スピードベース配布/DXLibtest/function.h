#pragma once
#include "DxLib.h"
#include <vector>

using namespace std;

#pragma region 定数
//画面の大きさ
constexpr int WINDOW_WIDTH = 720;
constexpr int WINDOW_HEIGHT = 640;
//トランプの大きさ
constexpr int CARD_WIDTH = 64;
constexpr int CARD_HEIGHT = 92;
//エリアの大きさ
constexpr int AREA_WIDTH = 70;
constexpr int AREA_HEIGHT = 98;
//プレイヤーの手札の配置場所
constexpr int PLAYER_CARD_START_X = WINDOW_WIDTH / 2 - AREA_WIDTH * 2;
constexpr int PLAYER_CARD_START_Y = WINDOW_HEIGHT / 2 + CARD_HEIGHT;
//ＣＰＵの手札の配置場所
constexpr int CPU_CARD_START_X = WINDOW_WIDTH / 2 - AREA_WIDTH * 2;
constexpr int CPU_CARD_START_Y = WINDOW_HEIGHT / 2 - CARD_HEIGHT * 2;
//手札を配置するときのトランプの間隔
constexpr int CARD_SPACE = 10;
//プレイヤーの山札の配置場所
constexpr int PLAYER_DECK_X = PLAYER_CARD_START_X + (CARD_WIDTH + CARD_SPACE) * 3 + CARD_WIDTH * 2;
constexpr int PLAYER_DECK_Y = PLAYER_CARD_START_Y;
//ＣＰＵの山札の配置場所
constexpr int CPU_DECK_X = CPU_CARD_START_X - CARD_WIDTH * 2;
constexpr int CPU_DECK_Y = WINDOW_HEIGHT / 2 - CARD_HEIGHT * 2;
//エリアの配置場所
constexpr int RIGHTAREA_POSITION_X = WINDOW_WIDTH / 2 + AREA_WIDTH / 2;
constexpr int RIGHTAREA_POSITION_Y = WINDOW_HEIGHT / 2 - AREA_HEIGHT / 2;
constexpr int LEFTAREA_POSITION_X = WINDOW_WIDTH / 2 - AREA_WIDTH - AREA_WIDTH / 2;
constexpr int LEFTAREA_POSITION_Y = WINDOW_HEIGHT / 2 - AREA_HEIGHT / 2;
//エリアのトランプの配置場所
constexpr int RIGHTAREACARD_POSITION_X = WINDOW_WIDTH / 2 + CARD_WIDTH / 2 + 6;
constexpr int RIGHTAREACARD_POSITION_Y = WINDOW_HEIGHT / 2 - CARD_HEIGHT / 2;
constexpr int LEFTAREACARD_POSITION_X = WINDOW_WIDTH / 2 - CARD_WIDTH * 3 / 2 - 6;
constexpr int LEFTAREACARD_POSITION_Y = WINDOW_HEIGHT / 2 - CARD_HEIGHT / 2;
//デッキの最大数
constexpr int DECK_MAX = 26;

#pragma endregion

#pragma region 構造体
typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct Vector
{
	int x;
	int y;
}Vector;

typedef struct CARD
{
	Point pos;
	int num;
}CARD;

#pragma endregion
