#pragma once

#include "EnemyBase.h"

class EnemyRight : public EnemyBase
{

public:
	EnemyRight() {}
	virtual ~EnemyRight() {}

	virtual Vec2 getRandPos();

	// XV
	virtual void update();
};