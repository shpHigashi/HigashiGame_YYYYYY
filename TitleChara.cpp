#include "DxLib.h"
#include "TitleChara.h"
#include "game.h"

namespace
{
    // 移動速度
    constexpr float kMoveSpeed = 12.0f;

    // 画像の表示位置
    constexpr float kPlayerDrawPosX = 16.0f;
    constexpr float kPlayerDrawPosY = 34.0f;
}

TitleChara::TitleChara()
{
    m_playerHandle = -1;

    m_height = 0;
    m_width = 0;

    m_isReverseLength = false;
    m_isReverseSide = false;
}

// プレイヤーの初期化
void TitleChara::init()
{
    // 移動量の初期化
    m_vec.x = kMoveSpeed;
    m_vec.y = kMoveSpeed;
}

// プレイヤーの画像セット
void TitleChara::setHandle(int playerHandle)
{
    m_playerHandle = playerHandle;
    // 画像サイズの取得
    GetGraphSize(m_playerHandle, &m_width, &m_height);
}

// プレイヤーの座標設定
void TitleChara::setPos(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
}

// プレイヤーの更新処理
void TitleChara::update()
{
    // パッド(もしくはキーボード)からの入力を取得する
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // 現在の座標に移動量を加える
    m_pos += m_vec;

    // 画面端に行こうとした場合
    if (getLeft() < 0)
    {
        m_pos.x = 0.0f;    // 画面端より左には行かない
        m_vec.x *= -1;     // 方向変換
        m_isReverseSide = true;      // 画像反転する
    }
    if (getRight() > Game::kScreenWidth)
    {
        m_pos.x = static_cast<float>(Game::kScreenWidth - m_width); // 画面端より右には行かない
        m_vec.x *= -1;               // 方向変換
        m_isReverseSide = false;     // 画像反転しない
    }
    // ステージの範囲外に行こうとした場合
    if (getTop() < 0.0f)
    {
        m_pos.y = 0.0f;   // ステージの範囲より上には行かない
        m_vec.y *= -1;                      // 重力変更
        m_isReverseLength = false;          // 画像反転しない
    }
    if (getBottom() > Game::kScreenHeight)
    {
        m_pos.y = static_cast<float>(Game::kScreenHeight - m_height);    // ステージの範囲より下には行かない
        m_vec.y *= -1;                      // 重力変更
        m_isReverseLength = true;           // 画像反転する
    }
}

// プレイヤーの描画処理
void TitleChara::draw()
{
    // 左右、上下の反転、死亡時のプレイヤーでそれぞれ描画する
    if (m_isReverseSide && m_isReverseLength)
    {
        DrawRotaGraphF(m_pos.x + kPlayerDrawPosX, m_pos.y + kPlayerDrawPosY, 1.0, DX_PI, m_playerHandle, true, false);
    }
    else if (m_isReverseLength)
    {
        DrawRotaGraphF(m_pos.x + kPlayerDrawPosX, m_pos.y + kPlayerDrawPosY, 1.0, DX_PI, m_playerHandle, true, true);
    }
    else if (m_isReverseSide)
    {
        DrawTurnGraphF(m_pos.x, m_pos.y, m_playerHandle, true);
    }
    else
    {
        DrawGraphF(m_pos.x, m_pos.y, m_playerHandle, true);
    }
    //DrawBox(getLeft(), getTop(), getRight(), getBottom(), GetColor(255, 255, 255), false);
}