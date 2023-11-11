//===============================================
//プレイヤー制御[player.h]
//Date:2023/11/08	Auther:譚偉進
//===============================================
#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "obj.h"
#include "attackarea.h"
#include "collsionpoly.h"
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
class Enemy;
class Player :public Obj
{
private:
	const float ATTACK_DMG = 1.0f;
	Map* m_Map = nullptr;
	std::vector<Enemy*> m_enemies;
	DefenseObj* m_defenseobj = nullptr;
	CAttackArea* m_attackarea;
	CollisionPoly* m_colpoly;
public:
	Player(Map* map, std::vector<Enemy*>& enemies, DefenseObj* defenseobj);
	~Player();
	void Update(void)override;
	void Draw(void)override;
	CAttackArea* GetAttackArea() { return m_attackarea; }
	Player* GetPlayer() { return this; }
};
#endif





