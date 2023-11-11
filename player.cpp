//===============================================
//�v���C���[����[player.cpp]
//Date:2023/11/08	Auther:杈̐i
//===============================================
#include "player.h"
#include "model.h"
#include "collision.h"
#include "input.h"

#include "polygon.h"
Player::Player(Map* map, std::vector<Enemy*>& enemies, DefenseObj* defenseobj):
	m_Map(map), 
	m_enemies(enemies),
	m_defenseobj(defenseobj)
{
	LoadModel((char*)"data/MODEL/moxrigvamp02.obj", &model);
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	SetScl(D3DXVECTOR3(0.2f, 0.2f, 0.2f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_attackarea = new CAttackArea();
	m_colpoly = new CollisionPoly(model.m_MaxVertex, model.m_MinVertex);
}

Player::~Player()
{	
	delete m_attackarea;
	delete m_colpoly;
	UnloadModel(&model);
}

void Player::Update(void)
{
	//���x�𑫂��Ă����v���C���[�̍��W�ړ�
	SetPos(GetPos() + GetVel());
	m_attackarea->UpdatePos(GetPos());
	m_attackarea->Update();
	for (auto obstacle: m_Map->GetObstacles())
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
	
	//m_colpoly->UpdateColPoly(&model);

	for (auto& enemy : m_enemies) {
		
		if (CollisionBB(m_attackarea->GetPos(), m_attackarea->GetSize(), m_attackarea->GetScl(), enemy->GetPos(), enemy->GetSize(), enemy->GetScl())) {
			enemy->SetFlag(false);
		
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

	m_attackarea->Draw();
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
