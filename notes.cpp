//=============================================================================
// �|���S���\������ [notes.cpp]
//Date:2023/10/29	Auther:�їS��
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "notes.h"
#include "texture.h"
#include "notes.h"
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
Notes::Notes()
{
	// �e�N�X�`������
	SetTexture(LoadTexture((char*)"data/TEXTURE/field001.jpg"));

	// �ʒu�E��]�E�X�P�[���̏����ݒ�
	SetPos(D3DXVECTOR3(-100.0f, 0.0f, 0.0f));
	SetNotesPos(D3DXVECTOR2(-100.0f, 0.0f));
	SetRot(D3DXVECTOR3(0.45f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(10.0f, 10.0f, 0.0f));
	SetVel(NOTES_VEL);
	SetScl(D3DXVECTOR3(10.0f, 10.0f, 0.0f));
	SetFlag(true);
}

//=============================================================================
// �I������
//=============================================================================
Notes::~Notes()
{
	obstacles.clear();
	//// ���_�o�b�t�@�̉��
	//if (g_VertexBuffer) {
	//	g_VertexBuffer->Release();
	//	g_VertexBuffer = NULL;
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void Notes::Update()
{
	SetPos(GetPos() + GetVel());
	SetNotesPos(GetNotesPos() + JUDGMENTNOTES_VEL);

	//if (GetKeyboardTrigger(DIK_SPACE))
	{
		if (CollisionPerfectBC(GetNotesPos(), JF_POS))
		{
			SetTexture(LoadTexture((char*)"data/TEXTURE/white_000.jpg"));
			//SetFlag(false); // �p�[�t�F�N�g
		}
		else if (CollisionFastBC(GetNotesPos(), JF_POS))
		{
			SetTexture(LoadTexture((char*)"data/TEXTURE/blue_000.jpg"));
			//SetFlag(false); //fast
		}
		else if ((CollisionFlontMissBC(GetNotesPos(), JF_POS)))
		{
			SetTexture(LoadTexture((char*)"data/TEXTURE/black_000.jpg"));
			//SetFlag(false);//miss
		}
		else if (CollisionBackMissBC(GetNotesPos(), JF_POS))
		{
			SetTexture(LoadTexture((char*)"data/TEXTURE/black_000.jpg"));//miss
			//SetFlag(false);
		}
		else
		{
			//SetVel(D3DXVECTOR3(0.0f, 0.0f, 0.0f));// �m�F�p���肵����~�܂�
			SetTexture(LoadTexture((char*)"data/TEXTURE/red_000.jpg"));
			//SetFlag(false);//late
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void Notes::Draw()
{
	if (GetFlag())
	{
		DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	}
}

