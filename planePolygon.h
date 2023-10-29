//=============================================================================
//
// 地面処理 [planePolygon.h]
// Author : 
//
//=============================================================================
#pragma once

#include <d3dx9.h>
#include "renderer.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
struct PLANEPOLYGON
{
	D3DXVECTOR3		pos;		// ポリゴンの位置
	D3DXVECTOR3		rot;		// ポリゴンの向き(回転)
	D3DXVECTOR3		scl;		// ポリゴンの大きさ(スケール)

	D3DXMATRIX		mtxWorld;	// ワールドマトリックス
};

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitPlanePolygon(void);
void UninitPlanePolygon(void);
void UpdatePlanePolygon(void);
void DrawPlanePolygon(int texNo, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld, float U, float V, float UW, float VH);

