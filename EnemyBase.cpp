#include "DxLib.h"
#include "EnemyBase.h"
#include "game.h"

namespace
{
    // 基本移動速度
    constexpr float kMoveSpeed = 6.0f;
    // 画像の回転速度
    constexpr float kRotaSpeed = 0.3f;
    // 敵の初期化座標
    constexpr float kSetEnemy = -50.0f;
    // 敵の移動速度の下限、上限
    constexpr int kSpeedLimit = 5;
}

EnemyBase::EnemyBase()
{
    m_handle = -1;
    m_height = 0;
    m_width = 0;

    m_angle = 0.0f;

    m_isExist = false;
}

void EnemyBase::init()
{
    m_vec.x = kMoveSpeed;

    m_pos.y = kSetEnemy;
}

void EnemyBase::setHandle(int handle)
{
    m_handle = handle;
    GetGraphSize(m_handle, &m_width, &m_height);
}

void EnemyBase::start(Vec2 pos)
{
    m_isExist = true;
    m_pos = pos;

    m_vec.x = static_cast<float>(GetRand(kSpeedLimit)) + kSpeedLimit;
}

void EnemyBase::update()
{
    if (!m_isExist) return;
}

void EnemyBase::draw()
{
    DrawRotaGraphF(getCenterX(), getCenterY(), 1.0, m_angle, m_handle, true, false);
}