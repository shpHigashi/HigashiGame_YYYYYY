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

	void gameEnd();

	void HitCheck();

	// 敵の生成
	void createEnemyRight();
	void createEnemyLeft();

private:
	static constexpr int kMobMax = 5;

private:

	// キャラクターのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;
	int m_hEnemyGraphic;

	// ゲームの制限時間
	int m_GameTimeRemaining;
	// 
	int m_waitFrame;

	// 乱数取得用変数
	int m_randNum;

	// ゲーム終了
	bool isGameEnd;

	// プレイヤー
	Player m_player;

	// 敵
	EnemyRight m_EnemyRight[kMobMax];
	EnemyLeft m_EnemyLeft[kMobMax];
};