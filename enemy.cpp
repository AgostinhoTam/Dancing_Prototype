//===============================================
//�^�C�g������[enemy.cpp]
//Date:2023/10/27	Auther:�їS��
//===============================================
#include "obj.h"
#include "enemy.h"
#include "input.h"
//#include "camera.h"
#define PERFECT_FAITH (2.0f)			//�M�l�����p
#define NORMAL_FAITL (1.0f)
Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Update(void)
{
	//���x�𑫂��Ă����v���C���[�̍��W�ړ�
	SetEnemyPos(GetEnemyPos() + GetEnemyVel());

	//�O
	if (GetKeyboardPress(DIK_W))
	{
		SetEnemyVelZ(ENEMY_MOVE_SPEED_Z);
	}
	//���
	else if (GetKeyboardPress(DIK_S))
	{
		SetEnemyVelZ(-ENEMY_MOVE_SPEED_Z);
	}
	else
	{
		SetEnemyVelZ(0);
	}
	//��
	if (GetKeyboardPress(DIK_A))
	{
		SetEnemyVelX(ENEMY_MOVE_SPEED_X);
	}
	//�E
	else if (GetKeyboardPress(DIK_D))
	{
		SetEnemyVelX(-ENEMY_MOVE_SPEED_X);
	}
	else
	{
		SetEnemyVelX(0);
	}
}

void Enemy::Draw(void)
{

}
