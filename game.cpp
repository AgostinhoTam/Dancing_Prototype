//===============================================
//�^�C�g������[gameover.cpp]
//Date:2023/09/05	Auther:�їS��
//===============================================
#include "obj.h"
#include "game.h"
#include "player.h"
#include "input.h"

#define	USE_KEYBOARD

//-------------------------------------
//�ϐ��錾
//-------------------------------------
//Player *pPlayer;

//�R���X�g���N�^
Game::Game()
{
	//�C���X�^���X��
	//pPlayer = new Player();
	pNotes = new Notes();
	pJF = new JudgmentFrame();
}
//�f�X�g���N�^
Game::~Game()
{
	//���I�̉��
	//delete pPlayer;
	delete pNotes;
	delete pJF;
}
//�X�V����
void Game::Update(void)
{
	//pPlayer->Update();
	pNotes->Update();
	pJF->Update();


}
//�`�揈��
void Game::Draw(void)
{
	//pPlayer->Draw();
	pNotes->Draw();
	pJF->Draw();


}
