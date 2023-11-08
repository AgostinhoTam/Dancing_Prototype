//===============================================
//ƒQ[ƒ€§Œä[game.h]
//Date:2023/09/05	Auther:—Ñ—S–ç
//===============================================
#pragma once


#include "obj.h"
#include "renderer.h"
#include "notes.h"
#include "judgment frame.h"
///==================================
//ƒNƒ‰ƒXéŒ¾
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



