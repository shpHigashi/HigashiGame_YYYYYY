#include "SceneClear.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// ゲームタイトル
	const char* const kGameTitle = "YYYYYY";
	const char* const kGameClear = "GameClear!";
}

void SceneClear::init()
{
	m_isEnd = false;

	m_handle = LoadGraph("imagedata/GameClear.png");
	GetGraphSize(m_handle, &m_width, &m_height);
}

void SceneClear::end()
{
	DeleteGraph(m_handle);
}

void SceneClear::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneClear::draw()
{
	//SetFontSize(60);
	LoadGraphScreen(0, 0, "imagedata/VVVVVVbackground.png", true);
	DrawRotaGraphF(Game::kScreenWidth / 2, Game::kScreenHeight / 2, 1.5, 0, m_handle, true, false);
}