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
#include "enemy.h"
#include "collision.h"



//=============================================================================
// 初期化処理
//=============================================================================
Title::Title()
{
	pTitleBG =new TitleBG();
	pMap = new Map();
	pPlayer = new Player(pMap);
	GenerateEnemy();
	SetTexture(LoadTexture((char*)"data/TEXTURE/field000.jpg"));
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(100.0f, 100.0f, 100.0f));
	SetScl(D3DXVECTOR3(4.0f, 1.0f, 1.0f));
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
	delete pTitleBG;
	delete pPlayer;
	delete pMap;
	for(auto* enemy:Enemies){
		delete enemy;
	}
	Enemies.clear();
	//delete pEnemy;
	UnloadModel(&model);
}

//=============================================================================
// 更新処理
//=============================================================================
void Title::Update()
{	
	FrameAdd();

	pTitleBG->Update();
	pPlayer->Update();
	pMap->Update();
	if (GetFrame() == 60 && Enemies.capacity() < 200) {
		int random = rand() % 2000 -1000;
		GenerateEnemy(random);
		SetFrameZero();
	}
	for (auto* enemy : Enemies) {
		enemy->Update();
	}
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
	for (auto* enemy : Enemies) {
		enemy->Draw();
	}
	//pEnemy->Draw();

	////描画処理
	//DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(),GetV(),GetUW(),GetVH());

	//DrawPlanePolygon(GetTexture(), GetPos()-D3DXVECTOR3(0.0f, 0.0f,100.0f),D3DXVECTOR3(400.0f, 0.0f, 100.0f), GetRot(), D3DXVECTOR3(1.0f,1.0f,1.0f), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());

	//UI
	//DrawUIPlanePolygon(GetTexture(), GetPos() - D3DXVECTOR3(100.0f, 0.0f, 0.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());

	//2Dポリゴンの描画
	//DrawPlanePolygon();
}

void Title::GenerateEnemy()
{
	DX11_MODEL enemytemp;
	LoadModel((char*)"data/MODEL/miku_01.obj", &enemytemp);
	Enemies.push_back(new Enemy(enemytemp,
		D3DXVECTOR3(400.0f, 200.0f, 0.0f),						//pos
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//vel
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//size
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//rot
		D3DXVECTOR3(15.0f, 15.0f, 15.0f),GetMap()));					//scl
}

void Title::GenerateEnemy(int index)
{
	DX11_MODEL enemytemp;
	LoadModel((char*)"data/MODEL/miku_01.obj", &enemytemp);
	Enemies.push_back(new Enemy(enemytemp,
		D3DXVECTOR3(index, 200.0f, 0.0f),						//pos
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//vel
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//size
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//rot
		D3DXVECTOR3(15.0f, 15.0f, 15.0f), GetMap()));					//scl
}
