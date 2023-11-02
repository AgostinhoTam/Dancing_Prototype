#pragma once
/*==============================================================================

   オブジェクト管理[obj.h]
														 Author :林祐也
														 Date   :2023/10/29
--------------------------------------------------------------------------------

==============================================================================*/

#include "renderer.h"
#include "main.h"
#include "model.h"

//==================================
//マクロ定義
//==================================

//==================================
//列挙体宣言
//==================================

//==================================
//クラス
//==================================
class Obj
{
private:

	//-----------------------------------
	//座標処理/2D
	//-----------------------------------
	D3DXVECTOR3  pos = { 0.0f,0.0f ,0.0f };			//場所
	D3DXVECTOR3  oldpos = { 0.0f,0.0f,0.0f };		//過去座標
	D3DXVECTOR3  size = { 0.0f,0.0f,0.0f };			//大きさ
	D3DXVECTOR3  vel = { 0.0f,0.0f ,0.0f };			//速度
	D3DXVECTOR3  rot = { 0.0f,0.0f ,0.0f };			//回転
	D3DXVECTOR3  scl = { 0.0f,0.0f,0.0f };			//スケール
	D3DXMATRIX	mtxWorld;							// ワールドマトリックス


	//-----------------------------------
	//アニメーション用/画像
	//-----------------------------------
	int texture = 0;				//画像格納用
	float U = 1.0f;					//画像の場所指定用X
	float V = 1.0f;					//画像の場所指定用Y
	float UW = 1.0f;				//画像のサイズX
	float VH = 1.0f;				//画像のサイズY
	float U_Cut = 1.0f;				//画像の横軸分割数
	float V_Cut = 1.0f;				//画像の縦軸分割数
	float frameCnt = 0.0f;			//描画速度のカウント用
	float frameSet = 0.0f;			//アニメーションの更新速度設定
	float red = 1.0f;				//赤
	float green = 1.0f;				//緑
	float blue = 1.0f;				//青
	float degree = 1.0f;			//透過度

	//----------------------------------
	//汎用
	//----------------------------------
	int cnt = 0;			//カウント用
	int target = 0;			//目標数値設定用
	bool flag = false;		//フラグ管理用
	//------------------------
	//音関係
	//------------------------
	int bgm = 0;		//BGM用
	int se = 0;			//SE用

protected:
	DX11_MODEL model;				//3Dモデル格納用

public:
	Obj(){}
	Obj(D3DXVECTOR3 rpos, D3DXVECTOR3 rsize, D3DXVECTOR3 rscl, D3DXVECTOR3 rrot):pos(rpos),size(rsize),scl(rscl),rot(rrot){}
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	//--------------------------------------------
	//セッター
	//--------------------------------------------
	//-----------------------------------
	//座標処理/2D
	//-----------------------------------
	void SetPos(D3DXVECTOR3 sPos) {
		pos = sPos;
	}//X,Y座標のセット
	void SetOldPos(D3DXVECTOR3 sPos) {
		oldpos = sPos;
	}//過去の座標セット
	
	void SetPosX(float sPos) {
		pos.x = sPos;
	}//X座標のセット
	void SetPosY(float sPos) {
		pos.y = sPos;
	}//Y座標のセット
	void SetPosZ(float sPos) {
		pos.z = sPos;
	}//Z座標のセット

	void SetOldPosX(float sPos) {
		oldpos.x = sPos;
	}//X座標のセット
	void SetOldPosY(float sPos) {
		oldpos.y = sPos;
	}//Y座標のセット
	void SetOldPosZ(float sPos) {
		oldpos.z = sPos;
	}//Z座標のセット

	void SetSize(D3DXVECTOR3 sSize) {
		size = sSize;
	}//X,Yサイズのセット
	void SetSizeX(float sSize) {
		size.x = sSize;
	}//Xサイズのセット
	void SetSizeY(float sSize) {
		size.y = sSize;
	}//Yサイズのセット
	void SetSizeZ(float sSize) {
		size.z = sSize;
	}//Zサイズのセット
	void SetVel(D3DXVECTOR3 sVel) {
		vel = sVel;
	}//X,Y速度のセット
	void SetVelX(float sVel) {
		vel.x = sVel;
	}//X速度のセット
	void SetVelY(float sVel) {
		vel.y = sVel;
	}//Y速度のセット
	void SetVelZ(float sVel) {
		vel.z = sVel;
	}//Z速度のセット
	void SetRot(D3DXVECTOR3 sRot) {
		rot = sRot;
	}//回転のセット
	void SetRotX(float sRot) {
		rot.x = sRot;
	}//X回転のセット
	void SetRotY(float sRot) {
		rot.y = sRot;
	}//Y回転のセット
	void SetRotZ(float sRot) {
		rot.z = sRot;
	}//Z回転のセット
	void SetScl(D3DXVECTOR3 sScl) {
		scl = sScl;
	}//スケールのセット
	void SetSclX(float sScl) {
		scl.x = sScl;
	}//X回転のセット
	void SetSclY(float sScl) {
		scl.y = sScl;
	}//Y回転のセット
	void SetSclZ(float sScl) {
		scl.z = sScl;
	}//Z回転のセット
	void SetMtxWorld(D3DXMATRIX mtx) {
		mtxWorld = mtx;
	}//ワールドマトリックスの設定

	//-----------------------------------
	//アニメーション用/画像
	//-----------------------------------

