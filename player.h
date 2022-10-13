#pragma once
#include "Vec2.h"

class Player
{
public:
	Player();
	virtual ~Player() {}

	virtual void init();
	virtual void setHandle(int playerHandle, int playerDeadHandle);
	virtual void setPos(float x, float y);

	virtual void update();
	virtual void draw();

	virtual float getCenterX(){ return m_pos.x + (m_height / 2); }
	virtual float getCenterY(){ return m_pos.y + (m_height / 2); }
	
	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	virtual void isDead() { m_isDead = true; }
	virtual bool getIsDead() { return m_isDead; }

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }
	
	Vec2 getPos() const { return m_pos; }

private:
	// 画像データ
	int m_aliveHandle;
	int m_deadHandle;

	// 画像サイズ
	int m_height;
	int m_width;

	// 表示位置
	Vec2 m_pos;

	// 中心位置
	Vec2 m_midPos;

	// 移動量
	Vec2 m_vec;

	// 画像反転判定
	bool m_isReverseSide;
	bool m_isReverseLength;

	// 死亡判定
	bool m_isDead;
};