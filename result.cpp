//===============================================
//�^�C�g������[result.cpp]
//Date:2023/07/31	Auther:�їS��
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
// ����������
//=============================================================================
Result::Result()
{
	pResultBG = new ResultBG();
}

//=============================================================================
// �I������
//=============================================================================
Result::~Result()
{
	delete pResultBG;
	//if (GetBattleWinner() == 2)//�G����������
	//{
	//	delete pGameOver;
	//}
	//if (GetBattleWinner() == 1)//�v���C���[����������
	//{
	//	delete pGameCrear;
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void Result::Update()
{
	SetCnt(GetCnt() + 1);
	if (GetCnt() == 1)
	{
		//if (GetBattleWinner() == 2)//�G����������
		//{
		//	pGameOver = new GameOver();
		//}
		//if (GetBattleWinner() == 1)//�v���C���[����������
		//{
		//	pGameCrear = new GameCrear();
		//}
	}

	pResultBG->Update();
	if (GetCnt() > 2)
	{
		//if (GetBattleWinner() == 2)//�G����������
		//{
		//	pGameOver->Update();
		//}
		//if (GetBattleWinner() == 1)//�v���C���[����������
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
// �`�揈��
//=============================================================================
void Result::Draw(void)
{
	pResultBG->Draw();
	if (GetCnt() >= 2)
	{
		//if (GetBattleWinner() == 2)//�G����������
		//{
		//	pGameOver->Draw();
		//}
		//if (GetBattleWinner() == 1)//�v���C���[����������
		//{
		//	pGameCrear->Draw();
		//}
	}
}