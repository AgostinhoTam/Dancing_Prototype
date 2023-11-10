//===============================================
//タイトル制御[gameover.cpp]
//Date:2023/09/05	Auther:林祐也
//===============================================
#include "obj.h"
#include "game.h"
#include "player.h"
#include "input.h"

#define	USE_KEYBOARD

//-------------------------------------
//変数宣言
//-------------------------------------
//Player *pPlayer;

//コンストラクタ
Game::Game()
{
	//インスタンス化
	//pPlayer = new Player();
	pNotes = new Notes();
	pJF = new JudgmentFrame();
	NJ = new NotesJudge();
}
//デストラクタ
Game::~Game()
{
	//動的の解放
	//delete pPlayer;
	delete pNotes;
	delete pJF;
	delete NJ;
}
//更新処理
void Game::Update(void)
{
	//pPlayer->Update();
	pNotes->Update();
	pJF->Update();
	NJ->Update();
	SetCnt(GetCnt() + 1);

	if (GetCnt() == 10 || GetCnt() == 500 || GetCnt() == 1000)
	{
		NJ->SetFlag(true);
	}

}
//描画処理
void Game::Draw(void)
{
	//pPlayer->Draw();
	pNotes->Draw();
	pJF->Draw();
	NJ->Draw();
}
