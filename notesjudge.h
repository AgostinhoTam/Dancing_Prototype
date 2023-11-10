//=============================================================================
//
// 地面処理 [notes.h]
//Date:2023/10/29	Auther:林祐也
//=============================================================================
#pragma once

#include "obj.h"
#include "obstacle.h"
#include <vector>
#include "judgment frame.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	SIZE_X			(100.0f)					// 地面のサイズ(X方向)
#define	SIZE_Z			(100.0f)					// 地面のサイズ(Z方向)
#define NOTES_SIZE	(10.0f)
#define NOTES_VEL	(D3DXVECTOR3(1.0f,0.0f,0.0f))	// NOTES_VEL = JUDGME
#define JUDGMENTNOTES_VEL (D3DXVECTOR2(1.0f,0.0f))
class NotesJudge : public Obj
{
private:
	std::vector<Obstacle> obstacles;
	JudgmentFrame* pJF;
public:
	NotesJudge();
	~NotesJudge();
	void Update(void)override;
	void Draw(void)override;

	void SetObstacles(const std::vector<Obstacle>& pObstacles) {
		obstacles = pObstacles;
	}
};

