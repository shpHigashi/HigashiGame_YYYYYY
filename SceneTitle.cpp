#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

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
	
	DrawString(0, m_LeftTextPosY, "YYYYYY", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 187, m_LeftTextPosY, "YYYYYY", GetColor(255, 255, 255));

	DrawString(Game::kScreenWidth / 2 - 90, 210, "YYYYYY", GetColor(255, 255, 255));

	SetFontSize(30);
	DrawString(Game::kScreenWidth / 2 - 201, Game::kScreenHeight / 2, "Zキーを押してゲームスタート", GetColor(255, 255, 255));
}