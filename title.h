//===============================================
//タイトル制御[title.h]
//Date:2023/07/10	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"
#include "titleBG.h"
#include "player.h"
#include "map.h"
#include "obstacle.h"

//==================================
//クラス宣言
//==================================
class Title :public Obj
{
private:
	Obj* pTitleBG;
	Player* pPlayer;
	Map* pMap;
public:
	Title();
	~Title();
	void Update(void)override;
	void Draw(void)override;
};


