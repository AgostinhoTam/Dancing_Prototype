//===============================================
//�v���C���[����[player.h]
//Date:2023/11/08	Auther:杈̐i
//===============================================
#pragma once


#include "obj.h"
#include "map.h"
#include "attackobj.h"
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





