//=============================================================================
//
// �|���S���\������ [planePolygon.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "planePolygon.h"
#include "texture.h"
#include "camera.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	VALUE_MOVE		(5.0f)						// �ړ���
#define	VALUE_ROTATE	(D3DX_PI * 0.02f)			// ��]��
#define NUM_VERTEX		(4)							//�|���S���̒��_��

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// ���_���

static PLANEPOLYGON						g_PlanePolygon;			// �|���S���f�[�^
static int								g_TexNo;			    // �e�N�X�`���ԍ�

//=============================================================================
// ����������
//=============================================================================
HRESULT InitPlanePolygon(void)
{

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitPlanePolygon(void)
{
	// ���_�o�b�t�@�̉��
	if (g_VertexBuffer) {
		g_VertexBuffer->Release();
		g_VertexBuffer = NULL;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdatePlanePolygon(void)
{

}

//=============================================================================
// �`�揈��
//=============================================================================
//void DrawPlanePolygon(void)
//{
//	// ���_�o�b�t�@�ݒ�
//	UINT stride = sizeof(VERTEX_3D);
//	UINT offset = 0;
//	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);
//
//	// �v���~�e�B�u�g�|���W�ݒ�
//	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
//
//	// �e�N�X�`���ݒ�
//	GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_TexNo));
//
//
//	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;
//
//	// ���[���h�}�g���b�N�X�̏�����
//	D3DXMatrixIdentity(&g_PlanePolygon.mtxWorld);
//
//	// �X�P�[���𔽉f
//	D3DXMatrixScaling(&mtxScl, g_PlanePolygon.scl.x, g_PlanePolygon.scl.y, g_PlanePolygon.scl.z);
//	D3DXMatrixMultiply(&g_PlanePolygon.mtxWorld, &g_PlanePolygon.mtxWorld, &mtxScl);
//
//	// ��]�𔽉f
//	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_PlanePolygon.rot.y, g_PlanePolygon.rot.x, g_PlanePolygon.rot.z);
//	D3DXMatrixMultiply(&g_PlanePolygon.mtxWorld, &g_PlanePolygon.mtxWorld, &mtxRot);
//
//	// �ړ��𔽉f
//	D3DXMatrixTranslation(&mtxTranslate, g_PlanePolygon.pos.x, g_PlanePolygon.pos.y, g_PlanePolygon.pos.z);
//	D3DXMatrixMultiply(&g_PlanePolygon.mtxWorld, &g_PlanePolygon.mtxWorld, &mtxTranslate);
//
//	// ���[���h�}�g���b�N�X�̐ݒ�
//	SetWorldMatrix(&g_PlanePolygon.mtxWorld);
//
//	// �|���S���`��
//	GetDeviceContext()->Draw(NUM_VERTEX, 0);
//}
//=============================================================================
// ���ʃ|���S���f�[�^�ݒ�
// ���W�E�T�C�Y�EUV�w��
//=============================================================================
//����
//texNo		: �e�N�X�`���̎��ʔԍ��itexture.h, texture.cpp ��LoadTexture�֐��̖߂�l�j
//Pos		: ���W
//Size		: �T�C�Y
//Rot		: ��]
//Scl		: �X�P�[��
//MtxWorld	: ���[���h�}�g���b�N�X(�|���S���̃��[���h�}�g���b�N�X��������)�A�l���Ȃ��œ���đ��v
//U			: UV�l�n�_
//V			: UV�l�n�_
//UW		: UV�l����
//VH		: UV�l����
void DrawPlanePolygon(int texNo, D3DXVECTOR3 Pos, D3DXVECTOR3 Size,D3DXVECTOR3 Rot,D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld ,float U, float V, float UW, float VH)
{
	VERTEX_3D g_VertexArray[4] = {
	{D3DXVECTOR3(-Size.x/2,Size.y / 2, Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V)},
	{D3DXVECTOR3(Size.x / 2,Size.y / 2,  Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V)},
	{D3DXVECTOR3(-Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V + VH)},
	{D3DXVECTOR3(Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V + VH)}};

	//------------------------------------------------------------------------------------
		
	// ���_�o�b�t�@����
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;;
	bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	// �O���[�o���̒��_�z�񂩂璸�_�o�b�t�@������
	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = g_VertexArray;

	GetDevice()->CreateBuffer(&bd, &sd, &g_VertexBuffer);

	//-------------------------------------------------------------------------------------

	// ���_�o�b�t�@�ݒ�
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// �v���~�e�B�u�g�|���W�ݒ�
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// �e�N�X�`���ݒ�
	GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(texNo));

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&MtxWorld);

	// �X�P�[���𔽉f
	D3DXMatrixScaling(&mtxScl, Scl.x, Scl.y, Scl.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxScl);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, Rot.y, Rot.x, Rot.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	// �ړ��𔽉f
	D3DXMatrixTranslation(&mtxTranslate, Pos.x, Pos.y, Pos.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);
	// ���[���h�}�g���b�N�X�̐ݒ�
	SetWorldMatrix(&MtxWorld);

	// �|���S���`��
	GetDeviceContext()->Draw(NUM_VERTEX, 0);
}