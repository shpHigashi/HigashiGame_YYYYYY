#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneClear.h"

class SceneManager
{
public:
	// ƒV[ƒ“‚Ìí—Ş’è‹`
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

	void init(SceneKind kind = kSceneKindTitle);
	void end();

	void update();
	void draw();

	bool getIsGameEnd() { return m_isGameEnd; }

private:
	bool m_isGameEnd;
	
	SceneKind	m_kind;

	SceneTitle	m_title;
	SceneMain	m_main;
	SceneClear	m_clear;

	Player m_player;
};