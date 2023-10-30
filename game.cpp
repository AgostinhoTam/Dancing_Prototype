//===============================================
//タイトル制御[gameover.cpp]
//Date:2023/09/05	Auther:林祐也
//===============================================
#include "obj.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include <vector>
#include "Texture.h"
#define ENEMY_NUM (100)

//-------------------------------------
//変数宣言
//-------------------------------------
Player *pPlayer;
std::vector<Enemy> EnemyList;

//コンストラクタ
Game::Game()
{
	
	//インスタンス化
	pPlayer = new Player();
	for (int i = 0; i < ENEMY_NUM;i++) 
	{
		EnemyList.push_back(Enemy());

	}
}
//デストラクタ
Game::~Game()
{
	//動的の解放
	delete pPlayer;
	EnemyList.clear();
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
