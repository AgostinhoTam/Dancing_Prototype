//===============================================
//プレイヤー制御[player.h]
//Date:2023/11/08	Auther:譚偉進
//===============================================
#pragma once


#include "obj.h"
#include "map.h"
#include "attackobj.h"
#include "enemy.h"
#include <vector>
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
	const float ATTACK_DMG = 1.0f;
	Map* m_Map = nullptr;
	std::vector<Enemy*> m_enemies;
	AttackObj m_attackobj;
	D3DXVECTOR3 m_colpoly = {};
public:
	Player(Map* map, std::vector<Enemy*>& enemies);
	~Player();
	void Update(void)override;
	void Draw(void)override;
};





