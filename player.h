//===============================================
//�Q�[������[player.h]
//Date:2023/10/27	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "obstacle.h"
#include "map.h"

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
	Obstacle* pObstacle[OBSTACLE_MAX];
public:
	Player();
	~Player();
	void Update(void)override;
	void Draw(void)override;

	void SetObstacle(Obstacle *sObstacle,int cnt) {
			pObstacle[cnt] = sObstacle;
	}
};





