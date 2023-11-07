//===============================================
//タイトル制御[title.cpp]
//Date:2023/07/10	Auther:林祐也
//===============================================
#include "title.h"
#include "titleBG.h"
#include "sound.h"
#include "input.h"



//=============================================================================
// 初期化処理
//=============================================================================
Title::Title()
{
	pTitleBG =new TitleBG();
	pMap = new Map();
	pPlayer = new Player(pMap,Enemies);
	pDefObj = new DefenseObj();

	unsigned int sound = LoadSound((char*)"data/SOUND/BGM/test.wav");
	SetVolume(sound, 0.5f);//1.0が100％
	PlaySound(sound, 0);//後ろの数字で回数を決める、０以下になると無限ループになる
}

//=============================================================================
// 終了処理
//=============================================================================
Title::~Title()
{
	delete pTitleBG;
	delete pPlayer;
	delete pMap;
	delete pDefObj;
	for(auto* enemy:Enemies){
		if(enemy != nullptr){
		delete enemy;
		}
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
	pDefObj->Update();
	if (GetFrame() == 60 && Enemies.capacity() < 200) {
		float randomx = rand() % 2000 -1000;
		float randomz = rand() % 2000 - 1000;
		GenerateEnemy(randomx,randomz);
		SetFrameZero();
	}
	for (auto* enemy : Enemies) {
		if(enemy != nullptr){
		enemy->Update();
		}
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
	pDefObj->Draw();
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
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//vel
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//size
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//rot
		D3DXVECTOR3(15.0f, 15.0f, 15.0f),GetMap(),GetDefObj()));					//scl
}

void Title::GenerateEnemy(float x,float z)
{
	DX11_MODEL enemytemp;
	LoadModel((char*)"data/MODEL/miku_01.obj", &enemytemp);
	Enemies.push_back(new Enemy(enemytemp,
		D3DXVECTOR3(x, 200.0f, z),						//pos
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//vel
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//size
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//rot
		D3DXVECTOR3(15.0f, 15.0f, 15.0f), GetMap(), GetDefObj()));					//scl
}
