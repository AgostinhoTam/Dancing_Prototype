//=============================================================================
//
// �|���S���\������ [polygon.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "polygon.h"
#include "texture.h"
#include "model.h"

// �ǂ�������

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	VALUE_MOVE		(5.0f)						// �ړ���
#define	VALUE_ROTATE	(D3DX_PI * 0.02f)			// ��]��
#define VALUE_DIRECTION_X	(D3DX_PI*0.5f)
#define VALUE_DIRECTION_Z (D3DX_PI*1.0f)
#define JUMP_TIME_MAX (60)			//�W�����v�̎���

#define	SIZE_X			(100.0f)					// �n�ʂ̃T�C�Y(X����)
#define	SIZE_Z			(100.0f)					// �n�ʂ̃T�C�Y(Z����)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexPolygon(void);


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// ���_���

static POLYGON						g_Polygon;			// �|���S���f�[�^
static DX11_MODEL					g_Model;			// ���f���ǂݍ���

static int jumpCnt = 0;
static bool jumpFlag = false;


int abc;

//=============================================================================
// ����������
//=============================================================================
HRESULT InitPolygon(void)
{
	//obj���f���̓ǂݍ���
	LoadModel((char*)"data/MODEL/miku_01.obj", &g_Model);

	// �ʒu�E��]�E�X�P�[���̏����ݒ�
	g_Polygon.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Polygon.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Polygon.scl = D3DXVECTOR3(10.0f, 10.0f, 10.0f);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitPolygon(void)
{
	//obj���f���̉��
	UnloadModel(&g_Model);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdatePolygon(void)
{
	CAMERA* cam = GetCamera();
	SetCameraAT(g_Polygon.pos);
	// ��]�������Ⴄ
	if (GetKeyboardPress(DIK_LEFT))
	{
		g_Polygon.rot.y -= VALUE_ROTATE;
	}
	if (GetKeyboardPress(DIK_RIGHT))
	{
		g_Polygon.rot.y += VALUE_ROTATE;
	}
	if (GetKeyboardPress(DIK_UP))
	{
		g_Polygon.rot.x -= VALUE_ROTATE;
	}
	if (GetKeyboardPress(DIK_DOWN))
	{
		g_Polygon.rot.x += VALUE_ROTATE;
	}

	if (GetKeyboardPress(DIK_RETURN))
	{
		g_Polygon.rot.y = g_Polygon.rot.x = 0.0f;
	}

	if (GetKeyboardPress(DIK_W))
	{
		g_Polygon.pos.z += VALUE_MOVE;
		g_Polygon.rot.y = 0.0f;
	}
	if (GetKeyboardPress(DIK_S))
	{
		g_Polygon.pos.z -= VALUE_MOVE;
		g_Polygon.rot.y = -VALUE_DIRECTION_Z;
	}
	if (GetKeyboardPress(DIK_A))
	{
		g_Polygon.pos.x -= VALUE_MOVE;
		g_Polygon.rot.y = -VALUE_DIRECTION_X;
	}
	if (GetKeyboardPress(DIK_D))
	{
		g_Polygon.pos.x += VALUE_MOVE;
		g_Polygon.rot.y = VALUE_DIRECTION_X;
	}

	//�W�����v���Ă��Ȃ���
	if (!jumpFlag)
	{//�W�����v
		if (GetKeyboardPress(DIK_SPACE))
		{
			jumpFlag = true;//�W�����v�t���O��true��
		}
	}
	else if (jumpFlag)//�W�����v��
	{
		jumpCnt++;

		if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 5)
		{
			g_Polygon.pos.y += 3.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 4)
		{
			g_Polygon.pos.y += 2.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 3)
		{
			g_Polygon.pos.y += 1.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 2)
		{
			g_Polygon.pos.y -= 1.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 1)
		{
			g_Polygon.pos.y -= 2.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX)
		{
			g_Polygon.pos.y -= 3.0f;
		}
		else if (jumpCnt >= JUMP_TIME_MAX + 10)//���n��
		{
			g_Polygon.pos.y = 0;
			jumpFlag = false;
			jumpCnt = 0;
		}
	}

#ifdef _DEBUG	// �f�o�b�O����\������
	char* str = GetDebugStr();
	sprintf(&str[strlen(str)], " rotX:%.2f rotY:%.2f", g_Polygon.rot.x, g_Polygon.rot.y);

#endif
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawPolygon(void)
{
	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ���[���h�}�g���b�N�X�̏������i�P�ʍs������֐��j
	D3DXMatrixIdentity(&g_Polygon.mtxWorld);

	// �X�P�[���𔽉f
	D3DXMatrixScaling(&mtxScl, g_Polygon.scl.x, g_Polygon.scl.y, g_Polygon.scl.z);

	//��1���� ��          ��2����      ��    ��3����
	D3DXMatrixMultiply(&g_Polygon.mtxWorld, &g_Polygon.mtxWorld, &mtxScl);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Polygon.rot.y, g_Polygon.rot.x, g_Polygon.rot.z);
	D3DXMatrixMultiply(&g_Polygon.mtxWorld, &g_Polygon.mtxWorld, &mtxRot);

	// �ړ��𔽉f
	D3DXMatrixTranslation(&mtxTranslate, g_Polygon.pos.x, g_Polygon.pos.y, g_Polygon.pos.z);
	D3DXMatrixMultiply(&g_Polygon.mtxWorld, &g_Polygon.mtxWorld, &mtxTranslate);

	// ���[���h�}�g���b�N�X�̐ݒ�
	SetWorldMatrix(&g_Polygon.mtxWorld);

	//obj���f���̕`��
	DrawModel(&g_Model);
}



