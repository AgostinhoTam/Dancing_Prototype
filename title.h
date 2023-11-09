//===============================================
//タイトル制御[title.h]
//Date:2023/07/10	Auther:林祐也
//===============================================
#pragma once
#include "obj.h"
#include "player.h"
#include "map.h"
#include "defenseobj.h"
#include "enemy.h"
//==================================
//クラス宣言
//==================================
class Title :public Obj
{
private:
	Obj* pTitleBG = nullptr;
	Player* pPlayer = nullptr;
	Map* pMap = nullptr;
	DefenseObj* pDefObj = nullptr;
	std::vector<Enemy*> Enemies;
	int m_frame = 0;
public:
	Title();
	~Title();
	void Update(void)override;
	void Draw(void)override;
	void GenerateEnemy();
	void GenerateEnemy(float x, float z);
	int GetFrame() { return m_frame; }
	void FrameAdd() { m_frame++; }
	void SetFrameZero() { m_frame = 0; }
	Map& GetMap() { return *pMap; }
	std::vector<Enemy*>& GetEnemy() { return Enemies; }
	DefenseObj& GetDefObj() { return *pDefObj; }
	
};


