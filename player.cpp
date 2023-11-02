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

	//速度を足していくプレイヤーの座標移動
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

		//当たっている時
		if (obstacle.GetFlag())
		{
			SetPosY(GetPosY() + 500.0f);
		}
		//地面についている時
		else if (GetPosY() <= 0.0f)
		{
			SetPosY(0.1f);
		}
		//当たっていないとき
		else if (!obstacle.GetFlag())
		{
			SetVelY(-10.0f);
		}
	}

	//前
	if (GetKeyboardPress(DIK_W))
	{
		SetVelZ(PLAYER_MOVE_SPEED_Z);
	}
	//後ろ
	else if (GetKeyboardPress(DIK_S))
	{
		SetVelZ(-PLAYER_MOVE_SPEED_Z);
	}
	else
	{
		SetVelZ(0);
	}
	//左
	if (GetKeyboardPress(DIK_A))
	{
		SetVelX(-PLAYER_MOVE_SPEED_X);
	}
	//右
	else if (GetKeyboardPress(DIK_D))
	{
		SetVelX(PLAYER_MOVE_SPEED_X);
	}
	else
	{
		SetVelX(0);
	}

	//左
	if (GetKeyboardPress(DIK_F))
	{
		SetVelY(-PLAYER_MOVE_SPEED_Y);
	}
	//右
	else if (GetKeyboardPress(DIK_G))
	{
		SetVelY(PLAYER_MOVE_SPEED_Y);
	}

	

}

void Player::Draw(void)
{
	// ポリゴンの描画処理
	DrawPlayerPolygon(model, GetPos(), GetSize(), GetRot(),GetScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
