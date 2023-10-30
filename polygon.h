//=============================================================================
//
// 地面処理 [polygon.h]
//Date:2023/10/29	Auther:林祐也
//=============================================================================
#pragma once

#include <d3dx9.h>
#include "renderer.h"
#include "model.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitPolygon(void);
void UninitPolygon(void);
void UpdatePolygon(void);
void DrawPolygon(DX11_MODEL Model, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld);
void DrawPlayerPolygon(DX11_MODEL Model, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld);

