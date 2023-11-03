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
	LoadModel((char*)"data/MODEL/miku_01.obj", &model);
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(10.0f, 1.0f, 1.0f));
	SetScl(D3DXVECTOR3(8.0f, 8.0f, 8.0f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

Player::~Player()
{
	obstacles.clear();
	UnloadModel(&model);
}

void Player::Update(void)
{

	//���x�𑫂��Ă����v���C���[�̍��W�ړ�
	SetPos(GetPos() + GetVel());

	for (auto& obstacle:obstacles)
	{
		if (CollisionBB(GetPos(), GetSize(), GetScl(), obstacle.GetPos(), obstacle.GetSize(), obstacle.GetScl()))
		{
			obstacle.SetFlag(true);
		}
		else if (!CollisionBB(GetPos(), GetSize(), GetScl(), obstacle.GetPos(), obstacle.GetSize(), obstacle.GetScl()))
		{
			obstacle.SetFlag(false);
		}

		//�������Ă��鎞
		if (obstacle.GetFlag())
		{
			SetPosY(GetPosY() + 500.0f);
		}
		//�n�ʂɂ��Ă��鎞
		else if (GetPosY() <= 0.0f)
		{
			SetPosY(0.1f);
		}
		//�������Ă��Ȃ��Ƃ�
		else if (!obstacle.GetFlag())
		{
			SetVelY(-10.0f);
		}
	}

	//�O
	if (GetKeyboardPress(DIK_W))
	{
		SetVelZ(PLAYER_MOVE_SPEED_Z);
	}
	//���
	else if (GetKeyboardPress(DIK_S))
	{
		SetVelZ(-PLAYER_MOVE_SPEED_Z);
	}
	else
	{
		SetVelZ(0);
	}
	//��
	if (GetKeyboardPress(DIK_A))
	{
		SetVelX(-PLAYER_MOVE_SPEED_X);
	}
	//�E
	else if (GetKeyboardPress(DIK_D))
	{
		SetVelX(PLAYER_MOVE_SPEED_X);
	}
	else
	{
		SetVelX(0);
	}

	//��
	if (GetKeyboardPress(DIK_F))
	{
		SetVelY(-PLAYER_MOVE_SPEED_Y);
	}
	//�E
	else if (GetKeyboardPress(DIK_G))
	{
		SetVelY(PLAYER_MOVE_SPEED_Y);
	}

	

}

void Player::Draw(void)
{
	// �|���S���̕`�揈��
	DrawPlayerPolygon(model, GetPos(), GetSize(), GetRot(),GetScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
