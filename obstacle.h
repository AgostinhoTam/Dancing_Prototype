//===============================================
//��Q������[obstacle.h]
//Date:2023/10/30	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//�N���X�錾
//==================================
class Obstacle :public Obj
{
public:
	Obstacle();
	~Obstacle();
	void Update(void)override;
	void Draw(void)override;
};
