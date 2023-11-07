//===============================================
//タイトル制御[defenseobj.cpp]
//Date:2023/10/29	Auther:林祐也
//===============================================
#include "defenseobj.h"
#include "polygon.h"

DefenseObj::DefenseObj()
{
	LoadModel((char*)"data/MODEL/dancing_color_03.obj", &model);
	SetPos(D3DXVECTOR3(-2300.0f, -500.0f, 0.0f));
	SetSize(D3DXVECTOR3(10.0f, 10.0f, 10.0f));
	SetScl(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

DefenseObj::~DefenseObj()
{
	UnloadModel(&model);
}

void DefenseObj::Update(void)
{

}

void DefenseObj::Draw(void)
{
	// ポリゴンの描画処理
	DrawPolygon(model, GetPos(), GetSize(), GetRot(),GetScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
