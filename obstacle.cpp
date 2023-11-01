//===============================================
//��Q������[obstacle.cpp]
//Date:2023/10/30	Auther:�їS��
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
	//�����ɓ����蔻��ɂ��Ă̂������
	
}

void Obstacle::Draw(void)
{
	DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
}
