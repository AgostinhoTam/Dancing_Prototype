//=============================================================================
//�����蔻�菈�� [collision.cpp]
//Date:2023/10/30	Auther:�їS��
//=============================================================================
#include "collision.h"

//=============================================================================
// BB�ɂ�铖���蔻�菈��
// ��]�͍l�����Ȃ�
// �߂�l�F�������Ă���true
//=============================================================================
bool CollisionBB(D3DXVECTOR3 pos1, D3DXVECTOR3 size1, D3DXVECTOR3 scl1, D3DXVECTOR3 pos2, D3DXVECTOR3 size2, D3DXVECTOR3 scl2)
{
	D3DXVECTOR3 min1, max1;
	D3DXVECTOR3 min2, max2;

	min1.x = pos1.x - ((size1.x * scl1.x) / 2);
	min1.z = pos1.z - ((size1.z * scl1.z) / 2);
	min1.y = pos1.y - ((size1.y * scl1.y) / 2);
	max1.x = pos1.x + ((size1.x * scl1.x) / 2);
	max1.z = pos1.z + ((size1.z * scl1.z) / 2);
	max1.y = pos1.y + ((size1.y * scl1.y) / 2);


	min2.x = pos2.x - ((size2.x * scl2.x) / 2);
	min2.z = pos2.z - ((size2.z * scl2.z) / 2);
	min2.y = pos2.y - ((size2.y * scl2.y) / 2);
	max2.x = pos2.x + ((size2.x * scl2.x) / 2);
	max2.z = pos2.z + ((size2.z * scl2.z) / 2);
	max2.y = pos2.y + ((size2.y * scl2.y) / 2);

	//X���̔���
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Z���̔���
		if (min1.z < max2.z && max1.z > min2.z)
		{
			//Y���̔���
			if (min1.y < max2.y && max1.y > min2.y)
			{
				//�S�Ă̏�����TRUE�Ȃ�q�b�g����
				return true;
			}
		}
	}
	return false;
}