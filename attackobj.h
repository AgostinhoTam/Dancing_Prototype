#pragma once
class AttackObj {
private:
	float m_dmg = 0.0f;
	
public:
	AttackObj(float dmg):m_dmg(dmg){}
	~AttackObj(){}
	float GetDmg() { return m_dmg; }
	const void SetDmg(const float dmg) { m_dmg = dmg; }
	void IncreaseDmg(const float dmg) { m_dmg += dmg; }
};