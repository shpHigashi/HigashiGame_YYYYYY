#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// 敵出現用の遅延時間
	constexpr int kSpawnDelay = 90;
	// ゲームの制限時間
	constexpr int kGameMaxTime = 18000;	
	// 死亡時の遅延
	constexpr int kGameOverDelay = 90;
	// ゲームオーバー
	const char* const kGameOver = "GameOver";
	constexpr int kFontSize = 60;

	// 制限時間表示位置
	constexpr int kTimerPositionX = Game::kScreenWidthHalf - 30;
	constexpr int kTimerPositionY = Game::kStageLowerLimit + 25;
}

SceneMain::SceneMain()
{
	m_hBackgroundGraphic = -1;
	m_hPlayerGraphic = -1;
	m_hPlayerDeadGraphic = -1;
	m_hEnemyGraphic = -1;

	m_spawnDelay = 0;
	m_fontSize = 0;

	m_gameTimeRemaining = kGameMaxTime;
	m_GameOverDelay = kGameOverDelay;

	m_isGameClear = false;
	m_isEnd = false; 
}
SceneMain::~SceneMain()
{
}

// 初期化
void SceneMain::init()
{
	// 画像データの読み込み
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	m_hPlayerGraphic = LoadGraph(Game::kPlayerGraph);
	m_hPlayerDeadGraphic = LoadGraph("imagedata/playerDead.png");
	m_hEnemyGraphic = LoadGraph("imagedata/enemy.png");

	// プレイヤー画像の設定
	m_player.setHandle(m_hPlayerGraphic, m_hPlayerDeadGraphic);

	// 敵の画像設定、初期化
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		EnemyLeft.setHandle(m_hEnemyGraphic);
		EnemyLeft.init();
	}
	for (auto& EnemyRight : m_EnemyRight)
	{
		EnemyRight.setHandle(m_hEnemyGraphic);
		EnemyRight.init();
	}

	// プレイヤーの初期位置設定
	m_player.setPos(Game::kScreenWidthHalf, Game::kScreenHeightHalf);
	// プレイヤー初期化 
	m_player.init();

	// フォントサイズ設定
	m_fontSize = kFontSize;

	// 各時間用変数の初期化
	m_spawnDelay = kSpawnDelay;
	m_gameTimeRemaining = kGameMaxTime;
	m_GameOverDelay = kGameOverDelay;

	// シーン終了を偽に初期化
	m_isEnd = false;
}

