//=============================================================================
// ポリゴン表示処理 [notes.cpp]
//Date:2023/10/29	Auther:林祐也
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
	SetTexture(LoadTexture((char*)"data/TEXTURE/field001.jpg"));

	// 位置・回転・スケールの初期設定
	SetPos(D3DXVECTOR3(-100.0f, 0.0f, 0.0f));
	SetNotesPos(D3DXVECTOR2(-100.0f, 0.0f));
	SetRot(D3DXVECTOR3(0.45f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(10.0f, 10.0f, 0.0f));
	SetVel(NOTES_VEL);
	SetScl(D3DXVECTOR3(10.0f, 10.0f, 0.0f));
	SetFlag(true);
}

//=============================================================================
// 終了処理
//=============================================================================
Notes::~Notes()
{
	obstacles.clear();
	//// 頂点バッファの解放
	//if (g_VertexBuffer) {
	//	g_VertexBuffer->Release();
	//	g_VertexBuffer = NULL;
	//}
}

//=============================================================================
// 更新処理
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
			//SetFlag(false); // パーフェクト
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
			//SetVel(D3DXVECTOR3(0.0f, 0.0f, 0.0f));// 確認用判定したら止まる
			SetTexture(LoadTexture((char*)"data/TEXTURE/red_000.jpg"));
			//SetFlag(false);//late
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void Notes::Draw()
{
	if (GetFlag())
	{
		DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	}
}

