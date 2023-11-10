//=============================================================================
// �|���S���\������ [notesjudge.cpp]
//Date:2023/10/29	Auther:�їS��
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "notesjudge.h"
#include "texture.h"
#include "notesjudge.h"
#include "planePolygon.h"
#include "obstacle.h"
#include "collision.h"
#include "judgment frame.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
//static ID3D11Buffer* g_VertexBuffer = NULL;	// ���_���
// 
//=============================================================================
// ����������
//=============================================================================
NotesJudge::NotesJudge()
{
	// �e�N�X�`������
	SetTexture(LoadTexture((char*)"data/TEXTURE/TuachScore_Set.png"));

	// �ʒu�E��]�E�X�P�[���̏����ݒ�
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetRot(D3DXVECTOR3(0.45f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(10.0f, 10.0f, 0.0f));
	SetScl(D3DXVECTOR3(10.0f, 10.0f, 0.0f));
	SetNJFlag(false);
	SetFlag(false);
	SetCnt(0);
	SetU(0.0f);
	SetV(0.0f);
	SetUW(0.0);
	SetVH(0.0f);
	
}

//=============================================================================
// �I������
//=============================================================================
NotesJudge::~NotesJudge()
{
	obstacles.clear();
}

//=============================================================================
// �X�V����
//=============================================================================
void NotesJudge::Update()
{
	if (GetFlag())
	{
		SetCnt(GetCnt() + 1);
		SetPosY(GetPosY() + GetVelY());
	}

		if (GetKeyboardTrigger(DIK_SPACE))
		{
			if (GetCnt() > 240 && GetCnt() < 380)
			{
				SetNJFlag(true);
				SetUW(1.0 / 4);
				SetVH(1.0);

			}
			else if (GetCnt() > 190 && GetCnt() < 239)
			{
				SetNJFlag(true);
				SetU(1.0f / 4);
				SetUW(1.0 / 4);
				SetVH(1.0);

			}
			else if (GetCnt() > 370 && GetCnt() < 400)
			{
				SetNJFlag(true);
				SetU(1.0f / 2);
				SetUW(1.0 / 4);
				SetVH(1.0);

			}
			else if (GetCnt() < 190 || GetCnt() > 380)
			{
				SetNJFlag(true);
				SetU(0.75f);
				SetUW(1.0 / 4);
				SetVH(1.0);
			}

		}
		if (GetCnt() > SCREEN_WIDTH)
		{
			SetNJFlag(false);
			SetCnt(0);
			SetFlag(false);
		}
		if (!GetFlag())
		{
			SetPos(D3DXVECTOR3(200.0f, 0.0f, 0.0f));
			SetVelY(0.0f);
		}
		if (GetNJFlag())
		{
			SetVelY(1.0f);
		}

}

//=============================================================================
// �`�揈��
//=============================================================================
void NotesJudge::Draw()
{
	if (GetNJFlag())
	{
		DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	}
}

