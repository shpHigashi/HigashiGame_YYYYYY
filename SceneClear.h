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


	virtual void init();
	virtual void end() {}

	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;

	// �摜�f�[�^
	int m_handle;
	// �摜�T�C�Y
	int m_width;
	int m_height;
};