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

	// 初期化
	virtual void init();
	
	// 終了処理
	void end();
	// 更新
	virtual void update();
	// 描画
	virtual void draw();

	// m_isEnd を取得
	virtual bool isEnd() { return m_isEnd; }
private:
	// シーン終了
	bool m_isEnd;

	// 画像データ
	int m_handle;
	// 画像サイズ
	int m_width;
	int m_height;
};