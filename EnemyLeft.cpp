#include "EnemyLeft.h"
#include "game.h"
#include "DxLib.h"

namespace
{
    // �摜�̉�]���x
    constexpr float kRotaSpeed = 0.3f;
}

//************************************************************************
// �G�̏o���ʒu��ݒ�
// x���W : ��ʍ��[�̍��W(0.0f)����
// y���W : �X�e�[�W�͈͓��Ń����_���ɍ��W���擾��float�^�ɕϊ������
//************************************************************************
Vec2 EnemyLeft::getRandPos()
{
    m_pos.x = 0.0f;
    m_pos.y = static_cast<float>(GetRand((Game::kStageLowerLimit - m_height) - Game::kStageUpperLimit) + Game::kStageUpperLimit);

    return m_pos;
}

// �G�̍X�V����
void EnemyLeft::update()
{
    // ���݂̍��W�Ɉړ��ʂ���
    m_pos += m_vec;

    // �摜�̉�]�p
    m_angle += kRotaSpeed;
    
    // ��ʉE�[�܂ōs���ƓG�̑��݂� false �ɂ���
    if (m_pos.x > Game::kScreenWidth)
    {
        m_isExist = false;
    }
}