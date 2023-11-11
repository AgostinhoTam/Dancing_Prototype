//=============================================================================
// �|���S���\������ [judgment frame.cpp]
//Date:2023/10/29	Auther:�їS��
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "judgment frame.h"
#include "texture.h"
#include "planePolygon.h"
#include "obstacle.h"


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
JudgmentFrame::JudgmentFrame()
{

	// �e�N�X�`������
	SetTexture(LoadTexture((char*)"data/TEXTURE/field000.jpg"));

	// �ʒu�E��]�E�X�P�[���̏����ݒ�

	SetPos(D3DXVECTOR3(0.0f, 200.0f, 0.0f));
	SetRot(D3DXVECTOR3(D3DX_PI * 0.45f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetVel(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetScl(D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetFlag(true);
}

//=============================================================================
// �I������
//=============================================================================
JudgmentFrame::~JudgmentFrame()
{
	obstacles.clear();
	// ���_�o�b�t�@�̉��
	if (g_VertexBuffer) {
		g_VertexBuffer->Release();
		g_VertexBuffer = NULL;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void JudgmentFrame::Update()
{

}

//=============================================================================
// �`�揈��
//=============================================================================
void JudgmentFrame::Draw()
{
	//DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	if (GetFlag())
	{
		CAMERA* pCamera = GetCamera();
		// Z��r�Ȃ�
		SetDepthEnable(false);

		//DrawUIPlanePolygon(GetTexture(), D3DXVECTOR3(GetPos().x, pCamera->pos.y - 200.0f, pCamera->pos.z + 100.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
		DrawPlanePolygon(GetTexture(), D3DXVECTOR3(GetPos().x+pCamera->pos.x, pCamera->pos.y - 200.0f, pCamera->pos.z + 100.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	}
}