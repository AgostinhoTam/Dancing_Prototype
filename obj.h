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
	D3DXVECTOR3  size = { 0.0f,0.0f,0.0f };			//�傫��
	D3DXVECTOR3  vel = { 0.0f,0.0f ,0.0f };			//���x
	D3DXVECTOR3  rot = { 0.0f,0.0f ,0.0f };			//��]
	D3DXVECTOR3  scl = { 0.0f,0.0f,0.0f };			//�X�P�[��
	D3DXMATRIX	mtxWorld;							// ���[���h�}�g���b�N�X

	//-----------------------------------
	//�v���C���[�A�G�l�~�[�̍��W����/3D
	//-----------------------------------
	D3DXVECTOR3  playerPos = { 0.0f,0.0f,0.0f };		//�v���C���[�̏ꏊ
	D3DXVECTOR3  playerSize = { 0.0f,0.0f,0.0f };		//�v���C���[�̑傫��
	D3DXVECTOR3  playerVel = { 0.0f,0.0f,0.0f };		//�v���C���[�̑��x
	D3DXVECTOR3  playerOldpos = { 0.0f,0.0f,0.0f };		//�v���C���[�̉ߋ����W
	D3DXVECTOR3  playerRot = { 0.0f,0.0f,0.0f };		//�v���C���[�̉�]
	D3DXVECTOR3  playerScl = { 0.0f,0.0f,0.0f };		//�v���C���[�̃X�P�[��
	D3DXVECTOR3  enemyPos = { 0.0f,0.0f,0.0f };			//�G�l�~�[�̏ꏊ
	D3DXVECTOR3  enemySize = { 0.0f,0.0f,0.0f };		//�G�l�~�[�̑傫��
	D3DXVECTOR3  enemyVel = { 0.0f,0.0f,0.0f };			//�G�l�~�[�̑��x
	D3DXVECTOR3  enemyOldpos = { 0.0f,0.0f,0.0f };		//�G�l�~�[�̉ߋ����W
	D3DXVECTOR3  enemyRot = { 0.0f,0.0f,0.0f };			//�G�l�~�[�̉�]
	D3DXVECTOR3  enemyScl = { 0.0f,0.0f,0.0f };		//�v���C���[�̃X�P�[��

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

	Obj() {};
	~Obj() {};
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
	void SetPosX(float sPos) {
		pos.x = sPos;
	}//X���W�̃Z�b�g
	void SetPosY(float sPos) {
		pos.y = sPos;
	}//Y���W�̃Z�b�g
	void SetPosZ(float sPos) {
		pos.z = sPos;
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

	//-----------------------------------
	//�v���C���[�A�G�l�~�[�̍��W����
	//-----------------------------------
	void SetPlayerPos(D3DXVECTOR3 sPos) {
		playerPos = sPos;
	}//X,Y,Z���W�̃Z�b�g
	void SetPlayerPosX(float sPos) {
		playerPos.x = sPos;
	}//X���W�̃Z�b�g
	void SetPlayerPosY(float sPos) {
		playerPos.y = sPos;
	}//Y���W�̃Z�b�g
	void SetPlayerPosZ(float sPos) {
		playerPos.z = sPos;
	}//Z���W�̃Z�b�g
	void SetPlayerSize(D3DXVECTOR3 sSize) {
		playerSize = sSize;
	}//X,Y,Z�T�C�Y�̃Z�b�g
	void SetPlayerSizeX(float sSize) {
		playerSize.x = sSize;
	}//X�T�C�Y�̃Z�b�g
	void SetPlayerSizeY(float sSize) {
		playerSize.y = sSize;
	}//Y�T�C�Y�̃Z�b�g
	void SetPlayerSizeZ(float sSize) {
		playerSize.z = sSize;
	}//Z�T�C�Y�̃Z�b�g
	void SetPlayerVel(D3DXVECTOR3 sVel) {
		playerVel = sVel;
	}//X,Y���x�̃Z�b�g
	void SetPlayerVelX(float sVel) {
		playerVel.x = sVel;
	}//X���x�̃Z�b�g
	void SetPlayerVelY(float sVel) {
		playerVel.y = sVel;
	}//Y���x�̃Z�b�g
	void SetPlayerVelZ(float sVel) {
		playerVel.z = sVel;
	}//Z���x�̃Z�b�g
	void SetPlayerOldpos(D3DXVECTOR3 sOldpos) {
		playerOldpos = sOldpos;
	}//X,Y,Z�ߋ����W�̃Z�b�g
	void SetPlayerOldposX(float sOldpos) {
		playerOldpos.x = sOldpos;
	}//X�ߋ����W�̃Z�b�g
	void SetPlayerOldposY(float sOldpos) {
		playerOldpos.y = sOldpos;
	}//Y�ߋ����W�̃Z�b�g
	void SetPlayerOldposZ(float sOldpos) {
		playerOldpos.z = sOldpos;
	}//Z�ߋ����W�̃Z�b�g
	void SetPlayerRot(D3DXVECTOR3 sPlayerRot) {
		playerRot = sPlayerRot;
	}//�v���C���[�̉�]�̃Z�b�g
	void SetPlayerRotX(float sPlayerRot) {
		playerRot.x = sPlayerRot;
	}//X��]�̃v���C���[�̃Z�b�g
	void SetPlayerRotY(float sPlayerRot) {
		playerRot.y = sPlayerRot;
	}//Y��]�̃v���C���[�̃Z�b�g
	void SetPlayerRotZ(float sPlayerRot) {
		playerRot.z = sPlayerRot;
	}//Z��]�̃v���C���[�̃Z�b�g
	void SetPlayerScl(D3DXVECTOR3 sPlayerScl) {
		playerScl = sPlayerScl;
	}//�X�P�[���̃Z�b�g
	void SetPlayerSclX(float sPlayerScl) {
		playerScl.x = sPlayerScl;
	}//X��]�̃Z�b�g
	void SetPlayerSclY(float sPlayerScl) {
		playerScl.y = sPlayerScl;
	}//Y��]�̃Z�b�g
	void SetPlayerSclZ(float sPlayerScl) {
		playerScl.z = sPlayerScl;
	}//Z��]�̃Z�b�g

	void SetEnemyPos(D3DXVECTOR3 sPos) {
		enemyPos = sPos;
	}//X,Y,Z���W�̃Z�b�g
	void SetEnemyPosX(float sPos) {
		enemyPos.x = sPos;
	}//X���W�̃Z�b�g
	void SetEnemyPosY(float sPos) {
		enemyPos.y = sPos;
	}//Y���W�̃Z�b�g
	void SetEnemyPosZ(float sPos) {
		enemyPos.z = sPos;
	}//Z���W�̃Z�b�g
	void SetEnemySize(D3DXVECTOR3 sSize) {
		enemySize = sSize;
	}//X,Y,Z�T�C�Y�̃Z�b�g
	void SetEnemySizeX(float sSize) {
		enemySize.x = sSize;
	}//X�T�C�Y�̃Z�b�g
	void SetEnemySizeY(float sSize) {
		enemySize.y = sSize;
	}//Y�T�C�Y�̃Z�b�g
	void SetEnemySizeZ(float sSize) {
		enemySize.z = sSize;
	}//Z�T�C�Y�̃Z�b�g
	void SetEnemyVel(D3DXVECTOR3 sVel) {
		enemyVel = sVel;
	}//X,Y���x�̃Z�b�g
	void SetEnemyVelX(float sVel) {
		enemyVel.x = sVel;
	}//X���x�̃Z�b�g
	void SetEnemyVelY(float sVel) {
		enemyVel.y = sVel;
	}//Y���x�̃Z�b�g
	void SetEnemyVelZ(float sVel) {
		enemyVel.z = sVel;
	}//Z���x�̃Z�b�g
	void SetEnemyOldpos(D3DXVECTOR3 sOldpos) {
		enemyOldpos = sOldpos;
	}//X,Y,Z�ߋ����W�̃Z�b�g
	void SetEnemyOldposX(float sOldpos) {
		enemyOldpos.x = sOldpos;
	}//X�ߋ����W�̃Z�b�g
	void SetEnemyOldposY(float sOldpos) {
		enemyOldpos.y = sOldpos;
	}//Y�ߋ����W�̃Z�b�g
	void SetEnemyOldposZ(float sOldpos) {
		enemyOldpos.z = sOldpos;
	}//Z�ߋ����W�̃Z�b�g
	void SetEnemyRot(D3DXVECTOR3 sEnemyRot) {
		enemyRot = sEnemyRot;
	}//�v���C���[�̉�]�̃Z�b�g
	void SetEnemyRotX(float sEnemyRot) {
		enemyRot.x = sEnemyRot;
	}//X��]�̃v���C���[�̃Z�b�g
	void SetEnemyRotY(float sEnemyRot) {
		enemyRot.y = sEnemyRot;
	}//Y��]�̃v���C���[�̃Z�b�g
	void SetEnemyRotZ(float sEnemyRot) {
		enemyRot.z = sEnemyRot;
	}//Z��]�̃v���C���[�̃Z�b�g
	void SetEnemyScl(D3DXVECTOR3 sEnemyScl) {
		enemyScl = sEnemyScl;
	}//�X�P�[���̃Z�b�g
	void SetEnemySclX(float sEnemyScl) {
		enemyScl.x = sEnemyScl;
	}//X�X�P�[���̃Z�b�g
	void SetEnemySclY(float sEnemyScl) {
		enemyScl.y = sEnemyScl;
	}//Y�X�P�[���̃Z�b�g
	void SetEnemySclZ(float sEnemyScl) {
		enemyScl.z = sEnemyScl;
	}//Z�X�P�[���̃Z�b�g

	//-----------------------------------
	//�A�j���[�V�����p/�摜
	//-----------------------------------

	//void SetModel(DX11_MODEL sModel) {
	//	model = sModel;
	//}//���f���̃Z�b�g
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
	//-----------------------------------
	//�v���C���[�A�G�l�~�[�̍��W����
	//-----------------------------------
	D3DXVECTOR3 GetPlayerPos() const {
		return playerPos;
	}//X,Y,Z�v���C���[���W�̎擾
	float GetPlayerPosX()const {
		return playerPos.x;
	}//X�v���C���[���W�̎擾
	float GetPlayerPosY() const {
		return playerPos.y;
	}//X�v���C���[���W�̎擾
	float GetPlayerPosZ() const {
		return playerPos.z;
	}//Z�v���C���[���W�̎擾
	D3DXVECTOR3 GetPlayerSize() const {
		return playerSize;
	}//X,Y�v���C���[�T�C�Y�̎擾
	float GetPlayerSizeX() const {
		return playerSize.x;
	}//X�v���C���[�T�C�Y�̎擾
	float GetPlayerSizeY() const {
		return playerSize.y;
	}//Y�v���C���[�T�C�Y�̎擾
	float GetPlayerSizeZ() const {
		return playerSize.z;
	}//Z�v���C���[�T�C�Y�̎擾
	D3DXVECTOR3 GetPlayerVel() const {
		return playerVel;
	}//X,Y,Z�v���C���[���x�̎擾
	float GetPlayerVelX() const {
		return playerVel.x;
	}//X�v���C���[���x�̎擾
	float GetPlayerVelY() const {
		return playerVel.y;
	}//Y�v���C���[�̑��x�擾
	float GetPlayerVelZ() const {
		return playerVel.z;
	}//Z�v���C���[�̑��x�擾
	D3DXVECTOR3 GetPlayerOldpos() const {
		return playerOldpos;
	}//X,Y,Z�v���C���[�ߋ����W�̎擾
	float GetPlayerOldposX() const {
		return playerOldpos.x;
	}//X�v���C���[�ߋ����W�̎擾
	float GetPlayerOldposY() const {
		return playerOldpos.y;
	}//Y�v���C���[�ߋ����W�̎擾
	float GetPlayerOldposZ() const {
		return playerOldpos.z;
	}//Z�v���C���[�ߋ����W�̎擾
	D3DXVECTOR3 GetPlayerRot() const {
		return playerRot;
	}//X,Y,Z�v���C���[��]�l�̎擾
	float GetPlayerRotX() const {
		return playerRot.x;
	}//X�v���C���[��]�l�̎擾
	float GetPlayerRotY() const {
		return playerRot.y;
	}//Y�v���C���[��]�l�̎擾
	float GetPlayerRotZ() const {
		return playerRot.z;
	}//Z�v���C���[��]�l�̎擾
	D3DXVECTOR3 GetPlayerScl() const {
		return playerScl;
	}//X,Y,Z�X�P�[���̎擾
	float GetPlayerSclX() const {
		return playerScl.x;
	}//X�X�P�[���̎擾
	float GetPlayerSclY() const {
		return playerScl.y;
	}//Y�X�P�[���̎擾
	float GetPlayerSclZ() const {
		return playerScl.z;
	}//Z�X�P�[���̎擾

	D3DXVECTOR3 GetEnemyPos() const {
		return enemyPos;
	}//X,Y,Z�G�l�~�[���W�̎擾
	float GetEnemyPosX()const {
		return enemyPos.x;
	}//X�G�l�~�[���W�̎擾
	float GetEnemyPosY() const {
		return enemyPos.y;
	}//X�G�l�~�[���W�̎擾
	float GetEnemyPosZ() const {
		return enemyPos.z;
	}//Z�G�l�~�[���W�̎擾
	D3DXVECTOR3 GetEnemySize() const {
		return enemySize;
	}//X,Y�G�l�~�[�T�C�Y�̎擾
	float GetEnemySizeX() const {
		return enemySize.x;
	}//X�G�l�~�[�T�C�Y�̎擾
	float GetEnemySizeY() const {
		return enemySize.y;
	}//Y�G�l�~�[�T�C�Y�̎擾
	float GetEnemySizeZ() const {
		return enemySize.z;
	}//Z�G�l�~�[�T�C�Y�̎擾
	D3DXVECTOR3 GetEnemyVel() const {
		return enemyVel;
	}//X,Y,Z�G�l�~�[���x�̎擾
	float GetEnemyVelX() const {
		return enemyVel.x;
	}//X�G�l�~�[���x�̎擾
	float GetEnemyVelY() const {
		return enemyVel.y;
	}//Y�G�l�~�[�̑��x�擾
	float GetEnemyVelZ() const {
		return enemyVel.z;
	}//Z�G�l�~�[�̑��x�擾
	D3DXVECTOR3 GetEnemyOldpos() const {
		return enemyOldpos;
	}//X,Y,Z�G�l�~�[�ߋ����W�̎擾
	float GetEnemyOldposX() const {
		return enemyOldpos.x;
	}//X�G�l�~�[�ߋ����W�̎擾
	float GetEnemyOldposY() const {
		return enemyOldpos.y;
	}//Y�G�l�~�[�ߋ����W�̎擾
	float GetEnemyOldposZ() const {
		return enemyOldpos.z;
	}//Z�G�l�~�[�ߋ����W�̎擾
	D3DXVECTOR3 GetEnemyScl() const {
		return enemyScl;
	}//X,Y,Z�X�P�[���̎擾
	float GetEnemySclX() const {
		return enemyScl.x;
	}//X�X�P�[���̎擾
	float GetEnemySclY() const {
		return enemyScl.y;
	}//Y�X�P�[���̎擾
	float GetEnemySclZ() const {
		return enemyScl.z;
	}//Z�X�P�[���̎擾

	//-----------------------------------
	//�A�j���[�V�����p/�摜
	//-----------------------------------

	//DX11_MODEL GetModel()const {
	//	return model;
	//}//���f���̎擾
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