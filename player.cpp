//===============================================
//タイトル制御[player.cpp]
//Date:2023/10/27	Auther:林祐也
//===============================================
#include "obj.h"
#include "player.h"
#include "input.h"
//#include "camera.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Update(void)
{
	//速度を足していくプレイヤーの座標移動
	SetPlayerPos(GetPlayerPos() + GetPlayerVel());

	//前
	if (GetKeyboardPress(DIK_W))
	{
		SetPlayerVelZ(PLAYER_MOVE_SPEED_Z);
	}
	//後ろ
	else if (GetKeyboardPress(DIK_S))
	{
		SetPlayerVelZ(-PLAYER_MOVE_SPEED_Z);
	}
	else
	{
		SetPlayerVelZ(0);
	}
	//左
	if (GetKeyboardPress(DIK_A))
	{
		SetPlayerVelX(PLAYER_MOVE_SPEED_X);
	}
	//右
	else if (GetKeyboardPress(DIK_D))
	{
		SetPlayerVelX(-PLAYER_MOVE_SPEED_X);
	}
	else
	{
		SetPlayerVelX(0);
	}
}

void Player::Draw(void)
{

}
