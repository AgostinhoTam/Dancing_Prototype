//===============================================
//ƒQ[ƒ€§Œä[score.h]
//Date:2023/10/27	Auther:—Ñ—S–ç
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//ƒNƒ‰ƒXéŒ¾
//==================================
class Score :public Obj
{
public:
	Score();
	~Score();
	void Update(void)override;
	void Draw(void)override;
};




