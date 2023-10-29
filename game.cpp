//===============================================
//タイトル制御[gameover.cpp]
//Date:2023/09/05	Auther:林祐也
//===============================================
#include "obj.h"
#include "game.h"
#include "player.h"

//-------------------------------------
//変数宣言
//-------------------------------------
Player *pPlayer;

//コンストラクタ
Game::Game()
{
	//インスタンス化
	pPlayer = new Player();
}
//デストラクタ
Game::~Game()
{
	//動的の解放
	delete pPlayer;
}
//更新処理
void Game::Update(void)
{
	pPlayer->Update();
}
//描画処理
void Game::Draw(void)
{
	pPlayer->Draw();
}
