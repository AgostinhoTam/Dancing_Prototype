//===============================================
//�^�C�g������[title.h]
//Date:2023/07/10	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//�N���X�錾
//==================================
class Title :public Obj
{
public:
	Title();
	~Title();
	void Update(void)override;
	void Draw(void)override;
};


