//===============================================
//�^�C�g������[gameclear.h]
//Date:2023/09/05	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//�N���X�錾
//==================================
class GameOver :public Obj
{
public:
	GameOver();
	~GameOver();
	void Update(void)override;
	void Draw(void)override;
};


