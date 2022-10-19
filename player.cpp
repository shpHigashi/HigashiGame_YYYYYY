#include "DxLib.h"
#include "player.h"
#include "game.h"

namespace
{
    // �ړ����x
    constexpr float kMoveSpeed = 12.0f;

    // �摜�̕\���ʒu
    constexpr float kPlayerDrawPosX = 16.0f;
    constexpr float kPlayerDrawPosY = 34.0f;
}

Player::Player()
{
    m_aliveHandle = -1;
    m_deadHandle = -1;
    m_height = 0;
    m_width = 0;

    m_isReverseLength = false;
    m_isReverseSide = false;

    m_isDead = false;
}

// �v���C���[�̏�����
void Player::init()
{
    // ���S����� false �ɐݒ�
    m_isDead = false;
    
    // �ړ��ʂ̏�����
    m_vec.x = 0;
    m_vec.y = kMoveSpeed;
}

// �v���C���[�̉摜�Z�b�g
void Player::setHandle(int playerHandle, int playerDeadHandle)
{
    m_aliveHandle = playerHandle;
    m_deadHandle = playerDeadHandle;
    
    // �摜�T�C�Y�̎擾
    GetGraphSize(m_aliveHandle, &m_width, &m_height);
}

// �v���C���[�̍��W�ݒ�
void Player::setPos(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
}

// �v���C���[�̍X�V����
void Player::update()
{
    // �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // ���݂̍��W�Ɉړ��ʂ�������
    m_pos += m_vec;

    // �L�[���͂��������ꍇ
    if (padState & PAD_INPUT_RIGHT) // �E
    {
        m_pos.x += kMoveSpeed;
        m_isReverseSide = true;     // �摜���]����
    }
    if (padState & PAD_INPUT_LEFT)  // ��
    {
        m_pos.x += -kMoveSpeed;
        m_isReverseSide = false;    // �摜���]���Ȃ�
    }

    // ��ʒ[�ɍs�����Ƃ����ꍇ
    if (getLeft() < 0)
    {
        m_pos.x = 0.0f;    // ��ʒ[��荶�ɂ͍s���Ȃ�
    }
    if (getRight() > Game::kScreenWidth)
    {
        m_pos.x = static_cast<float>(Game::kScreenWidth - m_width); // ��ʒ[���E�ɂ͍s���Ȃ�
    }
    // �X�e�[�W�͈̔͊O�ɍs�����Ƃ����ꍇ
    if (getTop() < Game::kStageUpperLimit)
    {
        m_pos.y = Game::kStageUpperLimit;   // �X�e�[�W�͈̔͂���ɂ͍s���Ȃ�
        m_vec.y *= -1;                      // �d�͕ύX
        m_isReverseLength = false;          // �摜���]���Ȃ�
    }
    if (getBottom() > Game::kStageLowerLimit)
    {
        m_pos.y = static_cast<float>(Game::kStageLowerLimit - m_height);    // �X�e�[�W�͈̔͂�艺�ɂ͍s���Ȃ�
        m_vec.y *= -1;                      // �d�͕ύX
        m_isReverseLength = true;           // �摜���]����
    }
}

// �v���C���[�̕`�揈��
void Player::draw()
{
    int handle = m_aliveHandle;
    if (m_isDead)
    {
        handle = m_deadHandle;
    }

    double angle = 0.0;
    bool isReverseSide = m_isReverseSide;
    if (m_isReverseLength)
    {
        angle = DX_PI;
        if (isReverseSide) isReverseSide = false;
        else isReverseSide = true;
    }
    
    DrawRotaGraphF(m_pos.x + kPlayerDrawPosX, m_pos.y + kPlayerDrawPosY, 1.0, angle, handle, true, isReverseSide);
}