//=============================================================================
//
// �n�ʏ��� [notesjudge.h]
//Date:2023/10/29	Auther:�їS��
//=============================================================================
#pragma once

#include "obj.h"
#include "obstacle.h"
#include <vector>
#include "judgment frame.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	SIZE_X			(100.0f)					// �n�ʂ̃T�C�Y(X����)
#define	SIZE_Z			(100.0f)					// �n�ʂ̃T�C�Y(Z����)
#define NOTES_SIZE	(10.0f)
#define NOTES_VEL	(D3DXVECTOR3(1.0f,0.0f,0.0f))	// NOTES_VEL = JUDGME
#define JUDGMENTNOTES_VEL (D3DXVECTOR2(1.0f,0.0f))
class NotesJudge : public Obj
{
private:
	int m_judgeframe = 0;
public:
	NotesJudge();
	NotesJudge(int judgeframe);
	~NotesJudge();
	void Update(void)override;
	void Draw(void)override;
	int GetJudgeFrame() { return m_judgeframe; }
};