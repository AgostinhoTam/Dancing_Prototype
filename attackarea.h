//===============================================
//攻撃範囲制御[attackarea.h]
//Date:2023/11/08	Author:譚偉進
//===============================================
#pragma once
#ifndef _ATTACK_AREA_
#define _ATTACK_AREA_
#include "obj.h"
#include "player.h"
#include "model.h"
//==================================
//マクロ定義
//==================================


///==================================
//クラス宣言
//==================================
class CollisionPoly;
class CAttackArea:public Obj
{
private:
	const float MAX_RNG = 50.0f;
	const float SPD = 1.0f;
	const float RECOVERSPEED = SPD * 0.01f;
	float m_CurRng = 0.0f;
	float m_MaxRng = MAX_RNG;
	float m_dmg = 0.0f;
	CollisionPoly* m_colpoly;
public:
	CAttackArea();
	~CAttackArea();
	void Update()override;
	void UpdatePos(D3DXVECTOR3 pos);
	void Draw()override;
	void IncreaseCurRng(const float rng) { m_CurRng<MAX_RNG ? m_CurRng+= rng : m_CurRng =MAX_RNG+1.0f; }
	const float GetCurRng() const { return m_CurRng; }
	void UpdateCurRng() { this->SetScl(D3DXVECTOR3(m_CurRng, m_CurRng, m_CurRng)); }
	void DecreaseCurRng() { m_CurRng < RECOVERSPEED ? 0.0f : m_CurRng -= RECOVERSPEED; }
	void PolyUpdate(DX11_MODEL* model);
};

#endif



