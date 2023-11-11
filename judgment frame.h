
//=============================================================================
//
// 地面処理 [judgment frame.h]
//Date:2023/10/29	Auther:林祐也
//=============================================================================
#pragma once

#include "obj.h"
#include "obstacle.h"
#include <vector>
//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define JF_POS	(D3DXVECTOR3(200.0f, 0.0f,0.0f))
#define JF_SIZE (12)

class JudgmentFrame : public Obj
{
private:
	std::vector<Obstacle> obstacles;
public:
	JudgmentFrame();
	~JudgmentFrame();
	void Update(void)override;
	void Draw(void)override;

	void SetObstacles(const std::vector<Obstacle>& pObstacles) {
		obstacles = pObstacles;
	}
};