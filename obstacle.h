//===============================================
//è·äQï®êßå‰[obstacle.h]
//Date:2023/10/30	Auther:ó—óSñÁ
//===============================================
#pragma once

#include "obj.h"
#include "renderer.h"
#include "Texture.h"
///==================================
//ÉNÉâÉXêÈåæ
//==================================
class Obstacle :public Obj
{
public:
	Obstacle(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 scale, D3DXVECTOR3 rot) :Obj(pos, size, scale, rot) {}
	Obstacle(DX11_MODEL model, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 scale, D3DXVECTOR3 rot) :Obj(model,pos, size, scale, rot) {}
	~Obstacle();
	void Update(void)override;
	void Draw(void)override;
	void DrawMap(void);
};
