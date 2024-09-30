#include <stdio.h>

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

int main() {

	printf("こんにちは\n");

	printf("%d\n", Min<int>(10, 5));
	printf("%f\n", Min<float>(9.0f, 12.0f));
	printf("%lf\n", Min<double>(77.7, 55.5));
	printf("%c\n", Min<char>(10, 5));

	return 0;
}