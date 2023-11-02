//===============================================
//�^�C�g������[defenseobj.cpp]
//Date:2023/10/29	Auther:�їS��
//===============================================
#include "defenseobj.h"
#include "player.h"
#include "input.h"
#include "polygon.h"
#include "camera.h"
#include "collision.h"

DefenseObj::DefenseObj()
{
	LoadModel((char*)"data/MODEL/dancing.obj", &model);
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	SetScl(D3DXVECTOR3(0.2f, 0.2f, 0.2f));
	SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

DefenseObj::~DefenseObj()
{
	UnloadModel(&model);
}

void DefenseObj::Update(void)
{

		if (CollisionBB(GetPos(), GetSize(), GetScl(), m_defenseobj->GetPos(), m_defenseobj->GetSize(), m_defenseobj->GetScl()))
		{
			m_defenseobj->SetFlag(true);
		}
		else if (!CollisionBB(GetPos(), GetSize(), GetScl(), m_defenseobj->GetPos(), m_defenseobj->GetSize(), m_defenseobj->GetScl()))
		{
			m_defenseobj->SetFlag(false);
		}

		//�������Ă��鎞
		if (m_defenseobj->GetFlag())
		{
			SetPosY(GetPosY() + 500.0f);
		}
		//�n�ʂɂ��Ă��鎞
		else if (GetPosY() <= 0.0f)
		{
			SetPosY(0.1f);
		}
		//�������Ă��Ȃ��Ƃ�
		else if (!m_defenseobj->GetFlag())
		{
			SetVelY(-10.0f);
		}


}

void DefenseObj::Draw(void)
{
	// �|���S���̕`�揈��
	DrawPlayerPolygon(model, GetPos(), GetSize(), GetRot(),GetScl(), GetMtxWorld());
	//DrawPolygon(model, D3DXVECTOR3(-100.0f, 0.0f, 0.0f), GetSize(), GetRot(), D3DXVECTOR3(10.0f, 10.0f, 10.0f), GetMtxWorld());

}
