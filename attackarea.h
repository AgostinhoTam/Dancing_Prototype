//===============================================
//攻撃範囲制御[attackarea.h]
//Date:2023/11/08	Author:譚偉進
//===============================================
#pragma once
#ifndef _ATTACK_AREA_
#define _ATTACK_AREA_
#include "obj.h"
#include "player.h"
//==================================
//マクロ定義
//==================================


///==================================
//クラス宣言
//==================================

class CAttackArea:public Obj
{
private:
	const float MAX_RNG = 2.0f;
	const float SPD = 1.0f;
	const float RECOVERSPEED = SPD * 0.01f;
	float m_CurRng = 0.0f;
	float m_MaxRng = MAX_RNG;
	float m_dmg = 0.0f;
public:
	CAttackArea();
	~CAttackArea();
	void Update()override;
	void UpdatePos(D3DXVECTOR3 pos);
	void Draw()override;
	void IncreaseCurRng(const float rng) { m_CurRng += rng; }
	const float GetCurRng() const { return m_CurRng; }
	void SetCurRng(const float rng) { this->SetScl(D3DXVECTOR3(m_CurRng, this->GetSclY(), m_CurRng)); }
	void DecreaseCurRng() { m_CurRng < RECOVERSPEED ? 0.0f : m_CurRng -= RECOVERSPEED; }
};

#endif



