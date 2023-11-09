//=============================================================================
// �|���S���\������ [polygon.cpp]
//Date:2023/10/29	Auther:�їS��
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "polygon.h"
#include "texture.h"
#include "model.h"
#include "obj.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// ���_���

//=============================================================================
// ����������
//=============================================================================
HRESULT InitPolygon(void)
{
	//obj���f���̓ǂݍ���
	//LoadModel((char*)"data/MODEL/miku_01.obj", &g_Model);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitPolygon(void)
{
	//obj���f���̉��
	//UnloadModel(&g_Model);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdatePolygon(void)
{

}

//=============================================================================
// �`�揈��
//=============================================================================
//=============================================================================
// �|���S���f�[�^�ݒ�
// ���W�E�T�C�Y
//=============================================================================
//����
//texNo		: �e�N�X�`���̎��ʔԍ��itexture.h, texture.cpp ��LoadTexture�֐��̖߂�l�j
//Pos		: ���W
//Size		: �T�C�Y
//Rot		: ��]
//Scl		: �X�P�[��
//MtxWorld	: ���[���h�}�g���b�N�X(�|���S���̃��[���h�}�g���b�N�X��������)�A�l���Ȃ��œ���đ��v

void DrawPolygon(DX11_MODEL* Model,D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld)
{

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ���[���h�}�g���b�N�X�̏������i�P�ʍs������֐��j
	D3DXMatrixIdentity(&MtxWorld);

	// �X�P�[���𔽉f
	D3DXMatrixScaling(&mtxScl, Scl.x, Scl.y,Scl.z);

	//��1���� ��          ��2����      ��    ��3����
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxScl);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, Rot.y, Rot.x, Rot.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	// �ړ��𔽉f
	D3DXMatrixTranslation(&mtxTranslate, Pos.x, Pos.y, Pos.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);

	// ���[���h�}�g���b�N�X�̐ݒ�
	SetWorldMatrix(&MtxWorld);

	//obj���f���̕`��
	DrawModel(Model);
}
//=============================================================================
// �v���C���[�|���S���f�[�^�ݒ�
// ���W�E�T�C�Y�E�v���C���[�ǔ�
//=============================================================================
//����
//texNo		: �e�N�X�`���̎��ʔԍ��itexture.h, texture.cpp ��LoadTexture�֐��̖߂�l�j
//Pos		: ���W
//Size		: �T�C�Y
//Rot		: ��]
//Scl		: �X�P�[��
//MtxWorld	: ���[���h�}�g���b�N�X(�|���S���̃��[���h�}�g���b�N�X��������)�A�l���Ȃ��œ���đ��v
void DrawPlayerPolygon(DX11_MODEL Model, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld)
{
	//�J�������v���C���[�𒆐S��
	CAMERA* cam = GetCamera();
	SetCameraAT(Pos);

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ���[���h�}�g���b�N�X�̏������i�P�ʍs������֐��j
	D3DXMatrixIdentity(&MtxWorld);

	
	// �X�P�[���𔽉f
	D3DXMatrixScaling(&mtxScl, Scl.x, Scl.y, Scl.z);

	Model.m_MinVertex.x = Model.m_MinVertex.x * Scl.x;
	Model.m_MinVertex.y = Model.m_MinVertex.y * Scl.y;
	Model.m_MinVertex.z = Model.m_MinVertex.z * Scl.z;
	Model.m_MaxVertex.x = Model.m_MaxVertex.x * Scl.x;
	Model.m_MaxVertex.y = Model.m_MaxVertex.y * Scl.y;
	Model.m_MaxVertex.z = Model.m_MaxVertex.z * Scl.z;

	//��1���� ��          ��2����      ��    ��3����
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxScl);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, Rot.y, Rot.x, Rot.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	// �ړ��𔽉f
	D3DXMatrixTranslation(&mtxTranslate, Pos.x, Pos.y, Pos.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);

	// ���[���h�}�g���b�N�X�̐ݒ�
	SetWorldMatrix(&MtxWorld);


	//obj���f���̕`��
	DrawModel(&Model);
}

