//===============================================
//�^�C�g������[player.cpp]
//Date:2023/10/29	Auther:�їS��
//===============================================
#include "player.h"
#include "input.h"
#include "polygon.h"
#include "camera.h"
#include "collision.h"

Player::Player()
{
	LoadModel((char*)"data/MODEL/katana_02.obj", &model);
	SetPlayerPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetPlayerSize(D3DXVECTOR3(10.0f, 1.0f, 1.0f));
	SetPlayerScl(D3DXVECTOR3(8.0f, 8.0f, 8.0f));
	SetPlayerRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

Player::~Player()
{
	UnloadModel(&model);
}

void Player::Update(void)
{

	//���x�𑫂��Ă����v���C���[�̍��W�ړ�
	SetPlayerPos(GetPlayerPos() + GetPlayerVel());

	for (int i = 0; i < OBSTACLE_MAX; i++)
	{
		if (CollisionBB(GetPlayerPos(), GetPlayerSize(), GetPlayerScl(), pObstacle[i]->GetPos(), pObstacle[i]->GetSize(), pObstacle[i]->GetScl()))
		{
			pObstacle[i]->SetFlag(true);
		}
		else if (!CollisionBB(GetPlayerPos(), GetPlayerSize(), GetPlayerScl(), pObstacle[i]->GetPos(), pObstacle[i]->GetSize(), pObstacle[i]->GetScl()))
		{
			pObstacle[i]->SetFlag(false);
		}

		//�������Ă��鎞
		if (pObstacle[i]->GetFlag())
		{
			SetPlayerPosY(GetPlayerPosY() + 500.0f);
		}
		//�n�ʂɂ��Ă��鎞
		else if (GetPlayerPosY() <= 0.0f)
		{
			SetPlayerPosY(0.1f);
		}
		//�������Ă��Ȃ��Ƃ�
		else if (!pObstacle[i]->GetFlag())
		{
			SetPlayerVelY(-10.0f);
		}
	}

	//�O
	if (GetKeyboardPress(DIK_W))
	{
		SetPlayerVelZ(PLAYER_MOVE_SPEED_Z);
	}
	//���
	else if (GetKeyboardPress(DIK_S))
	{
		SetPlayerVelZ(-PLAYER_MOVE_SPEED_Z);
	}
	else
	{
		SetPlayerVelZ(0);
	}
	//��
	if (GetKeyboardPress(DIK_A))
	{
		SetPlayerVelX(-PLAYER_MOVE_SPEED_X);
	}
	//�E
	else if (GetKeyboardPress(DIK_D))
	{
		SetPlayerVelX(PLAYER_MOVE_SPEED_X);
	}
	else
	{
		SetPlayerVelX(0);
	}

	//��
	if (GetKeyboardPress(DIK_F))
	{
		SetPlayerVelY(-PLAYER_MOVE_SPEED_Y);
	}
	//�E
	else if (GetKeyboardPress(DIK_G))
	{
		SetPlayerVelY(PLAYER_MOVE_SPEED_Y);
	}

	

}

void Player::Draw(void)
{
	// �|���S���̕`�揈��
	DrawPlayerPolygon(model, GetPlayerPos(), GetPlayerSize(), GetPlayerRot(),GetPlayerScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
