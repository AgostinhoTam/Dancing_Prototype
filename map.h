//===============================================
//ゲーム制御[map.h]
//Date:2023/10/27	Auther:林祐也
//===============================================
#pragma once
#ifndef _MAP_H
#define _MAP_H
#include <vector>
#include "obstacle.h"
//==================================
//マクロ定義
//==================================
#define OBSTACLE_MAX	(1)	//障害物の上限数


///==================================
//クラス宣言
//==================================
class Map :public Obj
{
private:
	std::vector<Obstacle> obstacles;
	//std::vector<Obstacle> mapobstacles;
	/*Obstacle* pObstacle[OBSTACLE_MAX];*/

public:
	Map();
	~Map();
	void Update(void)override;
	void Draw(void)override;

	//Obstacleの情報を取得
	std::vector<Obstacle>& GetObstacles(){
		return obstacles;
	}


};
#endif // !_MAP_H