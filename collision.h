#pragma once
//=============================================================================
//ìñÇΩÇËîªíËèàóù [collision.h]
//Date:2023/10/30	Auther:ó—óSñÁ
//=============================================================================
#pragma once

#include <d3dx9.h>
#include "renderer.h"

bool CollisionBB(D3DXVECTOR3 pos1, D3DXVECTOR3 size1, D3DXVECTOR3 scl1, D3DXVECTOR3 pos2, D3DXVECTOR3 size2, D3DXVECTOR3 scl2);