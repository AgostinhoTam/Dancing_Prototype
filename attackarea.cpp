//===============================================
//UŒ‚”ÍˆÍ§Œä[attackarea.cpp]
//Date:2023/11/08	Author:æˆÌi
//===============================================
#include "attackarea.h"
#include "model.h"
#include "input.h"
#include "polygon.h"

CAttackArea::CAttackArea(){
	LoadModel((char*)"data/MODEL/torus.obj", &model);
	SetSize(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	SetScl(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

CAttackArea::~CAttackArea()
{
	UnloadModel(&model);
}


void CAttackArea::Update(void)
{
	DecreaseCurRng();
	if (GetKeyboardTrigger(DIK_SPACE)) {
 		IncreaseCurRng(SPD);
	}
	SetCurRng(m_CurRng);
}

void CAttackArea::UpdatePos(D3DXVECTOR3 pos)
{
	SetPos(pos);
}

void CAttackArea::Draw(void)
{
	// ƒ|ƒŠƒSƒ“‚Ì•`‰æˆ—
	DrawPlayerPolygon(model, GetPos(), GetSize(), GetRot(),GetScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
