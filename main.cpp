#include <stdio.h>
#include <iostream>

// 時給
const int kHourlyPay = 1072;

template <typename T>
T Min(T a, T b) {
	if (a < b) {
		return static_cast<T>(a);
	} else if (b < a) {
		return static_cast<T>(b);
	} else {
		printf("SameNumbers");
		return static_cast<T>(a);
	}
}

template <>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません");
	return a;
}

// 再帰的な賃金を計算する関数
int recursiveWage(int hour) {
	if (hour == 1) {
		return 100;
	} else {
		return recursiveWage(hour - 1) * 2 - 50;
	}
}

// 一般的な賃金体系と再帰的な賃金体系を比較する関数
void compareWages(int hours) {
	int generalWage = 1072 * hours;
	int recursiveTotalWage = 0;

	for (int hour = 1; hour <= hours; ++hour) {
		recursiveTotalWage += recursiveWage(hour);
	}
	std::cout << "勤務時間: " << hours << "時間" << std::endl;
	std::cout << "一般的な賃金体系での総賃金: " << generalWage << "円" << std::endl;
	std::cout << "再帰的な賃金体系での総賃金: " << recursiveTotalWage << "円" << std::endl;
}

int main() {
	int hours = 1;  // 例として8時間働く場合
	for (hours = 0; hours <= 8; hours++) {
		compareWages(hours);
	}

	return 0;
}