#pragma once
#include "Vec2.h"

// �v���C���[�N���X
class TitleChara
{
public:
	TitleChara();
	virtual ~TitleChara() {}

	// �v���C���[�̏�����
	virtual void init();
	// �v���C���[�̉摜�Z�b�g
	virtual void setHandle(int playerHandle);
	// �v���C���[�̍��W�ݒ�
	virtual void setPos(float x, float y);

	// �v���C���[�̍X�V����
	virtual void update();
	// �v���C���[�̕`�揈��
	virtual void draw();

	// �v���C���[�̒��S���W�擾
	virtual float getCenterX() { return m_pos.x + (m_height / 2); }
	virtual float getCenterY() { return m_pos.y + (m_height / 2); }

	// �l�����̍��W�擾�@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

private:
	// �摜�f�[�^
	int m_playerHandle;	// ��

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
};