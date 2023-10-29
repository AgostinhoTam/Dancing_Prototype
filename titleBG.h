//===============================================
//タイトルバック制御[titleBG.h]
//Date:2023/07/10	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"

//==================================
//クラス宣言
//==================================
class TitleBG:public Obj
{
public:
	TitleBG();
	~TitleBG();
	void Update(void)override;
	void Draw(void)override;
};