	//void SetModel(DX11_MODEL sModel) {
	//	model = sModel;
	//}//モデルのセット
	void SetTexture(int sTex) {
		texture = sTex;
	}//テクスチャのセット
	void SetU(float sU) {
		U = sU;
	}//UV値のUの始点設定
	void SetV(float sV) {
		V = sV;
	}//UV値のVの始点設定
	void SetUW(float sUW) {
		UW = sUW;
	}//UV値の横幅設定
	void SetVH(float sVH) {
		VH = sVH;
	}//UV値の立幅設定
	void SetU_Cut(float sCut) {
		U_Cut = sCut;
	}//横の画像分割数設定
	void SetV_Cut(float sCut) {
		V_Cut = sCut;
	}//縦の画像分割数設定
	void SetRed(float sRed) {
		red = sRed;
	}//赤色設定
	void SetGreen(float sGreen) {
		green = sGreen;
	}//緑色設定
	void SetBlue(float sBlue) {
		blue = sBlue;
	}//青色設定
	void SetDegree(float sDgree) {
		degree = sDgree;
	}//透過度設定
	//------------------------
	//汎用
	//------------------------
	void SetCnt(int sCnt) {
		cnt = sCnt;
	}//カウント設定
	void SetTarget(int sTarget) {
		target = sTarget;
	}//目標数値設定
	void SetFlag(bool sFlag) {
		flag = sFlag;
	}//フラグ設定

	//------------------------
	//音関係
	//------------------------
	void SetBGM(int sBGM) {
		bgm = sBGM;
	}//BGMの設定
	void SetSE(int sSE) {
		se = sSE;
	}//SEの設定

	//--------------------------------------------
	//ゲッター
	//--------------------------------------------
	//-----------------------------------
	//座標処理/2D
	//-----------------------------------
	D3DXVECTOR3 GetPos() const {
		return pos;
	}//X,Y座標の取得
	float GetPosX()const {
		return pos.x;
	}//X座標の取得
	float GetPosY() const {
		return pos.y;
	}//Y座標の取得
	float GetPosZ() const {
		return pos.z;
	}//Z座標の取得

	D3DXVECTOR3 GetOldPos() const {
		return oldpos;
	}//X,Y座標の取得
	float GetOldPosX()const {
		return oldpos.x;
	}//X座標の取得
	float GetOldPosY() const {
		return oldpos.y;
	}//Y座標の取得
	float GetOldPosZ() const {
		return oldpos.z;
	}//Z座標の取得

	D3DXVECTOR3 GetSize() const {
		return size;
	}//X,Yサイズの取得
	float GetSizeX() const {
		return size.x;
	}//Xサイズの取得
	float GetSizeY() const {
		return size.y;
	}//Yサイズの取得
	float GetSizeZ() const {
		return size.z;
	}//Yサイズの取得
	D3DXVECTOR3 GetVel() const {
		return vel;
	}//X,Yサイズの取得
	float GetVelX() const {
		return vel.x;
	}//X速度の取得
	float GetVelY() const {
		return vel.y;
	}//Y速度の取得
	float GetVelZ() const {
		return vel.z;
	}//Z速度の取得
	D3DXVECTOR3 GetRot() const {
		return rot;
	}//X,Yサイズの取得
	float GetRotX() const {
		return rot.x;
	}//X回転の取得
	float GetRotY() const {
		return rot.y;
	}//Y回転の取得
	float GetRotZ() const {
		return rot.z;
	}//Z回転の取得
	D3DXVECTOR3 GetScl() const {
		return scl;
	}//X,Y,Zスケールの取得
	float GetSclX() const {
		return scl.x;
	}//Xスケールの取得
	float GetSclY() const {
		return scl.y;
	}//Yスケールの取得
	float GetSclZ() const {
		return scl.z;
	}//Zスケールの取得

	D3DXMATRIX GetMtxWorld()const {
		return mtxWorld;
	}//ワールドマトリックスの取得
	
	//-----------------------------------
	//アニメーション用/画像
	//-----------------------------------

	//DX11_MODEL GetModel()const {
	//	return model;
	//}//モデルの取得
	int GetTexture() const {
		return texture;
	}//テクスチャの取得
	float GetU() const {
		return U;
	}//UV値のU始点取得
	float GetV() const {
		return V;
	}//UV値のV始点取得
	float GetUW() const {
		return UW;
	}//UV値のUW始点取得
	float GetVH() const {
		return VH;
	}//UV値のVH始点取得
	float GetU_Cut() const {
		return U_Cut;
	}//Uの画像分割数取得
	float GetV_Cut() const {
		return V_Cut;
	}//Vの画像分割数取得
	float GetRed() const {
		return red;
	}//赤色情報の取得
	float GetGreen() const {
		return green;
	}//緑色情報の取得
	float GetBlue() const {
		return blue;
	}//青色情報の取得
	float GetDegree() const {
		return degree;
	}//透過度情報の取得
	//------------------------
	//汎用
	//------------------------
	int GetCnt() const {
		return cnt;
	}//カウント取得
	int GetTarget() const {
		return target;
	}//目標数値取得
	bool GetFlag()const {
		return flag;
	}//フラグの取得

	//------------------------
	//音関係
	//------------------------
	int GetBGM() const {
		return bgm;
	}//BGMの取得
	int GetSE() const {
		return se;
	}//SEの取得
};