#pragma once
#include "main.h"
class CollisionPoly {
private:
	D3DXVECTOR3 m_ColPolygon[8];
	D3DXVECTOR3 m_max;
	D3DXVECTOR3 m_min;
public:
	CollisionPoly(D3DXVECTOR3 max,D3DXVECTOR3 min);
	~CollisionPoly(){}
};