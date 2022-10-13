#pragma once

#include "EnemyBase.h"

class EnemyLeft : public EnemyBase
{

public:
	EnemyLeft() {}
	virtual ~EnemyLeft() {}

	virtual Vec2 getRandPos();

	// XV
	virtual void update();
};