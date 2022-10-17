#pragma once
#include "SceneBase.h"

class SceneClear : public SceneBase
{
public:
	SceneClear()
	{
		m_isEnd = false;

		m_handle = -1;

		m_width = 0;
		m_height = 0;
	}
	virtual ~SceneClear() {}

	// ������
	virtual void init();
	
	// �I������
	void end();
	// �X�V
	virtual void update();
	// �`��
	virtual void draw();

	// m_isEnd ���擾
	virtual bool isEnd() { return m_isEnd; }
private:
	// �V�[���I��
	bool m_isEnd;

	// �摜�f�[�^
	int m_handle;
	// �摜�T�C�Y
	int m_width;
	int m_height;
};