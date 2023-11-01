//=============================================================================
//ポリゴン表示処理 [planePolygon.cpp]
//Date:2023/10/31	Auther:林祐也
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
#define NUM_VERTEX		(4)							//ポリゴンの頂点数


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;	// 頂点情報

static MATERIAL			Material;			// マテリアルデータ

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitPlanePolygon(void)
{
	// マテリアル設定
	ZeroMemory(&Material, sizeof(Material));
	Material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//拡散色
	Material.Ambient = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	//環境色
	Material.Emission = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	//自己発光色
	Material.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//※スペキュラーは未対応
	Material.Shininess = 20;								//※スペキュラーは未対応
	Material.noTexSampling = 0;								//テクスチャ有り:0 or テクスチャ無し:1
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

	// マテリアルのセット
	SetMaterial(Material);

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

//=============================================================================
// UI版平面ポリゴンデータ設定
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
void DrawUIPlanePolygon(int texNo, D3DXVECTOR3 Pos, D3DXVECTOR3 Size, D3DXVECTOR3 Rot, D3DXVECTOR3 Scl, D3DXMATRIX MtxWorld, float U, float V, float UW, float VH)
{

	//カメラの情報を取得
	CAMERA* cam = GetCamera();
	
	float vx, vz;
	vx = cam->pos.x - cam->at.x;
	vz = cam->pos.z - cam->at.z;

	float side = cam->len = sqrtf(vx * vx + vz * vz);
	float z1 = Pos.z + (side * cosf(cam->rot.z));
	float z2 = Pos.z + (side * sinf(cam->rot.z));
	float x1 = Pos.x + (side * cosf(cam->rot.x));
	float x2 = Pos.x + (side * sinf(cam->rot.x));

	VERTEX_3D g_VertexArray[4] = {
	{D3DXVECTOR3(-Size.x / 2,Size.y / 2, Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V)},
	{D3DXVECTOR3(Size.x / 2,Size.y / 2,  Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V)},
	{D3DXVECTOR3(-Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U, V + VH)},
	{D3DXVECTOR3(Size.x / 2, -Size.y / 2, -Size.z / 2), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(U + UW, V + VH)} };

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

	// マテリアルのセット
	SetMaterial(Material);

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
	D3DXMatrixTranslation(&mtxTranslate, cam->pos.x, cam->pos.y+ Pos.y, cam->pos.z + side);
	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTranslate);
	// ワールドマトリックスの設定
	SetWorldMatrix(&MtxWorld);

	// ポリゴン描画
	GetDeviceContext()->Draw(NUM_VERTEX, 0);
}