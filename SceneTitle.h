#pragma once
#include "SceneBase.h"
#include "TitleChara.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_TextPosY = 0;
		m_TextVecY = 0;

		m_isEnd = false;

		m_handle = -1;
		m_hPlayerGraphic = -1;

		m_width = 0;
		m_height = 0;
	}
	virtual ~SceneTitle() {}

	// ������
	virtual void init();
	
	// �I������
	void end();

	// �X�V����
	virtual void update();
	// �`��
	virtual void draw();

	// m_isEnd ���擾
	virtual bool isEnd() { return m_isEnd; }
private:	
	// �e�L�X�g�\���ʒu�ύX
	int m_TextPosY;
	int m_TextVecY;

	// �^�C�g���\�����I���邩�ǂ���
	bool m_isEnd;

	// �摜�f�[�^
	int m_handle;
	int m_hPlayerGraphic;
	// �摜�T�C�Y
	int m_width;
	int m_height;

	// �v���C���[
	TitleChara m_tChara;
};