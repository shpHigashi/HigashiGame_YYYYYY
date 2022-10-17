#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// �^�C�g�����b�Z�[�W
	const char* const kTitleMessage = "Z�L�[ or A�{�^����������";
	const char* const kGameStart = "�X�^�[�g";
}

// ������
void SceneTitle::init()
{
	// �e�L�X�g���W��������
	m_TextPosY = 0;
	m_TextVecY = 4;

	// �V�[���I���� false ����
	m_isEnd = false;

	// �摜�f�[�^�̓ǂݍ���
	m_handle = LoadGraph("imagedata/VVVVVV_logo.png");
	GetGraphSize(m_handle, &m_width, &m_height);
}

// �I������
void SceneTitle::end()
{
	// �摜�f�[�^�폜
	DeleteGraph(m_handle);
}

// �X�V����
void SceneTitle::update()
{	
	// �����̈ړ�
	m_TextPosY += m_TextVecY;
	
	// ��ʒ[�ɍs�����ꍇ�A�ړ��������t�ɕύX
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
	// �L�[���͂��������ꍇ�A�V�[���I���� true �ɂ���
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

// �`�揈��
void SceneTitle::draw()
{
	// �w�i�摜��ǂݍ���ŕ\��
	LoadGraphScreen(0, 0, Game::kBackgroundGraph, true);
	
	// �Q�[���^�C�g���̉摜�\��
	DrawGraph(0, m_TextPosY, m_handle, true);
	DrawGraph(Game::kScreenWidth - m_width, m_TextPosY, m_handle, true);

	DrawRotaGraphF(Game::kScreenWidth / 2, Game::kScreenHeight / 3, 1.5, 0, m_handle, true, false);

	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(30);
	// �^�C�g���̃e�L�X�g��\��
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kTitleMessage, 12), Game::kScreenHeight / 2, kTitleMessage, GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameStart, 4), Game::kScreenHeight / 2 + 30, kGameStart, GetColor(255, 255, 255));
}