#pragma once
#include "Vec2.h"

class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase() {}

	virtual void init();
	virtual void setHandle(int handle);

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	virtual void start(Vec2 pos);
	virtual void update();
	virtual void draw();

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	//存在するか
	bool isExist()const { return m_isExist; }

protected:
	// 画像データ
	int m_handle;

	// 画像サイズ
	int m_height;
	int m_width;

	// 表示位置
	Vec2 m_pos;

	// 移動量
	Vec2 m_vec;

	//存在するか
	bool m_isExist;

	// 画像の角度
	float m_angle;
};