#include "EnemyRight.h"
#include "game.h"
#include "DxLib.h"

namespace
{
    // �摜�̉�]���x
    constexpr float kRotaSpeed = 0.3f;
}

//************************************************************************
// �G�̏o���ʒu��ݒ�
// x���W : ��ʉE�[�̍��W(kScreenWidth)����
// y���W : �X�e�[�W�͈͓��Ń����_���ɍ��W���擾��float�^�ɕϊ������
//************************************************************************
Vec2 EnemyRight::getRandPos()
{
    m_pos.x = Game::kScreenWidth;
    m_pos.y = static_cast<float>(GetRand((Game::kStageLowerLimit - m_height) - Game::kStageUpperLimit) + Game::kStageUpperLimit);

    return m_pos;
}

// �G�̍X�V����
void EnemyRight::update()
{
    // ���݂̍��W�Ɉړ��ʂ���
    m_pos -= m_vec;

    // �摜�̉�]
    m_angle -= kRotaSpeed;

    // ��ʍ��[�܂ōs���ƓG�̑��݂� false �ɂ���
    if (m_pos.x < 0)
    {
        m_isExist = false;
    }
}