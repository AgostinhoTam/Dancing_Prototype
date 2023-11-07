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
class Enemy :public Obj
{
	const int ENEMY_MAX_NUM = 200;
	const float NORMAL_ENEMY_SPEED = 2.0f;
	Map* m_map= nullptr;
	DefenseObj* m_defenseobj= nullptr;
public:
	Enemy();
	Enemy(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rvel, D3DXVECTOR3 rsize, D3DXVECTOR3 rrot, D3DXVECTOR3 rscale, Map& rmap, DefenseObj& rdefobj) :
		  Obj(rmodel,rpos,rvel,rsize,rscale,rrot),m_map(&rmap),m_defenseobj(&rdefobj){}
	~Enemy();
	void Update(void)override;
	void Draw(void)override;
	void CollisionCheck(Map* rmap);
	void MoveToDefense();
	D3DXVECTOR3 CalDirection(const D3DXVECTOR3& enemyvel, const D3DXVECTOR3& direction);
};

#endif // !_ENEMY_H_




