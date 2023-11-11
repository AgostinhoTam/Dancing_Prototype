//===============================================
//çUåÇîÕàÕêßå‰[attackarea.cpp]
//Date:2023/11/08	Author:ÊùàÃêi
//===============================================
#include "attackarea.h"
#include "model.h"
#include "input.h"
#include "polygon.h"

CAttackArea::CAttackArea(){
	LoadModel((char*)"data/MODEL/torus.obj", &model);
	SetSize(D3DXVECTOR3(13.0f, 13.0f, 13.0f));
	SetScl(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_colpoly = new CollisionPoly(model.m_MaxVertex, model.m_MinVertex);
}

CAttackArea::~CAttackArea()
{

	UnloadModel(&model);
}


void CAttackArea::Update(void)
{
 	DecreaseCurRng();
	//if(GetKeyboardTrigger(DIK_SPACE))
	if (GetKeyboardTrigger(DIK_W)|| GetKeyboardTrigger(DIK_A)|| GetKeyboardTrigger(DIK_S)|| GetKeyboardTrigger(DIK_D) || GetKeyboardTrigger(DIK_W)||GetKeyboardTrigger(DIK_SPACE)) {
 		IncreaseCurRng(SPD);
	}
	UpdateCurRng();

}

void CAttackArea::UpdatePos(D3DXVECTOR3 pos)
{
	SetPos(pos);
}

void CAttackArea::Draw(void)
{
	// É|ÉäÉSÉìÇÃï`âÊèàóù
	DrawPolygon(&model, GetPos(), GetSize(), GetRot(),GetScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());
}

void CAttackArea::PolyUpdate(DX11_MODEL* model)
{
	
}
