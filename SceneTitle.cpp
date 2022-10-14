#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// ゲームタイトル
	const char* const kGameTitle = "YYYYYY";
	const char* const kTitleMessage = "Zキー or Aボタンを押して";
	const char* const kGameStart = "スタート";
}

void SceneTitle::init()
{
	m_LeftTextPosY = 0;
	m_LeftTextVecY = 4;

	m_isEnd = false;
}

void SceneTitle::update()
{
	// 文字の移動
	m_LeftTextPosY += m_LeftTextVecY;
	if (m_LeftTextPosY < 0)
	{
		m_LeftTextPosY = 0;
		m_LeftTextVecY = 4;
	}
	if (m_LeftTextPosY > 200)
	{
		m_LeftTextPosY = 200;
		m_LeftTextVecY = -4;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneTitle::draw()
{
	SetFontSize(60);
	
	DrawString(0, m_LeftTextPosY, kGameTitle, GetColor(0, 255, 255));
	DrawString(Game::kScreenWidth - GetDrawStringWidth(kGameTitle, 6), m_LeftTextPosY, kGameTitle, GetColor(0, 255, 255));

	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameTitle, 3), 210, kGameTitle, GetColor(0, 255, 255));

	SetFontSize(30);
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kTitleMessage, 12), Game::kScreenHeight / 2, kTitleMessage, GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameStart, 4), Game::kScreenHeight / 2 + 30, kGameStart, GetColor(255, 255, 255));
}