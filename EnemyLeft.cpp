#include "EnemyLeft.h"
#include "game.h"
#include "DxLib.h"

namespace
{
    // ‰æ‘œ‚Ì‰ñ“]‘¬“x
    constexpr float kRotaSpeed = 0.3f;
}

Vec2 EnemyLeft::getRandPos()
{
    m_pos.x = 0;
    m_pos.y = static_cast<float>(GetRand(Game::kStageLowerLimit - Game::kStageUpperLimit) + Game::kStageUpperLimit);

    return m_pos;
}

void EnemyLeft::update()
{
    m_pos += m_vec;

    m_angle += kRotaSpeed;
    
    if (m_pos.x > Game::kScreenWidth)
    {
        m_isExist = false;
    }
}