//===============================================
//�U���͈͐���[attackarea.h]
//Date:2023/11/08	Auther:杈̐i
//===============================================
#pragma once
#ifndef _ATTACK_AREA_
#define _ATTACK_AREA_
#include "player.h"
//==================================
//�}�N����`
//==================================


///==================================
//�N���X�錾
//==================================
class CAttackArea :public Obj
{
private:
	Player* m_ptr;
	const float MAX_RNG = 2.0f;
	const float SPD = 1.0f;
	const float RECOVERSPEED = SPD * 0.01f;
	float m_CurRng = 0.0f;
	float m_MaxRng = MAX_RNG;
public:
	CAttackArea(Player* ptr);
	~CAttackArea();
	void Update(void)override;
	void Draw(void)override;
	void IncreaseCurRng(const float rng) { m_CurRng += rng; }
	const float GetCurRng() const{ return m_CurRng; }
	void SetCurRng(const float rng) { this->SetScl(D3DXVECTOR3(m_CurRng, this->GetSclY(), m_CurRng)); }
	void DecreaseCurRng() { m_CurRng < RECOVERSPEED ? 0.0f : m_CurRng -= RECOVERSPEED; }
};

#endif



