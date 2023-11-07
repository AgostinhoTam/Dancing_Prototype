#include "collsionpoly.h"


CollisionPoly::CollisionPoly(D3DXVECTOR3 max, D3DXVECTOR3 min)
{
	m_ColPolygon[0] = D3DXVECTOR3(min.x, min.y, min.z);
	m_ColPolygon[1] = D3DXVECTOR3(max.x, min.y, min.z);
	m_ColPolygon[2] = D3DXVECTOR3(max.x, min.y, max.z);
	m_ColPolygon[3] = D3DXVECTOR3(min.x, min.y, max.z);
	m_ColPolygon[4] = D3DXVECTOR3(min.x, max.y, min.z);
	m_ColPolygon[5] = D3DXVECTOR3(max.x, max.y, min.z);
	m_ColPolygon[6] = D3DXVECTOR3(max.x, max.y, max.z);
	m_ColPolygon[7] = D3DXVECTOR3(min.x, max.y, max.z);
	m_max = max;
	m_min = min;
}

