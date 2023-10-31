//===============================================
//�^�C�g������[title.cpp]
//Date:2023/07/10	Auther:�їS��
//===============================================
#include "title.h"
#include "titleBG.h"
#include "input.h"
#include "main.h"
#include "sound.h"
#include "polygon.h"
#include "planePolygon.h"
#include "camera.h"
#include "Texture.h"

Obj* pTitleBG;
D3DXVECTOR3 cameraPos;
//=============================================================================
// ����������
//=============================================================================
Title::Title()
{
	pTitleBG =new TitleBG();
	SetTexture(LoadTexture((char*)"data/TEXTURE/field000.jpg"));
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(100.0f, 100.0f, 100.0f));
	SetScl(D3DXVECTOR3(2.0f, 1.0f, 2.0f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	//SetSound(LoadSound((char*)"data/SOUND/BGM/BGM_Title.wav"));
	//SetVolume(GetSound(), 0.5f);//1.0��100��
	//PlaySound(GetSound(), 0);//���̐����ŉ񐔂����߂�A�O�ȉ��ɂȂ�Ɩ������[�v�ɂȂ�
}

//=============================================================================
// �I������
//=============================================================================
Title::~Title()
{
	
}

//=============================================================================
// �X�V����
//=============================================================================
void Title::Update()
{
	SetPos(*GetCameraPos()-D3DXVECTOR3(0.0f,0.0f,-250.0f));
	pTitleBG->Update();
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		//StopSound(GetSound());
		SetScene(SCENE_GAME);
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void Title::Draw(void)
{
	pTitleBG->Draw();
	// �|���S���̕`�揈��
	//DrawPolygon();

	//�`�揈��
	DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(),GetV(),GetUW(),GetVH());

	//DrawPlanePolygon(GetTexture(), GetPos()+D3DXVECTOR3(0.0f, 500.0f,0.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld());

	//2D�|���S���̕`��
	//DrawPlanePolygon();
}
