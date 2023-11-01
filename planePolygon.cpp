//=============================================================================
//�|���S���\������ [planePolygon.cpp]
//Date:2023/10/31	Auther:�їS��
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
#define NUM_VERTEX		(4)							//�|���S���̒��_��


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// ���_���

static MATERIAL			Material;			// �}�e���A���f�[�^

//=============================================================================
// ����������
//=============================================================================
HRESULT InitPlanePolygon(void)
{
	// �}�e���A���ݒ�
	ZeroMemory(&Material, sizeof(Material));
	Material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//�g�U�F
	Material.Ambient = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	//���F
	Material.Emission = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	//���Ȕ����F
	Material.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//���X�y�L�����[�͖��Ή�
	Material.Shininess = 20;								//���X�y�L�����[�͖��Ή�
	Material.noTexSampling = 0;								//�e�N�X�`���L��:0 or �e�N�X�`������:1
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

	// �}�e���A���̃Z�b�g
	SetMaterial(Material);

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

//=============================================================================
// UI�ŕ��ʃ|���S���f�[�^�ݒ�
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
void DrawUIPlanePolygon(int texNo, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld, float U, float V, float UW, float VH)
{

	//�J�����̏����擾
	CAMERA* cam = GetCamera();
	
	float vx, vz;
	vx = cam->pos.x - cam->at.x;
	vz = cam->pos.z - cam->at.z;

	float side = cam->len = sqrtf(vx * vx + vz * vz);
	float z1 = Pos.z + (side * cosf(cam->rot.z));
	float z2 = Pos.z + (side * sinf(cam->rot.z));
	float x1 = Pos.x + (side * cosf(cam->rot.x));
	float x2 = Pos.x + (side * sinf(cam->rot.x));

	VERTEX_3D g_VertexArray[4] = {
	{D3DXVECTOR3(-Size.x / 2,Size.y / 2, Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V)},
	{D3DXVECTOR3(Size.x / 2,Size.y / 2,  Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V)},
	{D3DXVECTOR3(-Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V + VH)},
	{D3DXVECTOR3(Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V + VH)} };

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

	// �}�e���A���̃Z�b�g
	SetMaterial(Material);

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
	D3DXMatrixTranslation(&mtxTranslate, cam->pos.x, cam->pos.y+ Pos.y, cam->pos.z + side);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);
	// ���[���h�}�g���b�N�X�̐ݒ�
	SetWorldMatrix(&MtxWorld);

	// �|���S���`��
	GetDeviceContext()->Draw(NUM_VERTEX, 0);
}