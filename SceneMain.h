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

	void HitCheck();

	// �G�̐���
	void createEnemyRight();
	void createEnemyLeft();

	virtual bool isGameStop() { return m_isGameStop; }
	virtual bool isEnd() { return m_isEnd; }

private:
	static constexpr int kMobMax = 10;

private:

	// �L�����N�^�[�̃O���t�B�b�N�n���h��
	int m_hBackgroundGraphic;
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;
	int m_hEnemyGraphic;

	// �Q�[���̐�������
	int m_GameTimeRemaining;
	int m_GameOverDelay;
	// 
	int m_waitFrame;

	// �����擾�p�ϐ�
	int m_randNum;

	// �Q�[���I��
	bool m_isGameStop;
	bool m_isEnd;

	// �v���C���[
	Player m_player;

	// �G
	EnemyRight m_EnemyRight[kMobMax];
	EnemyLeft m_EnemyLeft[kMobMax];
};