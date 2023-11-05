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
#include "enemy.h"
//==================================
//�N���X�錾
//==================================
class Title :public Obj
{
private:
	Obj* pTitleBG=nullptr;
	Player* pPlayer=nullptr;
	Map* pMap=nullptr;
	Enemy* pEnemy=nullptr;

public:
	Title();
	~Title();
	void Update(void)override;
	void Draw(void)override;
	Map& GetMap() { return *pMap; }
};


