//===============================================
//�^�C�g���o�b�N����[titleBG.h]
//Date:2023/07/10	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

//==================================
//�N���X�錾
//==================================
class TitleBG:public Obj
{
public:
	TitleBG();
	~TitleBG();
	void Update(void)override;
	void Draw(void)override;
};

