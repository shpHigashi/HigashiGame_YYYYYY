#pragma once

#include "EnemyBase.h"

// ������o������G�p�̃N���X
class EnemyLeft : public EnemyBase
{
public:
	EnemyLeft() {}
	virtual ~EnemyLeft() {}

	// �G�̏o���ʒu��ݒ�
	virtual Vec2 getRandPos();

	// �G�̍X�V�X�V
	virtual void update();
};