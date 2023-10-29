//===============================================
//�Q�[������[player.h]
//Date:2023/10/27	Auther:�їS��
//===============================================
#pragma once


#include "obj.h"

//==================================
//�}�N����`
//==================================
#define PLAYER_MOVE_SPEED_X (10) //X���W�̃v���C���[�̈ړ����x
#define PLAYER_MOVE_SPEED_Z (15) //Z���W�̃v���C���[�̈ړ����x

///==================================
//�N���X�錾
//==================================
class Player :public Obj
{
private:
	float	m_faith = 0; //�M�l
	int		m_combo = 0;
	float	m_hp = 0;
public:
	Player();
	~Player();
	void Update(void)override;
	void Draw(void)override;
	float	GetFaith() { return m_faith; }
	int		GetCombo() { return m_combo; }
	float	GetHp() { return m_hp; }
	void	AddHp(float addhp) { m_hp += addhp; }
	void	AddFaith(float addfaith) { m_faith += addfaith; }
	void	AddCombo(float addcombo) { m_combo += addcombo; }
	void	ComboReset() { m_combo = 0; }
};





