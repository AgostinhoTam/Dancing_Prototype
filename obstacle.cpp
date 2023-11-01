//===============================================
//áŠQ•¨§Œä[obstacle.cpp]
//Date:2023/10/30	Auther:—Ñ—S–ç
//===============================================
#include "obstacle.h"
#include "Texture.h"
#include "planePolygon.h"
#include "collision.h"

Obstacle::Obstacle()
{
	SetTexture(LoadTexture((char*)"data/TEXTURE/field000.jpg"));
}

Obstacle::~Obstacle()
{

}

void Obstacle::Update(void)
{
	//‚±‚±‚É“–‚½‚è”»’è‚É‚Â‚¢‚Ä‚Ì‚â‚Â‚ğ‘‚­
	
}

void Obstacle::Draw(void)
{
	DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
}
