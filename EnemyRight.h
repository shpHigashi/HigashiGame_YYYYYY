#pragma once

#include "EnemyBase.h"

// �E����o������G�p�̃N���X
class EnemyRight : public EnemyBase
{
public:
	EnemyRight() {}
	virtual ~EnemyRight() {}

	// �G�̏o���ʒu��ݒ�
	virtual Vec2 getRandPos();

	// �G�̍X�V����
	virtual void update();
};