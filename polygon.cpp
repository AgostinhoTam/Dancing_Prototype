//=============================================================================
//
// ポリゴン表示処理 [polygon.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "polygon.h"
#include "texture.h"
#include "model.h"

// どうきする

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	VALUE_MOVE		(5.0f)						// 移動量
#define	VALUE_ROTATE	(D3DX_PI * 0.02f)			// 回転量
#define VALUE_DIRECTION_X	(D3DX_PI*0.5f)
#define VALUE_DIRECTION_Z (D3DX_PI*1.0f)
#define JUMP_TIME_MAX (60)			//ジャンプの時間

#define	SIZE_X			(100.0f)					// 地面のサイズ(X方向)
#define	SIZE_Z			(100.0f)					// 地面のサイズ(Z方向)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT MakeVertexPolygon(void);


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// 頂点情報

static POLYGON						g_Polygon;			// ポリゴンデータ
static DX11_MODEL					g_Model;			// モデル読み込み

static int jumpCnt = 0;
static bool jumpFlag = false;


int abc;

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitPolygon(void)
{
	//objモデルの読み込み
	LoadModel((char*)"data/MODEL/miku_01.obj", &g_Model);

	// 位置・回転・スケールの初期設定
	g_Polygon.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Polygon.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Polygon.scl = D3DXVECTOR3(10.0f, 10.0f, 10.0f);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitPolygon(void)
{
	//objモデルの解放
	UnloadModel(&g_Model);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdatePolygon(void)
{
	CAMERA* cam = GetCamera();
	SetCameraAT(g_Polygon.pos);
	// 回転させちゃう
	if (GetKeyboardPress(DIK_LEFT))
	{
		g_Polygon.rot.y -= VALUE_ROTATE;
	}
	if (GetKeyboardPress(DIK_RIGHT))
	{
		g_Polygon.rot.y += VALUE_ROTATE;
	}
	if (GetKeyboardPress(DIK_UP))
	{
		g_Polygon.rot.x -= VALUE_ROTATE;
	}
	if (GetKeyboardPress(DIK_DOWN))
	{
		g_Polygon.rot.x += VALUE_ROTATE;
	}

	if (GetKeyboardPress(DIK_RETURN))
	{
		g_Polygon.rot.y = g_Polygon.rot.x = 0.0f;
	}

	if (GetKeyboardPress(DIK_W))
	{
		g_Polygon.pos.z += VALUE_MOVE;
		g_Polygon.rot.y = 0.0f;
	}
	if (GetKeyboardPress(DIK_S))
	{
		g_Polygon.pos.z -= VALUE_MOVE;
		g_Polygon.rot.y = -VALUE_DIRECTION_Z;
	}
	if (GetKeyboardPress(DIK_A))
	{
		g_Polygon.pos.x -= VALUE_MOVE;
		g_Polygon.rot.y = -VALUE_DIRECTION_X;
	}
	if (GetKeyboardPress(DIK_D))
	{
		g_Polygon.pos.x += VALUE_MOVE;
		g_Polygon.rot.y = VALUE_DIRECTION_X;
	}

	//ジャンプしていない時
	if (!jumpFlag)
	{//ジャンプ
		if (GetKeyboardPress(DIK_SPACE))
		{
			jumpFlag = true;//ジャンプフラグをtrueに
		}
	}
	else if (jumpFlag)//ジャンプ中
	{
		jumpCnt++;

		if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 5)
		{
			g_Polygon.pos.y += 3.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 4)
		{
			g_Polygon.pos.y += 2.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 3)
		{
			g_Polygon.pos.y += 1.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 2)
		{
			g_Polygon.pos.y -= 1.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX - (JUMP_TIME_MAX / 6) * 1)
		{
			g_Polygon.pos.y -= 2.0f;
		}
		else if (jumpCnt <= JUMP_TIME_MAX)
		{
			g_Polygon.pos.y -= 3.0f;
		}
		else if (jumpCnt >= JUMP_TIME_MAX + 10)//着地隙
		{
			g_Polygon.pos.y = 0;
			jumpFlag = false;
			jumpCnt = 0;
		}
	}

#ifdef _DEBUG	// デバッグ情報を表示する
	char* str = GetDebugStr();
	sprintf(&str[strlen(str)], " rotX:%.2f rotY:%.2f", g_Polygon.rot.x, g_Polygon.rot.y);

#endif
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawPolygon(void)
{
	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ワールドマトリックスの初期化（単位行列を作る関数）
	D3DXMatrixIdentity(&g_Polygon.mtxWorld);

	// スケールを反映
	D3DXMatrixScaling(&mtxScl, g_Polygon.scl.x, g_Polygon.scl.y, g_Polygon.scl.z);

	//第1引数 ＝          第2引数      ＊    第3引数
	D3DXMatrixMultiply(&g_Polygon.mtxWorld, &g_Polygon.mtxWorld, &mtxScl);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Polygon.rot.y, g_Polygon.rot.x, g_Polygon.rot.z);
	D3DXMatrixMultiply(&g_Polygon.mtxWorld, &g_Polygon.mtxWorld, &mtxRot);

	// 移動を反映
	D3DXMatrixTranslation(&mtxTranslate, g_Polygon.pos.x, g_Polygon.pos.y, g_Polygon.pos.z);
	D3DXMatrixMultiply(&g_Polygon.mtxWorld, &g_Polygon.mtxWorld, &mtxTranslate);

	// ワールドマトリックスの設定
	SetWorldMatrix(&g_Polygon.mtxWorld);

	//objモデルの描画
	DrawModel(&g_Model);
}



