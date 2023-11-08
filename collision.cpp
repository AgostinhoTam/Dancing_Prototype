//=============================================================================
//当たり判定処理 [collision.cpp]
//Date:2023/10/30	Auther:林祐也
//=============================================================================
#include "collision.h"

//=============================================================================
// BBによる当たり判定処理
// 回転は考慮しない
// 戻り値：当たってたらtrue
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

	//X軸の判定
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Z軸の判定
		if (min1.z < max2.z && max1.z > min2.z)
		{
			//Y軸の判定
			if (min1.y < max2.y && max1.y > min2.y)
			{
				//全ての条件がTRUEならヒット判定
				return true;
			}
		}
	}
	return false;
}
bool CollisionPerfectBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
	//pos1とpos2をつなぐベクトルを作る
	D3DXVECTOR2 vDistance = pos1 - pos2;

	//vDistanceのベクトル長を得る
	float length;
	length = D3DXVec2Length(&vDistance);


	if (length < 60 && length > 50 && pos1.x < pos2.x) // 数字を大きくすると判定が左にずれる
	{
		return true;
	}
	else if (length < 60 && pos1.x <= pos2.x)
	{
		return true;
	}
	else if (pos2.x <= pos1.x && pos1.x < 280)
	{
		return true;
	}


	return false;
}
bool CollisionFastBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
	//pos1とpos2をつなぐベクトルを作る
	D3DXVECTOR2 vDistance = pos1 - pos2;

	//vDistanceのベクトル長を得る
	float length;
	length = D3DXVec2Length(&vDistance);

	if (length < 100 && length > 51 && pos1.x < pos2.x)
	{
		return true;
	}

	return false;
}
bool CollisionFlontMissBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
	//pos1とpos2をつなぐベクトルを作る
	D3DXVECTOR2 vDistance = pos1 - pos2;

	//vDistanceのベクトル長を得る
	float length;
	length = D3DXVec2Length(&vDistance);

	if (length < SCREEN_WIDTH && length > 50 && pos1.x < pos2.x)
	{
		return true;
	}

	return false;
}
bool CollisionBackMissBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
	//pos1とpos2をつなぐベクトルを作る
	D3DXVECTOR2 vDistance = pos1 - pos2;

	//vDistanceのベクトル長を得る
	float length;
	length = D3DXVec2Length(&vDistance);

	if (pos1.x > pos2.x + 100)
	{
		return true;
	}

	return false;
}