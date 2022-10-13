#pragma once

namespace Game
{
	// ウィンドウモード設定
	constexpr bool kWindowMode = true;
	// ウィンドウ名
	const char* const kTitleText = "YYYYYY";
	// ウィンドウサイズ
	constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;
	constexpr int kScreenInterval = 10;

	// ゲームのステージサイズ
	constexpr float kStageUpperLimit = 100.0f;
	constexpr float kStageLowerLimit = 620.0f;

	// カラーモード
	constexpr int kColorDepth = 32;
}