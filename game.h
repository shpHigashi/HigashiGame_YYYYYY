#pragma once

namespace Game
{
	// �E�B���h�E���[�h�ݒ�
	constexpr bool kWindowMode = true;
	// �E�B���h�E��
	const char* const kTitleText = "VVVVVV";
	// �E�B���h�E�T�C�Y
	constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;
	constexpr int kScreenWidthHalf = kScreenWidth / 2;
	constexpr int kScreenHeightHalf = kScreenHeight / 2;

	const char* const kGameMainMusic = "sounddata/Positive Force.mp3";

	// �Q�[���̃X�e�[�W�T�C�Y
	constexpr int kStageUpperLimit = 100;
	constexpr int kStageLowerLimit = 620;

	// �J���[���[�h
	constexpr int kColorDepth = 32;

	// �w�i�p�摜
	const char* const kBackgroundGraph = "imagedata/VVVVVVbackground.png";
	const char* const kPlayerGraph = "imagedata/player.png";
	
	// ��̃t�H���g�T�C�Y
	constexpr int kFontSize = 60;
}