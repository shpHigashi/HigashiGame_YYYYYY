#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// �^�C�g�����b�Z�[�W
	const char* const kTitleMessage = "Z�L�[ or A�{�^����������";
	const char* const kGameStart = "�X�^�[�g";
	// �e�L�X�g�̉�]�p�x
	constexpr float kRotaSpeed = 0.02f;
}

void SceneTitle::init()
{
	m_TextPosY = 0;
	m_TextVecY = 4;

	m_angle = 0;

	m_isEnd = false;

	m_handle = LoadGraph("imagedata/VVVVVV_logo.png");
	GetGraphSize(m_handle, &m_width, &m_height);
}

void SceneTitle::update()
{
	//m_angle += kRotaSpeed;
	
	// �����̈ړ�
	m_TextPosY += m_TextVecY;
	if (m_TextPosY < 0)
	{
		m_TextPosY = 0;
		m_TextVecY *= -1;
	}
	if (m_TextPosY > Game::kScreenHeight - m_height)
	{
		m_TextPosY = Game::kScreenHeight - m_height;
		m_TextVecY *= -1;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneTitle::draw()
{
	LoadGraphScreen(0, 0, "imagedata/VVVVVVbackground.png", true);
	
	SetFontSize(30);
	
	DrawGraph(0, m_TextPosY, m_handle, true);
	DrawGraph(Game::kScreenWidth - m_width, m_TextPosY, m_handle, true);

	DrawRotaGraphF(Game::kScreenWidth / 2, Game::kScreenHeight / 3, 1.5, m_angle, m_handle, true, false);

	SetFontSize(30);
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kTitleMessage, 12), Game::kScreenHeight / 2, kTitleMessage, GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameStart, 4), Game::kScreenHeight / 2 + 30, kGameStart, GetColor(255, 255, 255));
}