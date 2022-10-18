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
	m_hClearTextGraphic = LoadGraph("imagedata/GameClear.png");
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	// 画像サイズの取得
	GetGraphSize(m_hClearTextGraphic, &m_width, &m_height);
}

// 終了処理
void SceneClear::end()
{
	// 画像データの削除
	DeleteGraph(m_hClearTextGraphic);
	DeleteGraph(m_hBackgroundGraphic);
}

// 更新
void SceneClear::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	// キー入力があった場合シーン終了を true にする
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneClear::draw()
{
	// 背景画像の描画
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	// クリアテキスト画像の表示
	DrawRotaGraphF(Game::kScreenWidthHalf, Game::kScreenHeightHalf, 1.5, 0, m_hClearTextGraphic, true, false);
}