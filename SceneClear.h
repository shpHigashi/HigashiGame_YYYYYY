#pragma once
#include "SceneBase.h"

class SceneClear : public SceneBase
{
public:
	SceneClear()
	{
		m_LeftTextPosY = 0;
		m_LeftTextVecY = 0;
		m_isEnd = false;
	}
	virtual ~SceneClear() {}


	virtual void init();
	virtual void end() {}

	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	// �e�L�X�g�\���ʒu�ύX
	int m_LeftTextPosY;
	int m_LeftTextVecY;

	bool m_isEnd;
};