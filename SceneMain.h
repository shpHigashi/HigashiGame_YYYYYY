#pragma once

#include "player.h"
#include "EnemyRight.h"
#include "EnemyLeft.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();

	void gameEnd();

	void HitCheck();

	// �G�̐���
	void createEnemyRight();
	void createEnemyLeft();

private:
	static constexpr int kMobMax = 5;

private:

	// �L�����N�^�[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;
	int m_hEnemyGraphic;

	// �Q�[���̐�������
	int m_GameTimeRemaining;
	// 
	int m_waitFrame;

	// �����擾�p�ϐ�
	int m_randNum;

	// �Q�[���I��
	bool isGameEnd;

	// �v���C���[
	Player m_player;

	// �G
	EnemyRight m_EnemyRight[kMobMax];
	EnemyLeft m_EnemyLeft[kMobMax];
};