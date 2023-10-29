//===============================================
//ƒQ[ƒ€§Œä[map.h]
//Date:2023/10/27	Auther:—Ñ—S–ç
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//ƒNƒ‰ƒXéŒ¾
//==================================
class Map :public Obj
{
public:
	Map();
	~Map();
	void Update(void)override;
	void Draw(void)override;
};





