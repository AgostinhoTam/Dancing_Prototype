//===============================================
//タイトル制御[title.cpp]
//Date:2023/07/10	Auther:林祐也
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
// 初期化処理
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
	//SetVolume(GetSound(), 0.5f);//1.0が100％
	//PlaySound(GetSound(), 0);//後ろの数字で回数を決める、０以下になると無限ループになる
}

//=============================================================================
// 終了処理
//=============================================================================
Title::~Title()
{
	
}

//=============================================================================
// 更新処理
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
// 描画処理
//=============================================================================
void Title::Draw(void)
{
	pTitleBG->Draw();
	// ポリゴンの描画処理
	//DrawPolygon();

	//描画処理
	DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(),GetV(),GetUW(),GetVH());

	//DrawPlanePolygon(GetTexture(), GetPos()+D3DXVECTOR3(0.0f, 500.0f,0.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld());

	//2Dポリゴンの描画
	//DrawPlanePolygon();
}
