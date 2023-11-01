//===============================================
//É^ÉCÉgÉãêßå‰[map.cpp]
//Date:2023/10/30	Auther:ó—óSñÁ
//===============================================
#include "map.h"
#include "obstacle.h"

Map::Map()
{
	for (int i = 0; i < OBSTACLE_MAX; i++)
	{
		pObstacle[i] = new Obstacle();
	}

	for (int i = 0; i < OBSTACLE_MAX; i++)
	{
		pObstacle[i]->SetPos(D3DXVECTOR3(40.0f*i +100.0f, 0.0f, 40.0f*i));
		pObstacle[i]->SetSize(D3DXVECTOR3(10.0f, 100.0f, 100.0f));
		pObstacle[i]->SetScl(D3DXVECTOR3(1.0f, 5.0f, 1.0f));
		pObstacle[i]->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
}

Map::~Map()
{
	for (int i = 0; i < OBSTACLE_MAX; i++)
	{
		delete pObstacle[i];
	}
}

void Map::Update(void)
{
	for (int i = 0; i < OBSTACLE_MAX; i++)
	{
		pObstacle[i]->Update();
		pObstacle[i]->SetPlayerPos(GetPlayerPos());
		pObstacle[i]->SetPlayerSize(GetPlayerSize());
		pObstacle[i]->SetPlayerScl(GetPlayerScl());
	}
	
}

void Map::Draw(void)
{
	for (int i = 0; i < OBSTACLE_MAX; i++)
	{
		pObstacle[i]->Draw();
	}
}
