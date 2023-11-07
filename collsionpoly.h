/*===================================================================================
//ÇWí∏ì_êßå‰[collisionpoly.cpp]
//Date:2023/11/08	Auther:ÊùàÃêi
===================================================================================*/
#pragma once
#include "main.h"
#include "model.h"
class CollisionPoly {
private:
	D3DXVECTOR3 m_ColPolygon[8];
	D3DXVECTOR3 m_max;
	D3DXVECTOR3 m_min;
public:
	CollisionPoly(D3DXVECTOR3 max,D3DXVECTOR3 min);
	~CollisionPoly(){}
	bool ColPolyBB(DX11_MODEL object1, D3DXVECTOR3 pos1, DX11_MODEL object2, D3DXVECTOR3 pos2);
};