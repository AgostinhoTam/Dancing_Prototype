//===============================================
//プレイヤー制御[player.h]
//Date:2023/11/08	Auther:譚偉進
//===============================================
#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "obj.h"
#include "attackarea.h"
#include "map.h"
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
class CAttackArea;
class Player :public Obj
{
private:
	const float ATTACK_DMG = 1.0f;
	Map* m_Map = nullptr;
	std::vector<Enemy*> m_enemies;
	D3DXVECTOR3 m_colpoly = {};
	CAttackArea* m_attackarea;
public:
	Player(Map* map, std::vector<Enemy*>& enemies);
	~Player();
	void Update(void)override;
	void Draw(void)override;
};
#endif





