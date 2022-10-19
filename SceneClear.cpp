#include "SceneClear.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// タイトル表示までの遅延時間 (2秒)
	constexpr int kTitleDelayMax = 120;
}

// 初期化
void SceneClear::init()
{
	// 遅延時間初期化
	titleDelay = kTitleDelayMax;
	
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
	// 1フレームごとに残り遅延時間を減らす
	titleDelay--;
	// 0になったらシーン終了
	if (!titleDelay)
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