//=============================================================================
//
// モデルの処理 [model.h]
//  Date:2023/11/08 Author :譚偉進
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"
#define	SCALE_MODEL			(10.0f)					// スケールの調整（CGモデリングソフトによるので自前で調整する）

//*********************************************************
// 構造体
//*********************************************************

// マテリアル構造体
struct DX11_MODEL_MATERIAL
{
	MATERIAL					Material;
	ID3D11ShaderResourceView	*Texture;
};

// 描画サブセット構造体
struct DX11_SUBSET
{
	unsigned short	StartIndex;
	unsigned short	IndexNum;
	DX11_MODEL_MATERIAL	Material;
};

struct DX11_MODEL
{
	ID3D11Buffer*	VertexBuffer;
	ID3D11Buffer*	IndexBuffer;

	DX11_SUBSET		*SubsetArray;
	unsigned short	SubsetNum;

	D3DXVECTOR3		m_MinVertex;
	D3DXVECTOR3		m_MaxVertex;
};



//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
void LoadModel( char *FileName, DX11_MODEL *Model );
void UnloadModel( DX11_MODEL *Model );
void DrawModel( DX11_MODEL *Model );