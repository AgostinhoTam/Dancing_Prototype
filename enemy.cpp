//===============================================
//タイトル制御[enemy.cpp]
//Date:2023/10/27	Auther:林祐也
//===============================================
#include "obj.h"
#include "enemy.h"
#include "input.h"
//#include "camera.h"
#define PERFECT_FAITH (2.0f)			//信仰値調整用
#define NORMAL_FAITL (1.0f)
Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Update(void)
{
	//速度を足していくプレイヤーの座標移動
	SetEnemyPos(GetEnemyPos() + GetEnemyVel());

	//前
	if (GetKeyboardPress(DIK_W))
	{
		SetEnemyVelZ(ENEMY_MOVE_SPEED_Z);
	}
	//後ろ
	else if (GetKeyboardPress(DIK_S))
	{
		SetEnemyVelZ(-ENEMY_MOVE_SPEED_Z);
	}
	else
	{
		SetEnemyVelZ(0);
	}
	//左
	if (GetKeyboardPress(DIK_A))
	{
		SetEnemyVelX(ENEMY_MOVE_SPEED_X);
	}
	//右
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
