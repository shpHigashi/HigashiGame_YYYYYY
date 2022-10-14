#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// “GoŒ»—p‚Ì’x‰„ŽžŠÔ
	constexpr int kSpawnInterval = 80;
	// ƒQ[ƒ€‚Ì§ŒÀŽžŠÔ
	constexpr int kGameMaxTimeFrame = 1800;
	// Ž€–SŽž‚Ì’x‰„
	constexpr int kGameOverDelay = 90;
	// ƒQ[ƒ€ƒI[ƒo[
	const char* const kGameOver = "Game Over";
	constexpr int kFontSize = 60;
}

SceneMain::SceneMain()
{
	m_hBackgroundGraphic = -1;
	m_hPlayerGraphic = -1;
	m_hPlayerDeadGraphic = -1;
	m_hEnemyGraphic = -1;

	m_waitFrame = 0;
	m_randNum = 0;
	m_fontSize = 0;

	m_GameTimeRemaining = kGameMaxTimeFrame;
	m_GameOverDelay = kGameOverDelay;

	m_isGameStop = false;
	m_isEnd = false;
}
SceneMain::~SceneMain()
{

}

// ‰Šú‰»
void SceneMain::init()
{
	m_hBackgroundGraphic = LoadGraph("imagedata/VVVVVVbackground.png");
	m_hPlayerGraphic = LoadGraph("imagedata/player.png");
	m_hPlayerDeadGraphic = LoadGraph("imagedata/playerDead.png");
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

	m_fontSize = kFontSize;

	m_waitFrame = kSpawnInterval;
	m_GameTimeRemaining = kGameMaxTimeFrame;
	m_GameOverDelay = kGameOverDelay;

	m_isEnd = false;
}

// I—¹ˆ—
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hEnemyGraphic);
}

// –ˆƒtƒŒ[ƒ€‚Ìˆ—
void SceneMain::update()
{
	// ”wŒi‚Ì•\Ž¦
	DrawGraph(0, 0, m_hBackgroundGraphic, true);
	
	if (!m_GameTimeRemaining)
	{
		m_isGameStop = true;
		m_isEnd = true;
	}
	else if (!m_GameOverDelay)
	{
		m_isEnd = true;
	}

	if (m_player.getIsDead())
	{
		m_fontSize++;
		SetFontSize(m_fontSize);
		DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameOver, 4), 210, kGameOver, GetColor(255, 0, 0));
		
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

// –ˆƒtƒŒ[ƒ€‚Ì•`‰æ
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

	// ü‚Ì•\Ž¦
	DrawLine(0, Game::kStageUpperLimit, Game::kScreenWidth, Game::kStageUpperLimit, GetColor(255, 255, 255));
	DrawLine(0, Game::kStageLowerLimit, Game::kScreenWidth, Game::kStageLowerLimit, GetColor(255, 255, 255));

	// §ŒÀŽžŠÔ‚Ì•\Ž¦
	SetFontSize(Game::kFontSize);
	
	if (m_GameTimeRemaining >= 600) DrawFormatString(Game::kScreenWidth / 2 - 30, Game::kStageLowerLimit + 25, GetColor(255, 255, 255), "%d", m_GameTimeRemaining / 60);
	else if (m_GameTimeRemaining >= 300) DrawFormatString(Game::kScreenWidth / 2 - 30, Game::kStageLowerLimit + 25, GetColor(255, 216, 0), "%d", m_GameTimeRemaining / 60);
	else DrawFormatString(Game::kScreenWidth / 2 - 30, Game::kStageLowerLimit + 25, GetColor(255, 0, 0), "%d", m_GameTimeRemaining / 60);
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