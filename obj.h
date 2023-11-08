#pragma once
/*==============================================================================

   �I�u�W�F�N�g�Ǘ�[obj.h]
														 Author :�їS��
														 Date   :2023/10/29
--------------------------------------------------------------------------------

==============================================================================*/

#include "renderer.h"
#include "main.h"
#include "model.h"

//==================================
//�}�N����`
//==================================

//==================================
//�񋓑̐錾
//==================================

//==================================
//�N���X
//==================================
class Obj
{
private:

	//-----------------------------------
	//���W����/2D
	//-----------------------------------
	D3DXVECTOR3  pos = { 0.0f,0.0f ,0.0f };			//�ꏊ
	D3DXVECTOR3  oldpos = { 0.0f,0.0f,0.0f };		//�ߋ����W
	D3DXVECTOR3  size = { 0.0f,0.0f,0.0f };			//�傫��
	D3DXVECTOR3  vel = { 0.0f,0.0f ,0.0f };			//���x
	D3DXVECTOR3  rot = { 0.0f,0.0f ,0.0f };			//��]
	D3DXVECTOR3  scl = { 0.0f,0.0f,0.0f };			//�X�P�[��
	D3DXMATRIX	mtxWorld;							// ���[���h�}�g���b�N�X

	D3DXVECTOR2 notespos = { 0.0f,0.0f };
	float notessize = 10.0f;

	//-----------------------------------
	//�A�j���[�V�����p/�摜
	//-----------------------------------
	int texture = 0;				//�摜�i�[�p
	float U = 1.0f;					//�摜�̏ꏊ�w��pX
	float V = 1.0f;					//�摜�̏ꏊ�w��pY
	float UW = 1.0f;				//�摜�̃T�C�YX
	float VH = 1.0f;				//�摜�̃T�C�YY
	float U_Cut = 1.0f;				//�摜�̉���������
	float V_Cut = 1.0f;				//�摜�̏c��������
	float frameCnt = 0.0f;			//�`�摬�x�̃J�E���g�p
	float frameSet = 0.0f;			//�A�j���[�V�����̍X�V���x�ݒ�
	float red = 1.0f;				//��
	float green = 1.0f;				//��
	float blue = 1.0f;				//��
	float degree = 1.0f;			//���ߓx

	//----------------------------------
	//�ėp
	//----------------------------------
	int cnt = 0;			//�J�E���g�p
	int target = 0;			//�ڕW���l�ݒ�p
	bool flag = false;		//�t���O�Ǘ��p
	//------------------------
	//���֌W
	//------------------------
	int bgm = 0;		//BGM�p
	int se = 0;			//SE�p

protected:
	DX11_MODEL model;				//3D���f���i�[�p

public:
	Obj() {}
	Obj(D3DXVECTOR3 rpos, D3DXVECTOR3 rsize, D3DXVECTOR3 rscl, D3DXVECTOR3 rrot) :pos(rpos), size(rsize), scl(rscl), rot(rrot) {}
	Obj(DX11_MODEL rmodel, D3DXVECTOR3 rpos, D3DXVECTOR3 rsize, D3DXVECTOR3 rscl, D3DXVECTOR3 rrot) :model(rmodel), pos(rpos), size(rsize), scl(rscl), rot(rrot) {}
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	//--------------------------------------------
	//�Z�b�^�[
	//--------------------------------------------
	//-----------------------------------
	//���W����/2D
	//-----------------------------------
	void SetPos(D3DXVECTOR3 sPos) {
		pos = sPos;
	}//X,Y���W�̃Z�b�g
	void SetOldPos(D3DXVECTOR3 sPos) {
		oldpos = sPos;
	}//�ߋ��̍��W�Z�b�g

	void SetPosX(float sPos) {
		pos.x = sPos;
	}//X���W�̃Z�b�g
	void SetPosY(float sPos) {
		pos.y = sPos;
	}//Y���W�̃Z�b�g
	void SetPosZ(float sPos) {
		pos.z = sPos;
	}//Z���W�̃Z�b�g

	void SetOldPosX(float sPos) {
		oldpos.x = sPos;
	}//X���W�̃Z�b�g
	void SetOldPosY(float sPos) {
		oldpos.y = sPos;
	}//Y���W�̃Z�b�g
	void SetOldPosZ(float sPos) {
		oldpos.z = sPos;
	}//Z���W�̃Z�b�g

