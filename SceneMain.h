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

	virtual bool isGameStop() { return m_isGameStop; }
	virtual bool isEnd() { return m_isEnd; }

private:
	static constexpr int kMobMax = 10;

private:

	// キャラクターのグラフィックハンドル
	int m_hBackgroundGraphic;
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;
	int m_hEnemyGraphic;

	// ゲームの制限時間
	int m_GameTimeRemaining;
	int m_GameOverDelay;
	// 
	int m_waitFrame;

	// 乱数取得用変数
	int m_randNum;

	// ゲーム終了
	bool m_isGameStop;
	bool m_isEnd;

	// プレイヤー
	Player m_player;

	// 敵
	EnemyRight m_EnemyRight[kMobMax];
	EnemyLeft m_EnemyLeft[kMobMax];
};