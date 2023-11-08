//===============================================
//�Q�[������[map.h]
//Date:2023/10/27	Auther:�їS��
//===============================================
#pragma once

#include "obj.h"
#include "renderer.h"
#include "obstacle.h"
#include "vector"
//==================================
//�}�N����`
//==================================
#define OBSTACLE_MAX	(30)	//��Q���̏����


///==================================
//�N���X�錾
//==================================
class Map :public Obj
{
private:
	std::vector<Obstacle> obstacles;
	std::vector<Obstacle> mapobstacles;
	/*Obstacle* pObstacle[OBSTACLE_MAX];*/

public:
	Map();
	~Map();
	void Update(void)override;
	void Draw(void)override;

	//Obstacle�̏����擾
	const std::vector<Obstacle>& GetObstacles() const {
		return obstacles;
	}
	const std::vector<Obstacle>& GetMapObstacles()const {
		return mapobstacles;
	}
	//Obstacle* GetObstacle(int cnt)const {
	//	return pObstacle[cnt];
	//}

};