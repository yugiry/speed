#include "DxLib.h"
#include <vector>

using namespace std;

//定数定義--------------------------------------------------------------
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

typedef struct Point
{
	int x, y;
}Point;

typedef struct Vector
{
	int x, y;
}Vector;

class CARD
{
private:
	Point pos;
	int num;
public:
	CARD();
};

class DECK :public CARD
{
private:
	vector<CARD> cards;
public:
	DECK();
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetOutApplicationLogValidFlag(false);//ログ出力オフ
	ChangeWindowMode(TRUE); //ウィンドウモード切り替え
	SetGraphMode(720,640, 32); //ウィンドウサイズ

	if (DxLib_Init() == -1) { //DXライブラリ初期化処理
		return -1;			  //エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に変更
	SetWindowText("speed"); //ウィンドウの名前

	//画像---------------------
	int gh_back;//背景
	int i_card;//トランプ
	int area;//エリア
	//画像読み込み
	gh_back = LoadGraph("image\\back.png");
	i_card = LoadGraph("image\\card.png");
	area = LoadGraph("image\\area.png");

	//画像の分割読み込み
	//LoadDivGraph(画像ファイルポインタ、分割総数、横分割数、縦分割数、横サイズ、縦サイズ、保存配列ポインタ)
	//トランプの横サイズ：64、縦サイズ：92

	int mouseX, mouseY;//カーソル位置保存用

	//変数定義--------------------------------------------------------------
	Point PLAYER_CARD[4];
	Point CPU_CARD[4];
	Point AREA_POS[2];
	Vector CARD_Vec;
	bool click = false;
	int click_card = -1;
	int left_area = -1;
	int right_area = -1;

	//カードの初期位置を設定
	for (int i = 0; i < 4; i++)
	{
		PLAYER_CARD[i] = { PLAYER_CARD_START_X + i * (CARD_WIDTH + CARD_SPACE), PLAYER_CARD_START_Y };
		CPU_CARD[i] = { CPU_CARD_START_X - i * (CARD_WIDTH + CARD_SPACE), CPU_CARD_START_Y };
	}
	//エリアの初期位置
	AREA_POS[0] = { WINDOW_WIDTH / 2 - AREA_WIDTH / 2 - AREA_WIDTH, WINDOW_HEIGHT / 2 - AREA_HEIGHT / 2 };
	AREA_POS[1] = { WINDOW_WIDTH / 2 - AREA_WIDTH / 2 + AREA_WIDTH, WINDOW_HEIGHT / 2 - AREA_HEIGHT / 2 };

	while (1) 
	{
		//裏画面のデータを全て削除
		ClearDrawScreen();

		//処理----------------------------------------------------------------

		//マウスカーソルの位置を取得
		GetMousePoint(&mouseX, &mouseY);

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) && !click)
		{
			for (int i = 0; i < 4; i++)
			{
				//クリックした時にトランプの上にカーソルがある場合
				if (mouseX > PLAYER_CARD[i].x && mouseX < PLAYER_CARD[i].x + CARD_WIDTH && mouseY > PLAYER_CARD[i].y && mouseY < PLAYER_CARD[i].y + CARD_HEIGHT)
				{
					click_card = i;
					CARD_Vec = { PLAYER_CARD[i].x - mouseX,PLAYER_CARD[i].y - mouseY };
				}
			}
		}
		click = (GetMouseInput() & MOUSE_INPUT_LEFT);

		if (click && click_card != -1)
		{
			PLAYER_CARD[click_card].x = mouseX + CARD_Vec.x;
			PLAYER_CARD[click_card].y = mouseY + CARD_Vec.y;
		}
		if (!click && click_card != -1)
		{
			//左のエリアとの判定
			if (mouseX > AREA_POS[0].x && mouseX < AREA_POS[0].x + AREA_WIDTH && mouseY > AREA_POS[0].y && mouseY < AREA_POS[0].y + AREA_HEIGHT)
			{

			}
			//右のエリアとの判定
			else if (mouseX > AREA_POS[1].x && mouseX < AREA_POS[1].x + AREA_WIDTH && mouseY > AREA_POS[1].y && mouseY < AREA_POS[1].y + AREA_HEIGHT)
			{

			}
			else
			{
				PLAYER_CARD[click_card].x = PLAYER_CARD_START_X + click_card * (CARD_WIDTH + CARD_SPACE);
				PLAYER_CARD[click_card].y = PLAYER_CARD_START_Y;
				click_card = -1;
			}
		}

		//画像の描画(位置X、位置Y、グラフィックハンドル、透明度の有効無効)
		//背景
		DrawGraph(0, 0, gh_back, true);

		//エリアを配置
		for (int i = 0; i < 2; i++)
		{
			DrawGraph(AREA_POS[i].x, AREA_POS[i].y, area, true);
		}
		//エリアに置かれたカードの表示
		if (left_area != -1)
		{

		}
		if (right_area != -1)
		{

		}

		//手札カードの配置
		for (int i = 0; i < 4; i++)
		{
			//プレイヤーのカードを設置
			DrawRectGraph(PLAYER_CARD[i].x, PLAYER_CARD[i].y, 0, 0, CARD_WIDTH, CARD_HEIGHT, i_card, true);
			//ＣＰＵのカードを設置
			DrawRectGraph(CPU_CARD[i].x, CPU_CARD[i].y, 0, 0, CARD_WIDTH, CARD_HEIGHT, i_card, true);
		}

		//--------------------------------------------------------------------

		ScreenFlip(); //裏画面データを表画面へ反映

		//毎ループ呼び出す。エラーになった場合breakする
		if (ProcessMessage() == -1)break;
		//エスケープキーを押したり、エラーになった場合、breakする
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
	}

	//画像データ削除
	DeleteGraph(gh_back);

	WaitKey();	 //キー入力待ち
	DxLib_End(); //DXライブラリ使用の終了処理
	return 0;
}