	void SetSize(D3DXVECTOR3 sSize) {
		size = sSize;
	}//X,Y�T�C�Y�̃Z�b�g
	void SetSizeX(float sSize) {
		size.x = sSize;
	}//X�T�C�Y�̃Z�b�g
	void SetSizeY(float sSize) {
		size.y = sSize;
	}//Y�T�C�Y�̃Z�b�g
	void SetSizeZ(float sSize) {
		size.z = sSize;
	}//Z�T�C�Y�̃Z�b�g
	void SetVel(D3DXVECTOR3 sVel) {
		vel = sVel;
	}//X,Y���x�̃Z�b�g
	void SetVelX(float sVel) {
		vel.x = sVel;
	}//X���x�̃Z�b�g
	void SetVelY(float sVel) {
		vel.y = sVel;
	}//Y���x�̃Z�b�g
	void SetVelZ(float sVel) {
		vel.z = sVel;
	}//Z���x�̃Z�b�g
	void SetRot(D3DXVECTOR3 sRot) {
		rot = sRot;
	}//��]�̃Z�b�g
	void SetRotX(float sRot) {
		rot.x = sRot;
	}//X��]�̃Z�b�g
	void SetRotY(float sRot) {
		rot.y = sRot;
	}//Y��]�̃Z�b�g
	void SetRotZ(float sRot) {
		rot.z = sRot;
	}//Z��]�̃Z�b�g
	void SetScl(D3DXVECTOR3 sScl) {
		scl = sScl;
	}//�X�P�[���̃Z�b�g
	void SetSclX(float sScl) {
		scl.x = sScl;
	}//X��]�̃Z�b�g
	void SetSclY(float sScl) {
		scl.y = sScl;
	}//Y��]�̃Z�b�g
	void SetSclZ(float sScl) {
		scl.z = sScl;
	}//Z��]�̃Z�b�g
	void SetMtxWorld(D3DXMATRIX mtx) {
		mtxWorld = mtx;
	}//���[���h�}�g���b�N�X�̐ݒ�

	void SetNotesPos(D3DXVECTOR2 sNotesPos) {
		notespos = sNotesPos;
	}
	//-----------------------------------
	//�A�j���[�V�����p/�摜
	//-----------------------------------

	void SetModel(DX11_MODEL sModel) {
		model = sModel;
	}//���f���̃Z�b�g
	void SetTexture(int sTex) {
		texture = sTex;
	}//�e�N�X�`���̃Z�b�g
	void SetU(float sU) {
		U = sU;
	}//UV�l��U�̎n�_�ݒ�
	void SetV(float sV) {
		V = sV;
	}//UV�l��V�̎n�_�ݒ�
	void SetUW(float sUW) {
		UW = sUW;
	}//UV�l�̉����ݒ�
	void SetVH(float sVH) {
		VH = sVH;
	}//UV�l�̗����ݒ�
	void SetU_Cut(float sCut) {
		U_Cut = sCut;
	}//���̉摜�������ݒ�
	void SetV_Cut(float sCut) {
		V_Cut = sCut;
	}//�c�̉摜�������ݒ�
	void SetRed(float sRed) {
		red = sRed;
	}//�ԐF�ݒ�
	void SetGreen(float sGreen) {
		green = sGreen;
	}//�ΐF�ݒ�
	void SetBlue(float sBlue) {
		blue = sBlue;
	}//�F�ݒ�
	void SetDegree(float sDgree) {
		degree = sDgree;
	}//���ߓx�ݒ�
	//------------------------
	//�ėp
	//------------------------
	void SetCnt(int sCnt) {
		cnt = sCnt;
	}//�J�E���g�ݒ�
	void SetTarget(int sTarget) {
		target = sTarget;
	}//�ڕW���l�ݒ�
	void SetFlag(bool sFlag) {
		flag = sFlag;
	}//�t���O�ݒ�

	//------------------------
	//���֌W
	//------------------------
	void SetBGM(int sBGM) {
		bgm = sBGM;
	}//BGM�̐ݒ�
	void SetSE(int sSE) {
		se = sSE;
	}//SE�̐ݒ�

