//===============================================
//�^�C�g������[result.h]
//Date:2023/07/10	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//�N���X�錾
//==================================
class Result :public Obj
{
public:
	Result();
	~Result();
	void Update(void)override;
	void Draw(void)override;
};


