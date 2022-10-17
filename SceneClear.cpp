#include "SceneClear.h"
#include "DxLib.h"
#include "game.h"

namespace
{
}

// 初期化
void SceneClear::init()
{
	m_isEnd = false;

	// 画像の読み込み
	m_handle = LoadGraph("imagedata/GameClear.png");
	// 画像サイズの取得
	GetGraphSize(m_handle, &m_width, &m_height);
}

// 終了処理
void SceneClear::end()
{
	// 画像データの削除
	DeleteGraph(m_handle);
}

// 更新
void SceneClear::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	// キー入力があった場合シーン終了を 真 にする
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneClear::draw()
{
	// 背景画像の描画
	LoadGraphScreen(0, 0, Game::kBackgroundGraph, true);

	// クリアテキスト画像の表示
	DrawRotaGraphF(Game::kScreenWidthHalf, Game::kScreenHeightHalf, 1.5, 0, m_handle, true, false);
}