//===============================================
//�^�C�g������[resultBG.h]
//Date:2023/07/31	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//�N���X�錾
//==================================
class ResultBG :public Obj
{
public:
	ResultBG();
	~ResultBG();
	void Update(void)override;
	void Draw(void)override;
};


