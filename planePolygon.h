//=============================================================================
// 2D�|���S���`�揈�� [planePolygon.h]
//Date:2023/10/29	Auther:�їS��
//=============================================================================
#pragma once

#include <d3dx9.h>
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
struct PLANEPOLYGON
{
	D3DXVECTOR3		pos;		// �|���S���̈ʒu
	D3DXVECTOR3		rot;		// �|���S���̌���(��])
	D3DXVECTOR3		scl;		// �|���S���̑傫��(�X�P�[��)

	D3DXMATRIX		mtxWorld;	// ���[���h�}�g���b�N�X
};

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitPlanePolygon(void);
void UninitPlanePolygon(void);
void UpdatePlanePolygon(void);
void DrawPlanePolygon(int texNo, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld, float U, float V, float UW, float VH);
void DrawUIPlanePolygon(int texNo, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld, float U, float V, float UW, float VH);
