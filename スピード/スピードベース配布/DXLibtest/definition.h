#pragma once
using namespace std;

#pragma region 定数定義
//ゲーム画面の大きさ
constexpr int WINDOW_WIDTH = 720;
constexpr int WINDOW_HEIGHT = 640;
//カード一枚の大きさ
constexpr int CARD_WIDTH = 64;
constexpr int CARD_HEIGHT = 92;
//エリアの大きさ
constexpr int AREA_WIDTH = 70;
constexpr int AREA_HEIGHT = 98;
//プレイヤー側の１枚目のカードを置く位置
constexpr int PLAYER_CARD_START_X = WINDOW_WIDTH / 2 - CARD_WIDTH / 2 - AREA_WIDTH * 3 / 2;
constexpr int PLAYER_CARD_START_Y = WINDOW_HEIGHT / 2 + CARD_HEIGHT / 2 + 50;
//ＣＰＵ側の１枚目のカードを置く位置
constexpr int CPU_CARD_START_X = WINDOW_WIDTH / 2 + CARD_WIDTH + 15;
constexpr int CPU_CARD_START_Y = WINDOW_HEIGHT / 2 - CARD_HEIGHT * 3 / 2 - 50;
//手札にあるカードの間隔
constexpr int CARD_SPACE = 10;
//画像のトランプの数
constexpr int CHORI_NUM = 13;
constexpr int CVER_NUM = 4;
//デッキ枚数
constexpr int DECK_NUM = 26;
//手札の枚数
constexpr int HAND_NUM = 4;

constexpr int thinking_interval = 120;

#pragma endregion

#pragma region 構造体定義
typedef struct Point
{
	int x, y;
}Point;

typedef struct Vector
{
	int x, y;
}Vector;

typedef struct CARD {
	Point pos{ 0,0 };
	int num{ -1 };
	bool oncard{ false };
}CARD;

#pragma endregion