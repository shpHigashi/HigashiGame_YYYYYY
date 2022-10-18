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
	m_hClearTextGraphic = LoadGraph("imagedata/GameClear.png");
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	// �摜�T�C�Y�̎擾
	GetGraphSize(m_hClearTextGraphic, &m_width, &m_height);
}

// �I������
void SceneClear::end()
{
	// �摜�f�[�^�̍폜
	DeleteGraph(m_hClearTextGraphic);
	DeleteGraph(m_hBackgroundGraphic);
}

// �X�V
void SceneClear::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	// �L�[���͂��������ꍇ�V�[���I���� true �ɂ���
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneClear::draw()
{
	// �w�i�摜�̕`��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	// �N���A�e�L�X�g�摜�̕\��
	DrawRotaGraphF(Game::kScreenWidthHalf, Game::kScreenHeightHalf, 1.5, 0, m_hClearTextGraphic, true, false);
}