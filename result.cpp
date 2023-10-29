//===============================================
//タイトル制御[result.cpp]
//Date:2023/07/31	Auther:林祐也
//===============================================
#include "result.h"
#include "input.h"
#include "resultBG.h"
#include "gameclear.h"
#include "gameover.h"

ResultBG* pResultBG;
GameClear* pGameClear;
GameOver* pGameOver;
//=============================================================================
// 初期化処理
//=============================================================================
Result::Result()
{
	pResultBG = new ResultBG();
}

//=============================================================================
// 終了処理
//=============================================================================
Result::~Result()
{
	delete pResultBG;
	//if (GetBattleWinner() == 2)//敵が勝った時
	//{
	//	delete pGameOver;
	//}
	//if (GetBattleWinner() == 1)//プレイヤーが勝った時
	//{
	//	delete pGameCrear;
	//}
}

//=============================================================================
// 更新処理
//=============================================================================
void Result::Update()
{
	SetCnt(GetCnt() + 1);
	if (GetCnt() == 1)
	{
		//if (GetBattleWinner() == 2)//敵が勝った時
		//{
		//	pGameOver = new GameOver();
		//}
		//if (GetBattleWinner() == 1)//プレイヤーが勝った時
		//{
		//	pGameCrear = new GameCrear();
		//}
	}

	pResultBG->Update();
	if (GetCnt() > 2)
	{
		//if (GetBattleWinner() == 2)//敵が勝った時
		//{
		//	pGameOver->Update();
		//}
		//if (GetBattleWinner() == 1)//プレイヤーが勝った時
		//{
		//	pGameCrear->Update();
		//}
		//if (GetKeyboardTrigger(DIK_RETURN))
		//{
		//	SetScene(SCENE_TITLE);
		//}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void Result::Draw(void)
{
	pResultBG->Draw();
	if (GetCnt() >= 2)
	{
		//if (GetBattleWinner() == 2)//敵が勝った時
		//{
		//	pGameOver->Draw();
		//}
		//if (GetBattleWinner() == 1)//プレイヤーが勝った時
		//{
		//	pGameCrear->Draw();
		//}
	}
}