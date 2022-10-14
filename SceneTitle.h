#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_TextPosY = 0;
		m_TextVecY = 0;
		
		m_angle = 0;

		m_isEnd = false;

		m_handle = -1;

		m_width = 0;
		m_height = 0;
	}
	virtual ~SceneTitle() {}

	virtual void init();
	virtual void end() {}

	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	// �e�L�X�g�\���ʒu�ύX
	int m_TextPosY;
	int m_TextVecY;

	// �e�L�X�g�̊p�x
	float m_angle;

	// �^�C�g���\�����I���邩�ǂ���
	bool m_isEnd;

	// �摜�f�[�^
	int m_handle;
	// �摜�T�C�Y
	int m_width;
	int m_height;
};