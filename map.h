//===============================================
//�Q�[������[map.h]
//Date:2023/10/27	Auther:�їS��
//===============================================
#pragma once

#include "obj.h"
#include "renderer.h"
#include "obstacle.h"

//==================================
//�}�N����`
//==================================
#define OBSTACLE_MAX	(10)	//��Q���̏����

///==================================
//�N���X�錾
//==================================
class Map :public Obj
{
private:

	Obstacle* pObstacle[OBSTACLE_MAX];

public:
	Map();
	~Map();
	void Update(void)override;
	void Draw(void)override;

	//Obstacle�̏����擾
	Obstacle* GetObstacle(int cnt)const {
		return pObstacle[cnt];
	}
};