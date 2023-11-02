//===============================================
//ゲーム制御[defenseobj.h]
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
class DefenseObj :public Obj
{
private:
	Obstacle* m_defenseobj;
public:
	DefenseObj();
	~DefenseObj();
	void Update(void)override;
	void Draw(void)override;

	void SetDefenseObj(Obstacle *sObstacle) {
		m_defenseobj = sObstacle;
	}
};





