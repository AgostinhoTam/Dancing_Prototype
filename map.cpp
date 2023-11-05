//===============================================
//ƒ^ƒCƒgƒ‹§Œä[map.cpp]
//Date:2023/10/30	Auther:—Ñ—S–ç
//===============================================
#include "map.h"
#include "obstacle.h"

Map::Map()
{
	DX11_MODEL temp;
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
	
	LoadModel((char*)"data/MODEL/dancing_color_03.obj", &temp);
	mapobstacles.push_back(Obstacle(temp, 
		D3DXVECTOR3(-2450.0f, -500.0f, 0.0f),
		D3DXVECTOR3(10.0f, 10.0f, 10.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, D3DX_PI, 0.0f)));

		//pObstacle[i]->SetPos(D3DXVECTOR3(40.0f*i +100.0f, 0.0f, 40.0f*i));
		//pObstacle[i]->SetSize(D3DXVECTOR3(10.0f, 100.0f, 100.0f));
		//pObstacle[i]->SetScl(D3DXVECTOR3(1.0f, 5.0f, 1.0f));

		//pObstacle[i]->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

}

Map::~Map()
{
	obstacles.clear();
	mapobstacles.clear();
	//for (int i = 0; i < OBSTACLE_MAX; i++)
	//{
	//	delete pObstacle[i];
	//}
}

void Map::Update(void)
{
	//for (auto& obstacle : obstacles) {
	//	obstacle.Update();
	//	obstacle.SetPos(GetPos());
	//	obstacle.SetSize(GetSize());
	//	obstacle.SetScl(GetScl());
	//}
	//for (int i = 0; i < OBSTACLE_MAX; i++)
	//{
	//	pObstacle[i]->Update();
	//	pObstacle[i]->SetPos(GetPos());
	//	pObstacle[i]->SetSize(GetSize());
	//	pObstacle[i]->SetScl(GetScl());
	//}
}

void Map::Draw(void)
{
	for (auto& obstacle : obstacles) {
		obstacle.Draw();
	}
	for (auto& mapobstacle : mapobstacles) {
		mapobstacle.DrawMap();
	}
}
