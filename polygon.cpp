//=============================================================================
// ポリゴン表示処理 [polygon.cpp]
//Date:2023/10/29	Auther:林祐也
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "polygon.h"
#include "texture.h"
#include "model.h"
#include "obj.h"
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
HRESULT InitPolygon(void)
{
	//objモデルの読み込み
	//LoadModel((char*)"data/MODEL/miku_01.obj", &g_Model);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitPolygon(void)
{
	//objモデルの解放
	//UnloadModel(&g_Model);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdatePolygon(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
//=============================================================================
// ポリゴンデータ設定
// 座標・サイズ
//=============================================================================
//引数
//texNo		: テクスチャの識別番号（texture.h, texture.cpp のLoadTexture関数の戻り値）
//Pos		: 座標
//Size		: サイズ
//Rot		: 回転
//Scl		: スケール
//MtxWorld	: ワールドマトリックス(ポリゴンのワールドマトリックス情報を入れる)、考えないで入れて大丈夫

void DrawPolygon(DX11_MODEL* Model,D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld)
{

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ワールドマトリックスの初期化（単位行列を作る関数）
	D3DXMatrixIdentity(&MtxWorld);

	// スケールを反映
	D3DXMatrixScaling(&mtxScl, Scl.x, Scl.y,Scl.z);

	//第1引数 ＝          第2引数      ＊    第3引数
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxScl);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, Rot.y, Rot.x, Rot.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	// 移動を反映
	D3DXMatrixTranslation(&mtxTranslate, Pos.x, Pos.y, Pos.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);

	// ワールドマトリックスの設定
	SetWorldMatrix(&MtxWorld);

	//objモデルの描画
	DrawModel(Model);
}
//=============================================================================
// プレイヤーポリゴンデータ設定
// 座標・サイズ・プレイヤー追尾
//=============================================================================
//引数
//texNo		: テクスチャの識別番号（texture.h, texture.cpp のLoadTexture関数の戻り値）
//Pos		: 座標
//Size		: サイズ
//Rot		: 回転
//Scl		: スケール
//MtxWorld	: ワールドマトリックス(ポリゴンのワールドマトリックス情報を入れる)、考えないで入れて大丈夫
void DrawPlayerPolygon(DX11_MODEL Model, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld)
{
	//カメラがプレイヤーを中心に
	CAMERA* cam = GetCamera();
	SetCameraAT(Pos);

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ワールドマトリックスの初期化（単位行列を作る関数）
	D3DXMatrixIdentity(&MtxWorld);

	
	// スケールを反映
	D3DXMatrixScaling(&mtxScl, Scl.x, Scl.y, Scl.z);

	Model.m_MinVertex.x = Model.m_MinVertex.x * Scl.x;
	Model.m_MinVertex.y = Model.m_MinVertex.y * Scl.y;
	Model.m_MinVertex.z = Model.m_MinVertex.z * Scl.z;
	Model.m_MaxVertex.x = Model.m_MaxVertex.x * Scl.x;
	Model.m_MaxVertex.y = Model.m_MaxVertex.y * Scl.y;
	Model.m_MaxVertex.z = Model.m_MaxVertex.z * Scl.z;

	//第1引数 ＝          第2引数      ＊    第3引数
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxScl);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, Rot.y, Rot.x, Rot.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	// 移動を反映
	D3DXMatrixTranslation(&mtxTranslate, Pos.x, Pos.y, Pos.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);

	// ワールドマトリックスの設定
	SetWorldMatrix(&MtxWorld);


	//objモデルの描画
	DrawModel(&Model);
}

