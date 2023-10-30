//===============================================
//�^�C�g������[gameover.cpp]
//Date:2023/09/05	Auther:�їS��
//===============================================
#include "obj.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include <vector>
#include "Texture.h"
#define ENEMY_NUM (100)

//-------------------------------------
//�ϐ��錾
//-------------------------------------
Player *pPlayer;
std::vector<Enemy> EnemyList;

//�R���X�g���N�^
Game::Game()
{
	
	//�C���X�^���X��
	pPlayer = new Player();
	for (int i = 0; i < ENEMY_NUM;i++) 
	{
		EnemyList.push_back(Enemy());

	}
}
//�f�X�g���N�^
Game::~Game()
{
	//���I�̉��
	delete pPlayer;
	EnemyList.clear();
}
//�X�V����
void Game::Update(void)
{
	pPlayer->Update();

}
//�`�揈��
void Game::Draw(void)
{
	pPlayer->Draw();
}
