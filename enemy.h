//===============================================
//�G����[enemy.h]
//Date:2023/11/08	Auther:杈̐i
//===============================================
#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_


#include "obj.h"
#include "map.h"
#include "defenseobj.h"
#include "attackarea.h"
#include <vector>
//==================================
//�}�N����`
//==================================
#define ENEMY_MOVE_SPEED_X (10) //X���W�̃v���C���[�̈ړ����x
#define ENEMY_MOVE_SPEED_Z (10) //Z���W�̃v���C���[�̈ړ����x
#define ENEMY_MOVE_SPEED_Y (10) //Y���W�̃v���C���[�̈ړ����x

///==================================
//�N���X�錾
//==================================
class CAttackArea;
class Player;
class Enemy :public Obj
{
	const int ENEMY_MAX_NUM = 200;
	const float NORMAL_ENEMY_SPEED = 2.0f;
	Map* m_map= nullptr;
	DefenseObj* m_defenseobj= nullptr;
	CAttackArea* m_attackarea = nullptr;
	CollisionPoly* m_colpoly=nullptr;
	Player* m_player = nullptr;
public:
	Enemy(){}
	Enemy(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rvel, D3DXVECTOR3 rsize, D3DXVECTOR3 rrot, D3DXVECTOR3 rscale, Map& rmap, DefenseObj& rdefobj, CAttackArea* attackarea,Player* player, bool alive);
	Enemy(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rvel, D3DXVECTOR3 rsize, D3DXVECTOR3 rrot, D3DXVECTOR3 rscale, Map& rmap, DefenseObj& rdefobj, bool alive);
	~Enemy();
	void Update(void)override;
	void Draw(void)override;
	void CollisionCheck(Map* rmap, CAttackArea* attackarea);
	void MoveToDefense();
	D3DXVECTOR3 CalDirection(const D3DXVECTOR3& enemyvel, const D3DXVECTOR3& direction);
};

#endif // !_ENEMY_H_