	//--------------------------------------------
	//�Q�b�^�[
	//--------------------------------------------
	//-----------------------------------
	//���W����/2D
	//-----------------------------------
	D3DXVECTOR3 GetPos() const {
		return pos;
	}//X,Y���W�̎擾
	float GetPosX()const {
		return pos.x;
	}//X���W�̎擾
	float GetPosY() const {
		return pos.y;
	}//Y���W�̎擾
	float GetPosZ() const {
		return pos.z;
	}//Z���W�̎擾

	D3DXVECTOR3 GetOldPos() const {
		return oldpos;
	}//X,Y���W�̎擾
	float GetOldPosX()const {
		return oldpos.x;
	}//X���W�̎擾
	float GetOldPosY() const {
		return oldpos.y;
	}//Y���W�̎擾
	float GetOldPosZ() const {
		return oldpos.z;
	}//Z���W�̎擾

	D3DXVECTOR3 GetSize() const {
		return size;
	}//X,Y�T�C�Y�̎擾
	float GetSizeX() const {
		return size.x;
	}//X�T�C�Y�̎擾
	float GetSizeY() const {
		return size.y;
	}//Y�T�C�Y�̎擾
	float GetSizeZ() const {
		return size.z;
	}//Y�T�C�Y�̎擾
	D3DXVECTOR3 GetVel() const {
		return vel;
	}//X,Y�T�C�Y�̎擾
	float GetVelX() const {
		return vel.x;
	}//X���x�̎擾
	float GetVelY() const {
		return vel.y;
	}//Y���x�̎擾
	float GetVelZ() const {
		return vel.z;
	}//Z���x�̎擾
	D3DXVECTOR3 GetRot() const {
		return rot;
	}//X,Y�T�C�Y�̎擾
	float GetRotX() const {
		return rot.x;
	}//X��]�̎擾
	float GetRotY() const {
		return rot.y;
	}//Y��]�̎擾
	float GetRotZ() const {
		return rot.z;
	}//Z��]�̎擾
	D3DXVECTOR3 GetScl() const {
		return scl;
	}//X,Y,Z�X�P�[���̎擾
	float GetSclX() const {
		return scl.x;
	}//X�X�P�[���̎擾
	float GetSclY() const {
		return scl.y;
	}//Y�X�P�[���̎擾
	float GetSclZ() const {
		return scl.z;
	}//Z�X�P�[���̎擾

	D3DXMATRIX GetMtxWorld()const {
		return mtxWorld;
	}//���[���h�}�g���b�N�X�̎擾


	D3DXVECTOR2 GetNotesPos() const {
		return notespos;
	}
	//-----------------------------------
	//�A�j���[�V�����p/�摜
	//-----------------------------------

	DX11_MODEL GetModel()const {
		return model;
	}//���f���̎擾
	int GetTexture() const {
		return texture;
	}//�e�N�X�`���̎擾
	float GetU() const {
		return U;
	}//UV�l��U�n�_�擾
	float GetV() const {
		return V;
	}//UV�l��V�n�_�擾
	float GetUW() const {
		return UW;
	}//UV�l��UW�n�_�擾
	float GetVH() const {
		return VH;
	}//UV�l��VH�n�_�擾
	float GetU_Cut() const {
		return U_Cut;
	}//U�̉摜�������擾
	float GetV_Cut() const {
		return V_Cut;
	}//V�̉摜�������擾
	float GetRed() const {
		return red;
	}//�ԐF���̎擾
	float GetGreen() const {
		return green;
	}//�ΐF���̎擾
	float GetBlue() const {
		return blue;
	}//�F���̎擾
	float GetDegree() const {
		return degree;
	}//���ߓx���̎擾
	//------------------------
	//�ėp
	//------------------------
	int GetCnt() const {
		return cnt;
	}//�J�E���g�擾
	int GetTarget() const {
		return target;
	}//�ڕW���l�擾
	bool GetFlag()const {
		return flag;
	}//�t���O�̎擾

	//------------------------
	//���֌W
	//------------------------
	int GetBGM() const {
		return bgm;
	}//BGM�̎擾
	int GetSE() const {
		return se;
	}//SE�̎擾
};