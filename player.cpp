#include "DxLib.h"
#include "player.h"
#include "game.h"

namespace
{
    constexpr float kColRadius = 16.0f;
    // 移動速度
    constexpr float kMoveSpeed = 12.0f;
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

void Player::init()
{
    m_isDead = false;
    
    m_vec.x = 0;
    m_vec.y = kMoveSpeed;
}

void Player::setHandle(int playerHandle, int playerDeadHandle)
{
    m_aliveHandle = playerHandle;
    m_deadHandle = playerDeadHandle;
    GetGraphSize(m_aliveHandle, &m_width, &m_height);
}

void Player::setPos(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
}

void Player::update()
{
    // パッド(もしくはキーボード)からの入力を取得する
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    m_pos += m_vec;

    if (padState & PAD_INPUT_RIGHT)
    {
        m_pos.x += kMoveSpeed;
        m_isReverseSide = true;
    }
    if (padState & PAD_INPUT_LEFT)
    {
        m_pos.x += -kMoveSpeed;
        m_isReverseSide = false;
    }

    if (getLeft() < 0)
    {
        m_pos.x = 0;
    }
    if (getRight() > Game::kScreenWidth)
    {
        m_pos.x = Game::kScreenWidth - m_width;
    }
    if (getTop() < Game::kStageUpperLimit)
    {
        m_pos.y = Game::kStageUpperLimit;
        m_vec.y *= -1;
        m_isReverseLength = false;
    }
    if (getBottom() > Game::kStageLowerLimit)
    {
        m_pos.y = Game::kStageLowerLimit - m_height;
        m_vec.y *= -1;
        m_isReverseLength = true;
    }
}

void Player::draw()
{
    if (m_isDead && m_isReverseSide && m_isReverseLength)
    {
        DrawRotaGraphF(m_pos.x + 15.0f, m_pos.y + 35.0f, 1.0, DX_PI, m_deadHandle, true, false);
    }
    else if (m_isDead && m_isReverseLength)
    {
        DrawRotaGraphF(m_pos.x + 15.0f, m_pos.y + 35.0f, 1.0, DX_PI, m_deadHandle, true, true);
    }
    else if (m_isDead && m_isReverseSide)
    {
        DrawTurnGraphF(m_pos.x, m_pos.y, m_deadHandle, true);
    }
    else if(m_isDead)
    {
        DrawGraphF(m_pos.x, m_pos.y, m_deadHandle, true);
    }
    else if (m_isReverseSide && m_isReverseLength)
    {
        DrawRotaGraphF(m_pos.x + 15.0f, m_pos.y + 35.0f, 1.0, DX_PI, m_aliveHandle, true, false);
    }
    else if (m_isReverseLength)
    {
        DrawRotaGraphF(m_pos.x + 15.0f, m_pos.y + 35.0f, 1.0, DX_PI, m_aliveHandle, true, true);
    }
    else if (m_isReverseSide)
    {
        DrawTurnGraphF(m_pos.x, m_pos.y, m_aliveHandle, true);
    }
    else
    {
        DrawGraphF(m_pos.x, m_pos.y, m_aliveHandle, true);
    }
}