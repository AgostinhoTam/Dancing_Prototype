//===============================================
//ゲーム制御[player.h]
//Date:2023/10/27	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"

//==================================
//マクロ定義
//==================================
#define PLAYER_MOVE_SPEED_X (10) //X座標のプレイヤーの移動速度
#define PLAYER_MOVE_SPEED_Z (15) //Z座標のプレイヤーの移動速度

///==================================
//クラス宣言
//==================================
class Player :public Obj
{
public:
	Player();
	~Player();
	void Update(void)override;
	void Draw(void)override;
};





