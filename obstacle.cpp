//===============================================
//障害物制御[obstacle.cpp]
//Date:2023/10/30	Auther:林祐也
//===============================================
#include "obstacle.h"
#include "Texture.h"
#include "planePolygon.h"
#include "polygon.h"
#include "collision.h"


Obstacle::~Obstacle()
{
	
}

void Obstacle::Update(void)
{
	//ここに当たり判定についてのやつを書く
}

void Obstacle::Draw(void)
{
	DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	
}

void Obstacle::DrawMap(void)
{
	DrawPolygon(GetModel(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld());
}
