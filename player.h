//===============================================
//ゲーム制御[player.h]
//Date:2023/10/27	Auther:林祐也
//===============================================
#pragma once


#include "obj.h"

//==================================
//マクロ定義
//==================================
#define PLAYER_MOVE_SPEED_X (10) //X座標のプレイヤーの移動速度
#define PLAYER_MOVE_SPEED_Z (15) //Z座標のプレイヤーの移動速度

///==================================
//クラス宣言
//==================================
class Player :public Obj
{
private:
	float	m_faith = 0; //信仰値
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





