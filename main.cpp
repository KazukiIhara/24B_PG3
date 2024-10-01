#include <stdio.h>
#include <iostream>
#include <ctime>
#include <thread>
#include <functional>
#include <random>

typedef void (*PFunc)(bool);

int RollDice(std::mt19937& gen) {
	std::uniform_int_distribution<> dist(1, 6);
	return dist(gen);
}

void SetTimeout(PFunc p, int second, bool result) {
	std::cout << "判定中";
	for (size_t i = 0; i < second; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << ".";
	}
	std::cout << std::endl;
	p(result);
}

bool CheckResult(int dice, int input) {
	switch (input) {
	case 0:
		if (dice % 2) {
			return true;
		} else {
			return false;
		}
		break;
	case 1:
		if (dice % 2) {
			return false;
		} else {
			return true;
		}
		break;
	default:
		std::cout << "0か1を入力してください" << std::endl;
		return false;
		break;
	}
}

void DispResult(bool result) {
	if (result) {
		std::cout << "正解！";
	} else {
		std::cout << "残念...";
	}
}

int main() {

	std::random_device rd;
	std::mt19937 gen(rd());

	int dice = RollDice(gen);

	std::cout << dice << std::endl;
	std::cout << "ダイスが振られました" << std::endl << "奇数(0)か偶数(1)かを当ててください" << std::endl;
	std::cout << "入力: ";
	int input;
	std::cin >> input;

	PFunc p;
	p = DispResult;

	SetTimeout(p, 3, CheckResult(dice, input));

	return 0;
}