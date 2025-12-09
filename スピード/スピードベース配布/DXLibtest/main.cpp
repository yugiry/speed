#pragma once
#include "DxLib.h"
#include "function.h"

#include "player.h"
#include "cpu.h"
#include "master.h"
#include "area.h"

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

	Master GM;

	Player player;
	Cpu cpu;
	Area area;

	area.AreaSet(player, cpu);

	while (1) 
	{
		//裏画面のデータを全て削除
		ClearDrawScreen();

		//処理----------------------------------------------------------------



		GM.Action(area, player, cpu);
		player.Action(area);
		cpu.Action(area);

#pragma region 画像処理

		GM.Draw();
		area.AreaDraw();
		player.CardDraw();
		cpu.CardDraw();

#pragma endregion
		//--------------------------------------------------------------------

		ScreenFlip(); //裏画面データを表画面へ反映

		//毎ループ呼び出す。エラーになった場合breakする
		if (ProcessMessage() == -1)break;
		//エスケープキーを押したり、エラーになった場合、breakする
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
	}

	WaitKey();	 //キー入力待ち
	DxLib_End(); //DXライブラリ使用の終了処理
	return 0;
}