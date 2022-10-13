#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	constexpr int kSpawnInterval = 60;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hPlayerDeadGraphic = -1;
	m_hEnemyGraphic = -1;

	m_waitFrame = 0;
	m_randNum = 0;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
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
	m_waitFrame--;

	if (!m_waitFrame)
	{
		createEnemyLeft();
		createEnemyRight();

		m_waitFrame = kSpawnInterval;
	}

	m_player.update();

	isHitCheck();

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
}

bool SceneMain::isHitCheck()
{
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		//m_player.isDead();
	}

	for (auto& EnemyRight : m_EnemyRight)
	{
		EnemyRight.draw();
	}

	return false;
}

void SceneMain::createEnemyRight()
{
	for (auto& EnemyRight : m_EnemyRight)
	{
		if (EnemyRight.isExist())continue;

		EnemyRight.start(EnemyRight.getRandPos());
		return;
	}
}

void SceneMain::createEnemyLeft()
{
	for (auto& EnemyLeft : m_EnemyLeft)
	{
		if (EnemyLeft.isExist())continue;

		EnemyLeft.start(EnemyLeft.getRandPos());
		return;
	}
}