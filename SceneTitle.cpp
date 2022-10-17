#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// タイトルメッセージ
	const char* const kTitleMessage = "Zキー or Aボタンを押して";
	const char* const kGameStart = "スタート";
}

// 初期化
void SceneTitle::init()
{
	// テキスト座標を初期化
	m_TextPosY = 0;
	m_TextVecY = 4;

	// シーン終了に false を代入
	m_isEnd = false;

	// 画像データの読み込み
	m_handle = LoadGraph("imagedata/VVVVVV_logo.png");
	GetGraphSize(m_handle, &m_width, &m_height);
}

// 終了処理
void SceneTitle::end()
{
	// 画像データ削除
	DeleteGraph(m_handle);
}

// 更新処理
void SceneTitle::update()
{	
	// 文字の移動
	m_TextPosY += m_TextVecY;
	
	// 画面端に行った場合、移動方向を逆に変更
	if (m_TextPosY < 0)
	{
		m_TextPosY = 0;
		m_TextVecY *= -1;
	}
	if (m_TextPosY > Game::kScreenHeight - m_height)
	{
		m_TextPosY = Game::kScreenHeight - m_height;
		m_TextVecY *= -1;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	// キー入力があった場合、シーン終了を true にする
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

// 描画処理
void SceneTitle::draw()
{
	// 背景画像を読み込んで表示
	LoadGraphScreen(0, 0, Game::kBackgroundGraph, true);
	
	// ゲームタイトルの画像表示
	DrawGraph(0, m_TextPosY, m_handle, true);
	DrawGraph(Game::kScreenWidth - m_width, m_TextPosY, m_handle, true);

	DrawRotaGraphF(Game::kScreenWidth / 2, Game::kScreenHeight / 3, 1.5, 0, m_handle, true, false);

	// フォントサイズの設定
	SetFontSize(30);
	// タイトルのテキストを表示
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kTitleMessage, 12), Game::kScreenHeight / 2, kTitleMessage, GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameStart, 4), Game::kScreenHeight / 2 + 30, kGameStart, GetColor(255, 255, 255));
}