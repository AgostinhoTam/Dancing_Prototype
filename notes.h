#pragma once
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
#include "notesjudge.h"
enum JUDGE {
	PERFECT = 0,
	GREAT,
	GOOD,
	BAD,
	MAX_JUDGE
};

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	SIZE_X			(100.0f)					// 地面のサイズ(X方向)
#define	SIZE_Z			(100.0f)					// 地面のサイズ(Z方向)
#define NOTES_SIZE	(10.0f)
#define NOTES_VEL	(D3DXVECTOR3(4.0f,0.0f,0.0f))
#define JUDGMENTNOTES_VEL (D3DXVECTOR3(1.0f,0.0f,0.0f))
class Notes : public Obj
{
private:
	JudgmentFrame* pJF;
	std::vector<NotesJudge> pNotesJudge;
public:
	Notes();
	~Notes();
	void Update(void)override;
	void Draw(void)override;

};