#pragma once

#include "player.h"
#include "EnemyRight.h"
#include "EnemyLeft.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();

	void HitCheck();

	// 敵の生成
	void createEnemyRight();
	void createEnemyLeft();

private:
	static constexpr int kMobMax = 10;

private:

	// キャラクターのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;
	int m_hEnemyGraphic;

	int m_waitFrame;
	int m_randNum;

	// プレイヤー
	Player m_player;

	// 敵
	EnemyRight m_EnemyRight[kMobMax];
	EnemyLeft m_EnemyLeft[kMobMax];
};