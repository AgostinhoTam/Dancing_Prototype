//===============================================
//敵制御[enemy.h]
//Date:2023/10/27	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"
#include "obstacle.h"
#include "map.h"
#include <vector>
//==================================
//マクロ定義
//==================================
#define ENEMY_MOVE_SPEED_X (10) //X座標のプレイヤーの移動速度
#define ENEMY_MOVE_SPEED_Z (10) //Z座標のプレイヤーの移動速度
#define ENEMY_MOVE_SPEED_Y (10) //Y座標のプレイヤーの移動速度

///==================================
//クラス宣言
//==================================
class Enemy :public Obj
{
	const int ENEMY_MAX_NUM = 200;
	const float NORMAL_ENEMY_SPEED = 0.5f;
	std::vector<Enemy> Enemies;
	Map* m_map;
public:
	Enemy();
	Enemy(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rvel, D3DXVECTOR3 rsize, D3DXVECTOR3 rrot, D3DXVECTOR3 rscale) :Obj(rmodel,rpos,rvel,rsize,rscale,rrot){}
	~Enemy();
	void Update(void)override;
	void Draw(void)override;
	void AddEnemy(int number);
	void CollisionCheck(std::vector<Enemy>& renemies, Map* rmap);
};





