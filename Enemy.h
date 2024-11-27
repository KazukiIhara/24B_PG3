#pragma once

class Enemy {
public:
	enum class Phase {
		Approach,
		Attack,
		Leave,
	};
public:
	Enemy() = default;
	~Enemy() = default;

	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 接近
	void Approach();
	// 攻撃
	void Attack();
	// 離脱
	void Leave();
private:
	// メンバ関数ポインタテーブル
	static void (Enemy::* functionTable[])();
private:
	// 状態
	Phase phase_ = Phase::Approach;

};