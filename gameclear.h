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
class GameClear :public Obj
{
public:
	GameClear();
	~GameClear();
	void Update(void)override;
	void Draw(void)override;
};
