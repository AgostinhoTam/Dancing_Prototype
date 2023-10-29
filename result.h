//===============================================
//タイトル制御[result.h]
//Date:2023/07/10	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//クラス宣言
//==================================
class Result :public Obj
{
public:
	Result();
	~Result();
	void Update(void)override;
	void Draw(void)override;
};


