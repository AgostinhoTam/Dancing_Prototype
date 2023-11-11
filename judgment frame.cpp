//=============================================================================
// ポリゴン表示処理 [judgment frame.cpp]
//Date:2023/10/29	Auther:林祐也
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "judgment frame.h"
#include "texture.h"
#include "planePolygon.h"
#include "obstacle.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// 頂点情報

//=============================================================================
// 初期化処理
//=============================================================================
JudgmentFrame::JudgmentFrame()
{

	// テクスチャ生成
	SetTexture(LoadTexture((char*)"data/TEXTURE/field000.jpg"));

	// 位置・回転・スケールの初期設定

	SetPos(D3DXVECTOR3(0.0f, 200.0f, 0.0f));
	SetRot(D3DXVECTOR3(D3DX_PI * 0.45f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetVel(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetScl(D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetFlag(true);
}

//=============================================================================
// 終了処理
//=============================================================================
JudgmentFrame::~JudgmentFrame()
{
	obstacles.clear();
	// 頂点バッファの解放
	if (g_VertexBuffer) {
		g_VertexBuffer->Release();
		g_VertexBuffer = NULL;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void JudgmentFrame::Update()
{

}

//=============================================================================
// 描画処理
//=============================================================================
void JudgmentFrame::Draw()
{
	//DrawPlanePolygon(GetTexture(), GetPos(), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	if (GetFlag())
	{
		CAMERA* pCamera = GetCamera();
		// Z比較なし
		SetDepthEnable(false);

		//DrawUIPlanePolygon(GetTexture(), D3DXVECTOR3(GetPos().x, pCamera->pos.y - 200.0f, pCamera->pos.z + 100.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
		DrawPlanePolygon(GetTexture(), D3DXVECTOR3(GetPos().x+pCamera->pos.x, pCamera->pos.y - 200.0f, pCamera->pos.z + 100.0f), GetSize(), GetRot(), GetScl(), GetMtxWorld(), GetU(), GetV(), GetUW(), GetVH());
	}
}