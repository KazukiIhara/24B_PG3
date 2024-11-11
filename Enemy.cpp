#include "Enemy.h"

#include <cstdint>
#include <stdio.h>

void Enemy::Initialize() {
	phase_ = Phase::Approach;
}

void Enemy::Update() {
	for (uint32_t i = 0; i < 3; i++) {
		// メンバ関数ポインタ内の関数を呼び出す
		(this->*functionTable[static_cast<size_t>(phase_)])();
		phase_ = static_cast<Phase>(static_cast<size_t>(phase_) + 1);
	}
}

void Enemy::Approach() {
	printf("approach\n");
}

void Enemy::Attack() {
	printf("Attack\n");
}

void Enemy::Leave() {
	printf("Leave\n");
}

void(Enemy::* Enemy::functionTable[])() = {
	&Enemy::Approach,
	&Enemy::Attack,
	&Enemy::Leave,
};