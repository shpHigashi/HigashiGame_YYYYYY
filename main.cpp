#include "DxLib.h"
#include "game.h"
#include "SceneMain.h"
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�B���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[���I������p�̕ϐ��쐬
	int isGameMusicEnd = false;

	SceneManager scene;

	// �摜�̃��[�h
	scene.init();

	int backgroundSound = -1;
	backgroundSound = LoadSoundMem(Game::kGameMainMusic);

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		// ��ʂ̃N���A
		ClearDrawScreen();

		if(!CheckSoundMem(backgroundSound)) PlaySoundMem(backgroundSound, DX_PLAYTYPE_BACK);

		// ���݂̃V�[���̍X�V
		scene.update();

		// ���݂̃V�[���̕`��
		scene.draw();

		// �Q�[���I������
		isGameMusicEnd = scene.isGameMusicEnd();
		// isGameEnd�� true �̏ꍇBGM��~
		if (isGameMusicEnd)
		{
			StopSoundMem(backgroundSound);
		}

		// ����ʂ�\��ʂƓ���ւ���
		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	// �摜�̃A�����[�h
	scene.end();
	DeleteSoundMem(backgroundSound);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}