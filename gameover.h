//===============================================
//タイトル制御[gameclear.h]
//Date:2023/09/05	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//クラス宣言
//==================================
class GameOver :public Obj
{
public:
	GameOver();
	~GameOver();
	void Update(void)override;
	void Draw(void)override;
};


