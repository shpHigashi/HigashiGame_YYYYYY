#include "DxLib.h"
#include "EnemyBase.h"
#include "game.h"

namespace
{
    // ��{�ړ����x
    constexpr float kMoveSpeed = 6.0f;
    // �G�̏������ʒu
    constexpr float kSetPos = 0.0f;
    // �G�̈ړ����x�̉����A���
    constexpr int kSpeedLimitMax = 12;
    constexpr int kSpeedLimitMin = 5;
}

EnemyBase::EnemyBase()
{
    m_handle = -1;
    m_height = 0;
    m_width = 0;

    m_angle = 0.0f;

    m_isExist = false;
}

//**************************************
// ������
// �G�̈ړ����x�ƍ��W�������ʒu�ɐݒ�
//**************************************
void EnemyBase::init()
{
    m_vec.x = kMoveSpeed;
    m_vec.y = 0.0f;
    
    m_pos.x = kSetPos;
    m_pos.y = kSetPos;

    m_isExist = false;
}

// �摜�̃Z�b�g
void EnemyBase::setHandle(int handle)
{
    m_handle = handle;
    GetGraphSize(m_handle, &m_width, &m_height);
}

//***************************************************************************************
// �G�̏o������
// ���� pos : �G�̏o���ʒu�������Ƃ��Ď擾��m_pos�ɑ��
// �G�����݂��Ă��邩�� true �ɂ��Ax���W�̈ړ����x�𗐐��Ŏ擾�� m_vec.x �ɑ��
//***************************************************************************************
void EnemyBase::start(Vec2 pos)
{
    m_isExist = true;
    m_pos = pos;
    m_vec.x = static_cast<float>(GetRand(kSpeedLimitMax)) + kSpeedLimitMin;
}

// �G�̍X�V����
void EnemyBase::update()
{
    if (!m_isExist) return;
}

// �G�̕`�揈��
void EnemyBase::draw()
{
    DrawRotaGraphF(getCenterX(), getCenterY(), 1.0, m_angle, m_handle, true, false);
}