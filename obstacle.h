//===============================================
//��Q������[obstacle.h]
//Date:2023/10/30	Auther:�їS��
//===============================================
#pragma once

#include "obj.h"
#include "renderer.h"
#include "Texture.h"
///==================================
//�N���X�錾
//==================================
class Obstacle :public Obj
{
public:
	Obstacle(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 scale, D3DXVECTOR3 rot) :Obj(pos, size, scale, rot) {
		SetTexture(LoadTexture((char*)"data/TEXTURE/field000.jpg"));
	}
	~Obstacle();
	void Update(void)override;
	void Draw(void)override;
};
