//===============================================
//“G§Œä[enemy.cpp]
//Date:2023/11/08	Auther:æˆÌi
//===============================================
#include "obj.h"
#include "enemy.h"
#include "polygon.h"
#include "collision.h"
#include "defenseobj.h"
int frame = 0;


Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Update(void)
{
	MoveToDefense();
	
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
		if (CollisionBB(this->GetPos(), this->GetSize(), this->GetScl(), obstacle.GetPos(), obstacle.GetSize(), obstacle.GetScl()))
		{
			obstacle.SetFlag(true);
		}
		else if (!CollisionBB(this->GetPos(), this->GetSize(), this->GetScl(), obstacle.GetPos(), obstacle.GetSize(), obstacle.GetScl()))
		{
			obstacle.SetFlag(false);
		}

		//“–‚½‚Á‚Ä‚¢‚éŽž
		if (obstacle.GetFlag())
		{
			//this->SetPosY(this->GetPosY() + 500.0f);
			//this->SetPosY(this->GetPosY());
		}
		//’n–Ê‚É‚Â‚¢‚Ä‚¢‚éŽž
		else if (GetPosY() <= 0.0f)
		{
			//this->SetPosY(0.1f);
		}
		//“–‚½‚Á‚Ä‚¢‚È‚¢‚Æ‚«
		else if (!obstacle.GetFlag())
		{
			//this->SetVelY(-10.0f);
		}
	}
}

void Enemy::MoveToDefense()
{
	if(m_defenseobj != nullptr){
	D3DXVECTOR3 Nowpos = this->GetPos();
		D3DXVECTOR3 direction = (m_defenseobj->GetPos()) - Nowpos;
		D3DXVec3Normalize(&direction, &direction);
		SetVel(direction * NORMAL_ENEMY_SPEED);
		SetPos(GetPos() + GetVel());
	}
}

D3DXVECTOR3 Enemy::CalDirection(const D3DXVECTOR3& enemyvel, const D3DXVECTOR3& direction)
{
	D3DXVECTOR3 result;
	result.x = enemyvel.x * direction.x;
	result.y = enemyvel.y * direction.y;
	result.z = enemyvel.z * direction.z;
	return result;
}





