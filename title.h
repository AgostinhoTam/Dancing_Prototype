//===============================================
//�^�C�g������[title.h]
//Date:2023/07/10	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"
#include "titleBG.h"
#include "player.h"
#include "map.h"
#include "obstacle.h"

//==================================
//�N���X�錾
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


