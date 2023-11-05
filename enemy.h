//===============================================
//�G����[enemy.h]
//Date:2023/10/27	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "obstacle.h"
#include "map.h"
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
	const float NORMAL_ENEMY_SPEED = 0.5f;
	Map* m_map= nullptr;
public:
	Enemy();
	Enemy(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rvel, D3DXVECTOR3 rsize, D3DXVECTOR3 rrot, D3DXVECTOR3 rscale, Map& rmap) :Obj(rmodel,rpos,rvel,rsize,rscale,rrot),m_map(&rmap){}
	~Enemy();
	void Update(void)override;
	void Draw(void)override;
	void CollisionCheck(Map* rmap);
};





