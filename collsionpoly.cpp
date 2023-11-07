/*===================================================================================
//�W���_����[collisionpoly.h]
//Date:2023/11/08	Author:杈̐i
===================================================================================*/
#include "collsionpoly.h"



CollisionPoly::CollisionPoly(D3DXVECTOR3 max, D3DXVECTOR3 min)
{
	m_max = max;
	m_min = min;
	m_ColPolygon[0] = D3DXVECTOR3(min.x, min.y, min.z);
	m_ColPolygon[1] = D3DXVECTOR3(max.x, min.y, min.z);
	m_ColPolygon[2] = D3DXVECTOR3(max.x, min.y, max.z);
	m_ColPolygon[3] = D3DXVECTOR3(min.x, min.y, max.z);
	m_ColPolygon[4] = D3DXVECTOR3(min.x, max.y, min.z);
	m_ColPolygon[5] = D3DXVECTOR3(max.x, max.y, min.z);
	m_ColPolygon[6] = D3DXVECTOR3(max.x, max.y, max.z);
	m_ColPolygon[7] = D3DXVECTOR3(min.x, max.y, max.z);
}
//=============================================================================
// �����RD�|���R���ݒ�
// ���W�E�T�C�Y
//=============================================================================
//����
//object1	: ���f��
//pos1		: �|���R�����W
//object2	: ��r�Ώۃ��f��
//pos2		: ��r�Ώۃ|���R�����W


bool CollisionPoly::ColPolyBB(DX11_MODEL object1, D3DXVECTOR3 pos1, DX11_MODEL object2, D3DXVECTOR3 pos2)
{
	
	D3DXVECTOR3 min1 = object1.m_MinVertex + pos1;
	D3DXVECTOR3 max1 = object1.m_MaxVertex + pos1;
	D3DXVECTOR3 min2 = object2.m_MinVertex + pos2;
	D3DXVECTOR3 max2 = object2.m_MaxVertex + pos2;
	// X���̔���
	if (max1.x < min2.x || min1.x > max2.x) return false;

	// Z���̔���
	if (max1.z < min2.z || min1.z > max2.z) return false;

	// Y���̔���
	if (max1.y < min2.y || min1.y > max2.y) return false;

	return true;

}

