#pragma once
#include "Vec2.h"

// �G���N���X
class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase() {}

	// ������
	virtual void init();
	// �摜�̃Z�b�g
	virtual void setHandle(int handle);

	// �G�̏o������
	virtual void start(Vec2 pos);
	// �G�̍X�V����
	virtual void update();
	// �G�̕`�揈��
	virtual void draw();

	// �G�̒��S���W�擾
	virtual float getCenterX() { return m_pos.x + (m_width / 2); }
	virtual float getCenterY() { return m_pos.y + (m_height / 2); }

	// �����蔻��p�Ɏl�����̍��W�擾�@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// �G�����݂��Ă��邩
	bool isExist()const { return m_isExist; }

protected:
	// �摜�f�[�^
	int m_handle;

	// �摜�T�C�Y
	int m_height;
	int m_width;

	// �\���ʒu
	Vec2 m_pos;

	// �ړ���
	Vec2 m_vec;

	//���݂��邩
	bool m_isExist;

	// �摜�̊p�x
	float m_angle;
};