//===============================================
//タイトル制御[player.cpp]
//Date:2023/10/29	Auther:林祐也
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

	//速度を足していくプレイヤーの座標移動
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

		//当たっている時
		if (pObstacle[i]->GetFlag())
		{
			SetPlayerPosY(GetPlayerPosY() + 500.0f);
		}
		//地面についている時
		else if (GetPlayerPosY() <= 0.0f)
		{
			SetPlayerPosY(0.1f);
		}
		//当たっていないとき
		else if (!pObstacle[i]->GetFlag())
		{
			SetPlayerVelY(-10.0f);
		}
	}

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
		SetPlayerVelX(-PLAYER_MOVE_SPEED_X);
	}
	//右
	else if (GetKeyboardPress(DIK_D))
	{
		SetPlayerVelX(PLAYER_MOVE_SPEED_X);
	}
	else
	{
		SetPlayerVelX(0);
	}

	//左
	if (GetKeyboardPress(DIK_F))
	{
		SetPlayerVelY(-PLAYER_MOVE_SPEED_Y);
	}
	//右
	else if (GetKeyboardPress(DIK_G))
	{
		SetPlayerVelY(PLAYER_MOVE_SPEED_Y);
	}

	

}

void Player::Draw(void)
{
	// ポリゴンの描画処理
	DrawPlayerPolygon(model, GetPlayerPos(), GetPlayerSize(), GetPlayerRot(),GetPlayerScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
