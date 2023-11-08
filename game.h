//===============================================
//�Q�[������[game.h]
//Date:2023/09/05	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"
#include "notes.h"
#include "judgment frame.h"
///==================================
//�N���X�錾
//==================================
class Game :public Obj
{
private:
	Notes* pNotes;
	JudgmentFrame* pJF;
public:
	Game();
	~Game();
	void Update(void)override;
	void Draw(void)override;
};



