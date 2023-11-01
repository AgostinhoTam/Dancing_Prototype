//===============================================
//ゲーム制御[player.h]
//Date:2023/10/27	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"
#include "obstacle.h"
#include "map.h"

//==================================
//マクロ定義
//==================================
#define PLAYER_MOVE_SPEED_X (10) //X座標のプレイヤーの移動速度
#define PLAYER_MOVE_SPEED_Z (10) //Z座標のプレイヤーの移動速度
#define PLAYER_MOVE_SPEED_Y (10) //Y座標のプレイヤーの移動速度

///==================================
//クラス宣言
//==================================
class Player :public Obj
{
private:
	Obstacle* pObstacle[OBSTACLE_MAX];
public:
	Player();
	~Player();
	void Update(void)override;
	void Draw(void)override;

	void SetObstacle(Obstacle *sObstacle,int cnt) {
			pObstacle[cnt] = sObstacle;
	}
};





