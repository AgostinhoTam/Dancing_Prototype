//=============================================================================
//
// ポリゴン表示処理 [planePolygon.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "input.h"
#include "camera.h"
#include "planePolygon.h"
#include "texture.h"
#include "camera.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	VALUE_MOVE		(5.0f)						// 移動量
#define	VALUE_ROTATE	(D3DX_PI * 0.02f)			// 回転量
#define NUM_VERTEX		(4)							//ポリゴンの頂点数

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// 頂点情報

static PLANEPOLYGON						g_PlanePolygon;			// ポリゴンデータ
static int								g_TexNo;			    // テクスチャ番号

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitPlanePolygon(void)
{

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitPlanePolygon(void)
{
	// 頂点バッファの解放
	if (g_VertexBuffer) {
		g_VertexBuffer->Release();
		g_VertexBuffer = NULL;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdatePlanePolygon(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
//void DrawPlanePolygon(void)
//{
//	// 頂点バッファ設定
//	UINT stride = sizeof(VERTEX_3D);
//	UINT offset = 0;
//	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);
//
//	// プリミティブトポロジ設定
//	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
//
//	// テクスチャ設定
//	GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_TexNo));
//
//
//	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;
//
//	// ワールドマトリックスの初期化
//	D3DXMatrixIdentity(&g_PlanePolygon.mtxWorld);
//
//	// スケールを反映
//	D3DXMatrixScaling(&mtxScl, g_PlanePolygon.scl.x, g_PlanePolygon.scl.y, g_PlanePolygon.scl.z);
//	D3DXMatrixMultiply(&g_PlanePolygon.mtxWorld, &g_PlanePolygon.mtxWorld, &mtxScl);
//
//	// 回転を反映
//	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_PlanePolygon.rot.y, g_PlanePolygon.rot.x, g_PlanePolygon.rot.z);
//	D3DXMatrixMultiply(&g_PlanePolygon.mtxWorld, &g_PlanePolygon.mtxWorld, &mtxRot);
//
//	// 移動を反映
//	D3DXMatrixTranslation(&mtxTranslate, g_PlanePolygon.pos.x, g_PlanePolygon.pos.y, g_PlanePolygon.pos.z);
//	D3DXMatrixMultiply(&g_PlanePolygon.mtxWorld, &g_PlanePolygon.mtxWorld, &mtxTranslate);
//
//	// ワールドマトリックスの設定
//	SetWorldMatrix(&g_PlanePolygon.mtxWorld);
//
//	// ポリゴン描画
//	GetDeviceContext()->Draw(NUM_VERTEX, 0);
//}
//=============================================================================
// 平面ポリゴンデータ設定
// 座標・サイズ・UV指定
//=============================================================================
//引数
//texNo		: テクスチャの識別番号（texture.h, texture.cpp のLoadTexture関数の戻り値）
//Pos		: 座標
//Size		: サイズ
//Rot		: 回転
//Scl		: スケール
//MtxWorld	: ワールドマトリックス(ポリゴンのワールドマトリックス情報を入れる)、考えないで入れて大丈夫
//U			: UV値始点
//V			: UV値始点
//UW		: UV値横幅
//VH		: UV値高さ
void DrawPlanePolygon(int texNo, D3DXVECTOR3 Pos, D3DXVECTOR3 Size,D3DXVECTOR3 Rot,D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld ,float U, float V, float UW, float VH)
{
	VERTEX_3D g_VertexArray[4] = {
	{D3DXVECTOR3(-Size.x/2,Size.y / 2, Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V)},
	{D3DXVECTOR3(Size.x / 2,Size.y / 2,  Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V)},
	{D3DXVECTOR3(-Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V + VH)},
	{D3DXVECTOR3(Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V + VH)}};

	//------------------------------------------------------------------------------------
		
	// 頂点バッファ生成
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;;
	bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	// グローバルの頂点配列から頂点バッファをつくる
	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = g_VertexArray;

	GetDevice()->CreateBuffer(&bd, &sd, &g_VertexBuffer);

	//-------------------------------------------------------------------------------------

	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// テクスチャ設定
	GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(texNo));

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&MtxWorld);

	// スケールを反映
	D3DXMatrixScaling(&mtxScl, Scl.x, Scl.y, Scl.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxScl);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, Rot.y, Rot.x, Rot.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	// 移動を反映
	D3DXMatrixTranslation(&mtxTranslate, Pos.x, Pos.y, Pos.z);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);
	// ワールドマトリックスの設定
	SetWorldMatrix(&MtxWorld);

	// ポリゴン描画
	GetDeviceContext()->Draw(NUM_VERTEX, 0);
}