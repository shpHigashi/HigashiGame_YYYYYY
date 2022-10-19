#include "DxLib.h"
#include "TitleChara.h"
#include "game.h"

namespace
{
    // �ړ����x
    constexpr float kMoveSpeed = 12.0f;

    // �摜�̕\���ʒu
    constexpr float kPlayerDrawPosX = 16.0f;
    constexpr float kPlayerDrawPosY = 34.0f;
}

TitleChara::TitleChara()
{
    m_playerHandle = -1;

    m_height = 0;
    m_width = 0;

    m_isReverseLength = false;
    m_isReverseSide = true;
}

// �v���C���[�̏�����
void TitleChara::init()
{
    // �ړ��ʂ̏�����
    m_vec.x = kMoveSpeed;
    m_vec.y = kMoveSpeed;
}

// �v���C���[�̉摜�Z�b�g
void TitleChara::setHandle(int playerHandle)
{
    m_playerHandle = playerHandle;
    // �摜�T�C�Y�̎擾
    GetGraphSize(m_playerHandle, &m_width, &m_height);
}

// �v���C���[�̍��W�ݒ�
void TitleChara::setPos(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
}

// �v���C���[�̍X�V����
void TitleChara::update()
{
    // �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // ���݂̍��W�Ɉړ��ʂ�������
    m_pos += m_vec;

    // ��ʒ[�ɍs�����Ƃ����ꍇ
    if (getLeft() < 0)
    {
        m_pos.x = 0.0f;    // ��ʒ[��荶�ɂ͍s���Ȃ�
        m_vec.x *= -1;     // �����ϊ�
        m_isReverseSide = true;      // �摜���]����
    }
    if (getRight() > Game::kScreenWidth)
    {
        m_pos.x = static_cast<float>(Game::kScreenWidth - m_width); // ��ʒ[���E�ɂ͍s���Ȃ�
        m_vec.x *= -1;               // �����ϊ�
        m_isReverseSide = false;     // �摜���]���Ȃ�
    }
    // �X�e�[�W�͈̔͊O�ɍs�����Ƃ����ꍇ
    if (getTop() < 0.0f)
    {
        m_pos.y = 0.0f;   // �X�e�[�W�͈̔͂���ɂ͍s���Ȃ�
        m_vec.y *= -1;                      // �d�͕ύX
        m_isReverseLength = false;          // �摜���]���Ȃ�
    }
    if (getBottom() > Game::kScreenHeight)
    {
        m_pos.y = static_cast<float>(Game::kScreenHeight - m_height);    // �X�e�[�W�͈̔͂�艺�ɂ͍s���Ȃ�
        m_vec.y *= -1;                      // �d�͕ύX
        m_isReverseLength = true;           // �摜���]����
    }
}

// �v���C���[�̕`�揈��
void TitleChara::draw()
{
    // �`��p�x�p�ϐ�
    double angle = 0;
    // �`�捶�E���]�p�ϐ�
    bool isReverseSide = m_isReverseSide;
    if (m_isReverseLength)
    {
        // �㉺���]����ꍇ�A�p�x����
        angle = DX_PI;

        // �㉺���]����ꍇ�A���E���]���t�ɓ���ւ���
        if (isReverseSide) isReverseSide = false;
        else isReverseSide = true;
    }

    // �w�i�L�����N�^�[�`��
    DrawRotaGraphF(m_pos.x + kPlayerDrawPosX, m_pos.y + kPlayerDrawPosY, 1.0, angle, m_playerHandle, true, isReverseSide);
}