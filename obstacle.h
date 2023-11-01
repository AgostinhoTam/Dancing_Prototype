//===============================================
//áŠQ•¨§Œä[obstacle.h]
//Date:2023/10/30	Auther:—Ñ—S–ç
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//ƒNƒ‰ƒXéŒ¾
//==================================
class Obstacle :public Obj
{
public:
	Obstacle();
	~Obstacle();
	void Update(void)override;
	void Draw(void)override;
};
