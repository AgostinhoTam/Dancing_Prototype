//===============================================
//�Q�[������[map.h]
//Date:2023/10/27	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//�N���X�錾
//==================================
class Map :public Obj
{
public:
	Map();
	~Map();
	void Update(void)override;
	void Draw(void)override;
};





