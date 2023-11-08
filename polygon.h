//=============================================================================
//
// �n�ʏ��� [polygon.h]
//Date:2023/10/29	Auther:�їS��
//=============================================================================
#pragma once

#include <d3dx9.h>
#include "renderer.h"
#include "model.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitPolygon(void);
void UninitPolygon(void);
void UpdatePolygon(void);
void DrawPolygon(DX11_MODEL Model, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld);
void DrawPlayerPolygon(DX11_MODEL Model, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld);

