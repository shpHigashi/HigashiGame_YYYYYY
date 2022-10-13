#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// 敵出現用の遅延時間
	constexpr int kSpawnInterval = 80;
	// ゲームの制限時間
	constexpr int kGameMaxTimeFrame = 1800;
	constexpr int kGameOverDelay = 90;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hPlayerDeadGraphic = -1;
	m_hEnemyGraphic = -1;

	m_waitFrame = 0;
	m_randNum = 0;

	m_GameTimeRemaining = kGameMaxTimeFrame;
	m_GameOverDelay = kGameOverDelay;

	m_isGameEnd = false;
	m_isEnd = false;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hBackgroundGraphic = LoadGraph("imagedata/VVVVVVbackground.png");
	m_hPlayerGraphic = LoadGraph("imagedata/VVVVVV.png");
	m_hPlayerDeadGraphic = LoadGraph("imagedata/VVVVVVdead.png");
	m_hEnemyGraphic = LoadGraph("imagedata/enemy.png");

	m_player.setHandle(m_hPlayerGraphic, m_hPlayerDeadGraphic);

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

	m_player.setPos(Game::kScreenWidth / 2, Game::kScreenHeight / 2);
	m_player.init();

	m_waitFrame = kSpawnInterval;
	m_GameTimeRemaining = kGameMaxTimeFrame;
	m_GameOverDelay = kGameOverDelay;

	m_isEnd = false;
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hEnemyGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	// 背景の表示
	DrawGraph(0, 0, m_hBackgroundGraphic, true);
	
	if (!m_GameTimeRemaining)
	{
		m_isGameEnd = true;
		m_isEnd = true;
	}
	else if (!m_GameOverDelay)
	{
		m_isEnd = true;
	}

	if (m_player.getIsDead())
	{
		m_GameOverDelay--;
		return;
	}

	m_GameTimeRemaining--;
	m_waitFrame--;

	if (!m_waitFrame)
	{
		createEnemyLeft();
		createEnemyRight();

		m_waitFrame = kSpawnInterval;
	}

	m_player.update();

	HitCheck();

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
	m_player.draw();

	for (auto& EnemyLeft : m_EnemyLeft)
	{
		EnemyLeft.draw();
	}
	for (auto& EnemyRight : m_EnemyRight)
	{
		EnemyRight.draw();
	}

	// 線の表示
	DrawLine(0, Game::kStageUpperLimit, Game::kScreenWidth, Game::kStageUpperLimit, GetColor(255, 255, 255));
	DrawLine(0, Game::kStageLowerLimit, Game::kScreenWidth, Game::kStageLowerLimit, GetColor(255, 255, 255));

	// 制限時間の表示
	SetFontSize(60);
	DrawFormatString(Game::kScreenWidth / 2 - 30, Game::kStageLowerLimit + 25, GetColor(255, 255, 255), "%d", m_GameTimeRemaining / 60);
}

void SceneMain::HitCheck()
{
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		if (EnemyLeft.getRight() < m_player.getLeft()) continue;
		if (m_player.getRight() < EnemyLeft.getLeft()) continue;
		if (EnemyLeft.getBottom() < m_player.getTop()) continue;
		if (m_player.getBottom() < EnemyLeft.getTop()) continue;
		m_player.isDead();
	}

	for (auto& EnemyRight : m_EnemyRight)
	{
		if (EnemyRight.getRight() < m_player.getLeft()) continue;
		if (m_player.getRight() < EnemyRight.getLeft()) continue;
		if (EnemyRight.getBottom() < m_player.getTop()) continue;
		if (m_player.getBottom() < EnemyRight.getTop()) continue;
		m_player.isDead();
	}
}

void SceneMain::createEnemyRight()
{
	for (auto& EnemyRight : m_EnemyRight)
	{
		if (EnemyRight.isExist()) continue;

		EnemyRight.start(EnemyRight.getRandPos());
		return;
	}
}

void SceneMain::createEnemyLeft()
{
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		if (EnemyLeft.isExist()) continue;

		EnemyLeft.start(EnemyLeft.getRandPos());
		return;
	}
}