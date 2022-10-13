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

private:
	static constexpr int kMobMax = 10;

private:

	// �L�����N�^�[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;
	int m_hEnemyGraphic;

	int m_waitFrame;
	int m_randNum;

	// �v���C���[
	Player m_player;

	// �G
	EnemyRight m_EnemyRight[kMobMax];
	EnemyLeft m_EnemyLeft[kMobMax];
};