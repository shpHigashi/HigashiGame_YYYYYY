#include "SceneClear.h"
#include "DxLib.h"
#include "game.h"

namespace
{
}

// ������
void SceneClear::init()
{
	m_isEnd = false;

	// �摜�̓ǂݍ���
	m_handle = LoadGraph("imagedata/GameClear.png");
	// �摜�T�C�Y�̎擾
	GetGraphSize(m_handle, &m_width, &m_height);
}

// �I������
void SceneClear::end()
{
	// �摜�f�[�^�̍폜
	DeleteGraph(m_handle);
}

// �X�V
void SceneClear::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	// �L�[���͂��������ꍇ�V�[���I���� �^ �ɂ���
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneClear::draw()
{
	// �w�i�摜�̕`��
	LoadGraphScreen(0, 0, Game::kBackgroundGraph, true);

	// �N���A�e�L�X�g�摜�̕\��
	DrawRotaGraphF(Game::kScreenWidthHalf, Game::kScreenHeightHalf, 1.5, 0, m_handle, true, false);
}