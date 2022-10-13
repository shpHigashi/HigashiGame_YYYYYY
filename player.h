#pragma once
#include "Vec2.h"

class Player
{
public:
	Player();
	virtual ~Player() {}

	virtual void init();
	virtual void setHandle(int playerHandle, int playerDeadHandle);
	virtual void setPos(float x, float y);

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	virtual void update();
	virtual void draw();

	virtual void isDead() { m_isDead = true; }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	Vec2 getPos() const { return m_pos; }
private:
	// �摜�f�[�^
	int m_aliveHandle;
	int m_deadHandle;

	// �摜�T�C�Y
	int m_height;
	int m_width;

	// �\���ʒu
	Vec2 m_pos;

	// �ړ���
	Vec2 m_vec;

	// �摜���]����
	bool m_isReverseSide;
	bool m_isReverseLength;

	// ���S����
	bool m_isDead;
};