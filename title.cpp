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
	pDefObj = new DefenseObj();
	pPlayer = new Player(pMap,Enemies,pDefObj);

	unsigned int sound = LoadSound((char*)"data/SOUND/BGM/test.wav");
	SetVolume(sound, 0.2f);//1.0が100％
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
	UnloadModel(&model);
}

//=============================================================================
// 更新処理
//=============================================================================
void Title::Update()
{	
	FrameAdd();
	pTitleBG->Update();
	pMap->Update();
	pDefObj->Update();
	pPlayer->Update();
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
		if(enemy->GetFlag()){
		enemy->Draw();
		}
	}
}

void Title::GenerateEnemy()
{
	DX11_MODEL enemytemp;
	LoadModel((char*)"data/MODEL/miku_01.obj", &enemytemp);
	Enemies.push_back(new Enemy(enemytemp,
		D3DXVECTOR3(400.0f, 200.0f, 0.0f),						//pos
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//vel
		D3DXVECTOR3(10.0f, 10.0f, 10.0f),						//size
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//rot
		D3DXVECTOR3(10.0f, 10.0f, 10.0f),GetMap(),GetDefObj(),pPlayer->GetAttackArea(),true));					//scl
}

void Title::GenerateEnemy(float x,float z)
{
	DX11_MODEL enemytemp;
	LoadModel((char*)"data/MODEL/miku_01.obj", &enemytemp);
	Enemies.push_back(new Enemy(enemytemp,
		D3DXVECTOR3(x, 200.0f, z),						//pos
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),						//vel
		D3DXVECTOR3(10.0f, 10.0f, 10.0f),						//size
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),						//rot
		D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMap(), GetDefObj(), pPlayer->GetAttackArea(),true));					//scl
}
