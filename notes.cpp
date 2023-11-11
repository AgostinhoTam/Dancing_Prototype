//=============================================================================
// ポリゴン表示処理 [notes.cpp]
//Date:2023/10/29	Auther:林祐也
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "notes.h"
#include "texture.h"
#include "planePolygon.h"
#include "obstacle.h"
#include "collision.h"
#include "judgment frame.h"
#define ORIGINAL_LOC (200.0f)

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
//*****************************************************************************
// グローバル変数
//*****************************************************************************
//static ID3D11Buffer* g_VertexBuffer = NULL;	// 頂点情報
// 
//=============================================================================
// 初期化処理
//=============================================================================
Notes::Notes()
{
	// テクスチャ生成
	SetTexture(LoadTexture((char*)"data/TEXTURE/field004.jpg"));
	CAMERA* pCamera = GetCamera();
	// 位置・回転・スケールの初期設定
	SetPos(D3DXVECTOR3(-ORIGINAL_LOC, 200.0f, 0.0f)); //Vector3 
	SetRot(D3DXVECTOR3(D3DX_PI*0.45f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetVel(NOTES_VEL);
	SetScl(D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetFlag(true);
	pJF = new JudgmentFrame();
	
}

//=============================================================================
// 終了処理
//=============================================================================
Notes::~Notes()
{
	delete pJF;
	pNotesJudge.clear();
}

//=============================================================================
// 更新処理
//=============================================================================
void Notes::Update()
{
	SetPos(GetPos() + GetVel());
	SetTexture(LoadTexture((char*)"data/TEXTURE/black_000.jpg"));

	if (GetKeyboardTrigger(DIK_W) || GetKeyboardTrigger(DIK_A)|| GetKeyboardTrigger(DIK_S)|| GetKeyboardTrigger(DIK_D) || GetKeyboardTrigger(DIK_SPACE)) {

		if (CollisionPerfectBC(GetPos(), pJF->GetPos()))
		{
			SetTexture(LoadTexture((char*)"data/TEXTURE/white_000.jpg"));
			//SetFlag(false); // パーフェクト
			pJF->SetFlag(true);
			pNotesJudge.push_back(NotesJudge(PERFECT));
			SetPos(D3DXVECTOR3(-ORIGINAL_LOC, 200.0f, 0.0f));
		}
		else if (CollisionGreatBC(GetPos(), pJF->GetPos()))
		{
			SetTexture(LoadTexture((char*)"data/TEXTURE/blue_000.jpg"));
			//SetFlag(false); //fast
			pJF->SetFlag(true);
			pNotesJudge.push_back(NotesJudge(GREAT));
			SetPos(D3DXVECTOR3(-ORIGINAL_LOC, 200.0f, 0.0f));
		}
		else if ((CollisionGoodBC(GetPos(), pJF->GetPos())))
		{
			SetTexture(LoadTexture((char*)"data/TEXTURE/black_000.jpg"));
			pJF->SetFlag(true);
			pNotesJudge.push_back(NotesJudge(GOOD));
			SetPos(D3DXVECTOR3(-ORIGINAL_LOC, 200.0f, 0.0f));
			//SetFlag(false);//miss
		}
		else if((CollisionMissBC(GetPos(), pJF->GetPos())))
		{
			pJF->SetFlag(true);
			pNotesJudge.push_back(NotesJudge(BAD));
			SetPos(D3DXVECTOR3(-ORIGINAL_LOC, 200.0f, 0.0f));
		}
	}
	for (auto& Note : pNotesJudge) {
		Note.Update();
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void Notes::Draw()
{
	if (GetFlag())
	{
		CAMERA* pCamera = GetCamera();
		// Z比較なし
		SetDepthEnable(false);
	
		DrawPlanePolygon(GetTexture(), D3DXVECTOR3(GetPos().x+pCamera->pos.x,pCamera->pos.y-200.0f,pCamera->pos.z+100.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
		pJF->Draw();
		for (auto& Note : pNotesJudge) {
			Note.Draw();
			if (!Note.GetFlag()) {

				pNotesJudge.erase(pNotesJudge.begin());
			}
		}
	}

	// Z比較あり 
	SetDepthEnable(true);
}