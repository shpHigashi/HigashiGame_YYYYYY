#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneClear.h"

class SceneManager
{
public:
	// シーンの種類定義
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,
		kSceneKindClear,

		kSceneKindNum
	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager();

	// 初期化
	void init(SceneKind kind = kSceneKindTitle);
	// 削除
	void end();

	// 更新
	void update();
	// 描画
	void draw();

	// m_isGameEnd を取得
	bool getIsGameEnd() { return m_isGameEnd; }

private:
	// ゲーム終了
	bool m_isGameEnd;
	
	SceneKind	m_kind;

	SceneTitle	m_title;
	SceneMain	m_main;
	SceneClear	m_clear;

	Player m_player;
};