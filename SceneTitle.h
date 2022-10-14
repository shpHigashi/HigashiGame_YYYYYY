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
	// テキスト表示位置変更
	int m_TextPosY;
	int m_TextVecY;

	// テキストの角度
	float m_angle;

	// タイトル表示を終えるかどうか
	bool m_isEnd;

	// 画像データ
	int m_handle;
	// 画像サイズ
	int m_width;
	int m_height;
};