// 終了処理
void SceneMain::end()
{
	// 画像データの削除
	DeleteGraph(m_hBackgroundGraphic);
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hPlayerDeadGraphic);
	DeleteGraph(m_hEnemyGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	// 背景の表示
	DrawGraph(0, 0, m_hBackgroundGraphic, true);
	
	if (!m_gameTimeRemaining)	// ゲーム残り時間が0になった場合
	{
		m_isGameClear = true;	// ゲームクリアとシーン終了を true にする
		m_isEnd = true;			// クリア用のシーンへ移行する
	}
	else if (!m_GameOverDelay)	// ゲームオーバー遅延が0になった場合
	{
		m_isEnd = true;			// シーン終了のみを true にする			
	}							// タイトルへ戻る

	// プレイヤーの死亡判定が true の場合
	if (m_player.isDead())
	{
		// ゲームオーバー遅延を1フレームごとに減少させる
		m_GameOverDelay--;

		return;
	}

	// 1フレームごとに残り時間と敵の出現遅延を減少させる
	m_gameTimeRemaining--;
	m_spawnDelay--;

	// 出現遅延が0になった場合、敵を出現させる
	if (!m_spawnDelay)
	{
		// それぞれの方向の敵を作成
		createEnemyLeft();
		createEnemyRight();

		// 出現遅延に再び定数を代入
		m_spawnDelay = kSpawnDelay;
	}

	// プレイヤーの更新処理
	m_player.update();

	// 当たり判定チェック処理
	//checkCollision();

	// 敵の更新処理
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		EnemyLeft.update();
	}
	for (auto& EnemyRight : m_EnemyRight)
	{
		EnemyRight.update();
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	// プレイヤーの描画
	m_player.draw();

	// 存在している敵のみ描画
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		if (EnemyLeft.isExist()) EnemyLeft.draw();
	}
	for (auto& EnemyRight : m_EnemyRight)
	{
		if (EnemyRight.isExist()) EnemyRight.draw();
	}

	// ステージの線の表示
	DrawLine(0, Game::kStageUpperLimit, Game::kScreenWidth, Game::kStageUpperLimit, GetColor(255, 255, 255));
	DrawLine(0, Game::kStageLowerLimit, Game::kScreenWidth, Game::kStageLowerLimit, GetColor(255, 255, 255));

	// フォントサイズ設定
	SetFontSize(Game::kFontSize);
	// ゲームの制限時間表示 (通常は白文字、合計時間の半分を過ぎると黄色文字、5秒を過ぎると赤文字で表示される)
	if (m_gameTimeRemaining <= kGameMaxTime / 4) DrawFormatString(kTimerPositionX, kTimerPositionY, GetColor(255, 0, 0), "%d", m_gameTimeRemaining / 60);
	else if (m_gameTimeRemaining <= kGameMaxTime / 2) DrawFormatString(kTimerPositionX, kTimerPositionY, GetColor(255, 216, 0), "%d", m_gameTimeRemaining / 60);
	else DrawFormatString(kTimerPositionX, kTimerPositionY, GetColor(255, 255, 255), "%d", m_gameTimeRemaining / 60);

	// プレイヤーの死亡判定が true の場合
	if (m_player.isDead())
	{
		// 1フレームごとにフォントサイズを増加させる
		m_fontSize++;
		SetFontSize(m_fontSize);
		// ゲームオーバーのテキストを表示
		DrawString(Game::kScreenWidthHalf - GetDrawStringWidth(kGameOver, 4), 210, kGameOver, GetColor(255, 0, 0));
	}
}

// 当たり判定チェック処理
void SceneMain::checkCollision()
{
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		// 当たっていない場合処理をスキップ
		if (EnemyLeft.getRight() <= m_player.getLeft()) continue;
		if (m_player.getRight() <= EnemyLeft.getLeft()) continue;
		if (EnemyLeft.getBottom() <= m_player.getTop()) continue;
		if (m_player.getBottom() <= EnemyLeft.getTop()) continue;
		// 当たっている場合プレイヤーを死亡判定にする
		m_player.setDead();
	}
	for (auto& EnemyRight : m_EnemyRight)
	{
		// 当たっていない場合処理をスキップ
		if (EnemyRight.getRight() <= m_player.getLeft()) continue;
		if (m_player.getRight() <= EnemyRight.getLeft()) continue;
		if (EnemyRight.getBottom() <= m_player.getTop()) continue;
		if (m_player.getBottom() <= EnemyRight.getTop()) continue;
		// 当たっている場合プレイヤーを死亡判定にする
		m_player.setDead();
	}
}

// 敵の生成(左から出現)
void SceneMain::createEnemyLeft()
{
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		// 敵が存在している場合スキップ
		if (EnemyLeft.isExist()) continue;

		// 敵の出現処理 引数としてランダムで生成した座標を持つ
		EnemyLeft.start(EnemyLeft.getRandPos());
		
		return;
	}
}
// 敵の生成(右から出現)
void SceneMain::createEnemyRight()
{
	for (auto& EnemyRight : m_EnemyRight)
	{
		// 敵が存在している場合スキップ
		if (EnemyRight.isExist()) continue;

		// 敵の出現処理 引数としてランダムで生成した座標を持つ
		EnemyRight.start(EnemyRight.getRandPos());

		return;
	}
}