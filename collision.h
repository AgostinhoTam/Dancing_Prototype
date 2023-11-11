#pragma once
//=============================================================================
//ìñÇΩÇËîªíËèàóù [collision.h]
//Date:2023/10/30	Auther:ó—óSñÁ
//=============================================================================
#pragma once

#include <d3dx9.h>
#include "renderer.h"
bool CollisionBB(D3DXVECTOR3 pos1, D3DXVECTOR3 size1, D3DXVECTOR3 scl1, D3DXVECTOR3 pos2, D3DXVECTOR3 size2, D3DXVECTOR3 scl2);
bool CollisionPerfectBC(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
bool CollisionGreatBC(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
bool CollisionGoodBC(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
bool CollisionMissBC(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
bool CollisionBB(D3DXVECTOR3 pos1, D3DXVECTOR3 size1, D3DXVECTOR3 scl1, D3DXVECTOR3 pos2, D3DXVECTOR3 size2, D3DXVECTOR3 scl2);