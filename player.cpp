#include "DxLib.h"
#include "player.h"
#include "game.h"

namespace
{
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

// プレイヤーの初期化
void Player::init()
{
    // 死亡判定を false に設定
    m_isDead = false;
    
    // 移動量の初期化
    m_vec.x = 0;
    m_vec.y = kMoveSpeed;
}

// プレイヤーの画像セット
void Player::setHandle(int playerHandle, int playerDeadHandle)
{
    m_aliveHandle = playerHandle;
    m_deadHandle = playerDeadHandle;
    
    // 画像サイズの取得
    GetGraphSize(m_aliveHandle, &m_width, &m_height);
}

// プレイヤーの座標設定
void Player::setPos(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
}

// プレイヤーの更新処理
void Player::update()
{
    // パッド(もしくはキーボード)からの入力を取得する
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // 現在の座標に移動量を加える
    m_pos += m_vec;

    // キー入力があった場合
    if (padState & PAD_INPUT_RIGHT) // 右
    {
        m_pos.x += kMoveSpeed;
        m_isReverseSide = true;     // 画像反転する
    }
    if (padState & PAD_INPUT_LEFT)  // 左
    {
        m_pos.x += -kMoveSpeed;
        m_isReverseSide = false;    // 画像反転しない
    }

    // 画面端に行こうとした場合
    if (getLeft() < 0)
    {
        m_pos.x = 0.0f;    // 画面端より左には行かない
    }
    if (getRight() > Game::kScreenWidth)
    {
        m_pos.x = static_cast<float>(Game::kScreenWidth - m_width); // 画面端より右には行かない
    }
    // ステージの範囲外に行こうとした場合
    if (getTop() < Game::kStageUpperLimit)
    {
        m_pos.y = Game::kStageUpperLimit;   // ステージの範囲より上には行かない
        m_vec.y *= -1;                      // 重力変更
        m_isReverseLength = false;          // 画像反転しない
    }
    if (getBottom() > Game::kStageLowerLimit)
    {
        m_pos.y = static_cast<float>(Game::kStageLowerLimit - m_height);    // ステージの範囲より下には行かない
        m_vec.y *= -1;                      // 重力変更
        m_isReverseLength = true;           // 画像反転する
    }
}

// プレイヤーの描画処理
void Player::draw()
{
    // 左右、上下の反転、死亡時のプレイヤーでそれぞれ描画する
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