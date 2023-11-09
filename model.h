//=============================================================================
//
// ���f���̏��� [model.h]
//  Date:2023/11/08 Author :杈̐i
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"
#define	SCALE_MODEL			(10.0f)					// �X�P�[���̒����iCG���f�����O�\�t�g�ɂ��̂Ŏ��O�Œ�������j

//*********************************************************
// �\����
//*********************************************************

// �}�e���A���\����
struct DX11_MODEL_MATERIAL
{
	MATERIAL					Material;
	ID3D11ShaderResourceView	*Texture;
};

// �`��T�u�Z�b�g�\����
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
// �v���g�^�C�v�錾
//*****************************************************************************
void LoadModel( char *FileName, DX11_MODEL *Model );
void UnloadModel( DX11_MODEL *Model );
void DrawModel( DX11_MODEL *Model );