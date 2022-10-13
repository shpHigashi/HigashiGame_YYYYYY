#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_LeftTextPosY = 0;
		m_LeftTextVecY = 0;
		m_isEnd = false;
	}
	virtual ~SceneTitle() {}


	virtual void init();
	virtual void end() {}

	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	// テキスト表示位置変更
	int m_LeftTextPosY;
	int m_LeftTextVecY;

	bool m_isEnd;
};