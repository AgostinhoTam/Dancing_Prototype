//===============================================
//“G§Œä[enemy.cpp]
//Date:2023/11/08	Auther:æˆÌi
//===============================================
#include "obj.h"
#include "enemy.h"
#include "polygon.h"
#include "collision.h"
#include "defenseobj.h"
#include "collsionpoly.h"
int frame = 0;

Enemy::Enemy(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rvel, D3DXVECTOR3 rsize, D3DXVECTOR3 rrot, D3DXVECTOR3 rscale, Map& rmap, DefenseObj& rdefobj, CAttackArea* attackarea,Player* player, bool alive)  :
	Obj(rmodel, rpos, rvel, rsize, rscale, rrot), m_map(&rmap), m_defenseobj(&rdefobj), m_attackarea(attackarea), m_player(player) {
	SetFlag(alive);
	m_colpoly = new CollisionPoly(model.m_MaxVertex, model.m_MinVertex);
}
Enemy::Enemy(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rvel, D3DXVECTOR3 rsize, D3DXVECTOR3 rrot, D3DXVECTOR3 rscale, Map& rmap, DefenseObj& rdefobj, bool alive):Obj(rmodel, rpos, rvel, rsize, rscale, rrot), m_map(&rmap)
{
	SetFlag(alive);
}
Enemy::~Enemy()
{
	delete m_colpoly;
	UnloadModel(&model);
}

void Enemy::Update(void)
{
	if (m_attackarea != nullptr && m_defenseobj != nullptr && m_player != nullptr){
	MoveToDefense();
	m_colpoly->UpdateColPoly(&model);
	CollisionCheck (m_map,m_attackarea);
	}
}

void Enemy::Draw(void)
{
	// ƒ|ƒŠƒSƒ“‚Ì•`‰æˆ—
	if (GetFlag()){
		DrawPolygon(&model, GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld());
	}

	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}


void Enemy::CollisionCheck(Map* rmap, CAttackArea* attackarea)
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
	}
	if (CollisionBB(GetPos(), GetSize(), GetScl(), attackarea->GetPos(), attackarea->GetSize(), attackarea->GetScl())) {
 		SetFlag(false);
	}
}

void Enemy::MoveToDefense()
{
	if(m_defenseobj != nullptr){
	D3DXVECTOR3 Nowpos = this->GetPos();
		D3DXVECTOR3 direction = (m_player->GetPos()) - Nowpos;
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







