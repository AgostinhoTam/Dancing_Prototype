//===============================================
//ìGêßå‰[enemy.cpp]
//Date:2023/10/29	Auther:ÉVÉì
//===============================================
#include "player.h"
#include "input.h"
#include "polygon.h"
#include "camera.h"
#include "collision.h"
#include "enemy.h"
#include "title.h"
int frame = 0;
static DX11_MODEL enemytemp;
Enemy::Enemy()
{
	
	LoadModel((char*)"data/MODEL/moxrigvamp02.obj", &enemytemp);
}

Enemy::~Enemy()
{
	Enemies.clear(); 
	UnloadModel(&enemytemp);
}

void Enemy::Update(void)
{
	frame++;

	if (frame == 15 && Enemies.size()< ENEMY_MAX_NUM) {
		AddEnemy(Enemies.size());
		frame = 0;
	}
	CollisionCheck(Enemies,m_map);
	//for (auto& Enemy : Enemies) {
	//	for(auto& mapobstacle:mapobstacles){
	//		D3DXVECTOR3 direction = Enemy.GetPos() - mapobstacle.GetPos();
	//		D3DXVECTOR3 normalizedDirection;
	//		D3DXVec3Normalize(&normalizedDirection, &direction);
	//		Enemy.SetVel(normalizedDirection * NORMAL_ENEMY_SPEED);
	//	}
	//	Enemy.SetPos(Enemy.GetPos() += GetVel());
	//}

	
}

void Enemy::Draw(void)
{
	// É|ÉäÉSÉìÇÃï`âÊèàóù
	for (auto& Enemy : Enemies) {
		DrawPolygon(Enemy.GetModel(), Enemy.GetPos(), Enemy.GetSize(), Enemy.GetRot(), Enemy.GetScl(), Enemy.GetMtxWorld());
	}

	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}

void Enemy::AddEnemy(int number)
{
	Enemies.push_back(Enemy(enemytemp,							//model
		D3DXVECTOR3(40.0f*number, 0.0f, 0.0f),						//pos
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//vel
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//size
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//rot
		D3DXVECTOR3(0.2f, 0.2f, 0.2f)));					//scl
}

void Enemy::CollisionCheck(std::vector<Enemy>& renemies, Map* rmap)
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

		//ìñÇΩÇ¡ÇƒÇ¢ÇÈéû
		if (obstacle.GetFlag())
		{
			SetPosY(GetPosY() + 500.0f);
		}
		//ínñ Ç…Ç¬Ç¢ÇƒÇ¢ÇÈéû
		else if (GetPosY() <= 0.0f)
		{
			SetPosY(0.1f);
		}
		//ìñÇΩÇ¡ÇƒÇ¢Ç»Ç¢Ç∆Ç´
		else if (!obstacle.GetFlag())
		{
			SetVelY(-10.0f);
		}
	}
}
