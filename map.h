//===============================================
//ゲーム制御[map.h]
//Date:2023/10/27	Auther:林祐也
//===============================================
#pragma once

#include "obj.h"
#include "renderer.h"
#include "obstacle.h"

//==================================
//マクロ定義
//==================================
#define OBSTACLE_MAX	(10)	//障害物の上限数

//==================================
//マクロ定義
//==================================
#define OBSTACLE_MAX	(10)	//障害物の上限数

///==================================
//クラス宣言
//==================================
class Map :public Obj
{
private:

	Obstacle* pObstacle[OBSTACLE_MAX];

public:
	Map();
	~Map();
	void Update(void)override;
	void Draw(void)override;

	//Obstacleの情報を取得
	Obstacle* GetObstacle(int cnt)const {
		return pObstacle[cnt];
	}

};