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
	constexpr int kStageUpperLimit = 100;
	constexpr int kStageLowerLimit = 620;

	// カラーモード
	constexpr int kColorDepth = 32;

	// 基準のフォントサイズ
	constexpr int kFontSize = 60;
}