//===============================================
//�v���C���[����[player.h]
//Date:2023/11/08	Auther:杈̐i
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
//�}�N����`
//==================================
#define PLAYER_MOVE_SPEED_X (10) //X���W�̃v���C���[�̈ړ����x
#define PLAYER_MOVE_SPEED_Z (10) //Z���W�̃v���C���[�̈ړ����x
#define PLAYER_MOVE_SPEED_Y (10) //Y���W�̃v���C���[�̈ړ����x
///==================================
//�N���X�錾
//==================================
class CAttackArea;
class Player :public Obj
{
private:
	const float ATTACK_DMG = 1.0f;
	Map* m_Map = nullptr;
	std::vector<Enemy*> m_enemies;
	CAttackArea* m_attackarea;
	CollisionPoly* m_colpoly=nullptr;
	DefenseObj* m_defenseobj = nullptr;
public:
	Player(Map* map, std::vector<Enemy*>& enemies, DefenseObj* defenseobj);
	~Player();
	void Update(void)override;
	void Draw(void)override;
};
#endif





