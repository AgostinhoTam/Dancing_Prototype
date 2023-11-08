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
#include "player.h"
#include "map.h"
#include "collision.h"
#include "notes.h"


//=============================================================================
// 初期化処理
//=============================================================================
Title::Title()
{
	pTitleBG = new TitleBG();
	pPlayer = new Player();
	pMap = new Map();
	SetTexture(LoadTexture((char*)"data/TEXTURE/field000.jpg"));
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(100.0f, 100.0f, 100.0f));
	SetScl(D3DXVECTOR3(4.0f, 1.0f, 1.0f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	pPlayer->SetObstacles(pMap->GetObstacles());
	//SetSound(LoadSound((char*)"data/SOUND/BGM/BGM_Title.wav"));
	//SetVolume(GetSound(), 0.5f);//1.0が100％
	//PlaySound(GetSound(), 0);//後ろの数字で回数を決める、０以下になると無限ループになる
}

//=============================================================================
// 終了処理
//=============================================================================
Title::~Title()
{
	delete pTitleBG;
	delete pPlayer;
	delete pMap;

	UnloadModel(&model);
}

//=============================================================================
// 更新処理
//=============================================================================
void Title::Update()
{

	pTitleBG->Update();
	pPlayer->Update();
	pMap->Update();

	pMap->SetPos(pPlayer->GetPos());
	pMap->SetSize(pPlayer->GetSize());
	pMap->SetScl(pPlayer->GetScl());


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
	pPlayer->Draw();
	pMap->Draw();


	////描画処理
	//DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(),GetV(),GetUW(),GetVH());

	//DrawPlanePolygon(GetTexture(), GetPos()-D3DXVECTOR3(0.0f, 0.0f,100.0f),D3DXVECTOR3(400.0f, 0.0f, 100.0f), GetRot(), D3DXVECTOR3(1.0f,1.0f,1.0f), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());

	//UI
	//DrawUIPlanePolygon(GetTexture(), GetPos() - D3DXVECTOR3(100.0f, 0.0f, 0.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());

	//2Dポリゴンの描画
	//DrawPlanePolygon();
}
