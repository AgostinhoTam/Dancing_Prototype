//===============================================
//ƒ^ƒCƒgƒ‹§Œä[map.cpp]
//Date:2023/10/30	Auther:—Ñ—S–ç
//===============================================
#include "map.h"

Map::Map()
{	
	//前面障害
	for(int i =0;i<OBSTACLE_MAX;i++){
		obstacles.push_back(Obstacle(D3DXVECTOR3(40.0f * i -(OBSTACLE_MAX*0.5*40), 0.0f, 100.0f),
			D3DXVECTOR3(10.0f, 100.0f, 100.0f),
			D3DXVECTOR3(1.0f, 5.0f, 1.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f)));
	}
	//後ろ障害
	for (int i = 0; i < OBSTACLE_MAX; i++) {
		obstacles.push_back(Obstacle(D3DXVECTOR3(40.0f * i - (OBSTACLE_MAX * 0.5 * 40), 0.0f, -600.0f),
			D3DXVECTOR3(10.0f, 100.0f, 100.0f),
			D3DXVECTOR3(1.0f, 5.0f, 1.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f)));
	}

}

Map::~Map()
{
	obstacles.clear();
}

void Map::Update(void)
{

}

void Map::Draw(void)
{
	for (auto& obstacle : obstacles) {
		obstacle.Draw();
	}
}
