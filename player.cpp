//===============================================
//�^�C�g������[player.cpp]
//Date:2023/10/27	Auther:�їS��
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
	//���x�𑫂��Ă����v���C���[�̍��W�ړ�
	SetPlayerPos(GetPlayerPos() + GetPlayerVel());

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
		SetPlayerVelX(PLAYER_MOVE_SPEED_X);
	}
	//�E
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
