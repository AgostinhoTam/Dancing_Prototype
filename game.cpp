//===============================================
//�^�C�g������[gameover.cpp]
//Date:2023/09/05	Auther:�їS��
//===============================================
#include "obj.h"
#include "game.h"
#include "player.h"

//-------------------------------------
//�ϐ��錾
//-------------------------------------
Player *pPlayer;

//�R���X�g���N�^
Game::Game()
{
	//�C���X�^���X��
	pPlayer = new Player();
}
//�f�X�g���N�^
Game::~Game()
{
	//���I�̉��
	delete pPlayer;
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
