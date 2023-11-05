//===============================================
//“G§Œä[enemy.cpp]
//Date:2023/10/29	Auther:ƒVƒ“
//===============================================
#include "player.h"
#include "input.h"
#include "polygon.h"
#include "camera.h"
#include "collision.h"
#include "enemy.h"
#include "title.h"
int frame = 0;


Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	
}

void Enemy::Update(void)
{

	CollisionCheck(m_map);
}

void Enemy::Draw(void)
{
	// ƒ|ƒŠƒSƒ“‚Ì•`‰æˆ—
	
		DrawPolygon(GetModel(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld());
	

	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}


void Enemy::CollisionCheck(Map* rmap)
{
	for (auto& obstacle : rmap->GetObstacles())
	{
		if (CollisionBB(GetPos(), GetSize(), GetScl(), obstacle.GetPos(), obstacle.GetSize(), obstacle.GetScl()))
		{
			obstacle.SetFlag(true);
		}
		else if (!CollisionBB(GetPos(), GetSize(), GetScl(), obstacle.GetPos(), obstacle.GetSize(), obstacle.GetScl()))
		{
			obstacle.SetFlag(false);
		}

		//“–‚½‚Á‚Ä‚¢‚éŽž
		if (obstacle.GetFlag())
		{
			SetPosY(GetPosY() + 500.0f);
		}
		//’n–Ê‚É‚Â‚¢‚Ä‚¢‚éŽž
		else if (GetPosY() <= 0.0f)
		{
			SetPosY(0.1f);
		}
		//“–‚½‚Á‚Ä‚¢‚È‚¢‚Æ‚«
		else if (!obstacle.GetFlag())
		{
			SetVelY(-10.0f);
		}
	}
}
