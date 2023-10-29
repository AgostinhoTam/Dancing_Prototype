//===============================================
//タイトル制御[resultBG.h]
//Date:2023/07/31	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

///==================================
//クラス宣言
//==================================
class ResultBG :public Obj
{
public:
	ResultBG();
	~ResultBG();
	void Update(void)override;
	void Draw(void)override;
};


