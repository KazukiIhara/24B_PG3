#include <list>
#include <iostream>
#include <cstring> 

int main() {

	// 駅を追加
	std::list<const char*> yamanoteStations;
	yamanoteStations.push_back("Tokyo");
	yamanoteStations.push_back("Kanda");
	yamanoteStations.push_back("Akihabara");
	yamanoteStations.push_back("Okachimachi");
	yamanoteStations.push_back("Uneno");
	yamanoteStations.push_back("Ugisudani");
	yamanoteStations.push_back("Nippori");
	yamanoteStations.push_back("Tabata");
	yamanoteStations.push_back("Komagome");
	yamanoteStations.push_back("Sugamo");
	yamanoteStations.push_back("Otsuka");
	yamanoteStations.push_back("Ikebukuro");
	yamanoteStations.push_back("Mejiro");
	yamanoteStations.push_back("Takadanobaba");
	yamanoteStations.push_back("Shin-Okubo");
	yamanoteStations.push_back("Shinjuku");
	yamanoteStations.push_back("Yoyogi");
	yamanoteStations.push_back("Harajuku");
	yamanoteStations.push_back("Shibuya");
	yamanoteStations.push_back("Ebisu");
	yamanoteStations.push_back("Meguro");
	yamanoteStations.push_back("Gotanda");
	yamanoteStations.push_back("Osaki");
	yamanoteStations.push_back("Shinagawa");
	yamanoteStations.push_back("Tamachi");
	yamanoteStations.push_back("Hamamatsucho");
	yamanoteStations.push_back("Shimbashi");
	yamanoteStations.push_back("Yurakucho");

	// 1970年の山手線の各駅を出力する
	std::cout << "1970" << std::endl;
	for (const auto& station : yamanoteStations) {
		std::cout << station << std::endl;
	}

	// 西日暮里駅を挿入
	{
		auto it = yamanoteStations.begin();
		for (; it != yamanoteStations.end(); ++it) {
			if (strcmp(*it, "Nippori") == 0) {
				++it; // "Nippori"の次の位置に移動
				yamanoteStations.insert(it, "Nishi-Nippori");
				break;
			}
		}
	}

	// 2019年の山手線の各駅を出力する
	std::cout << "2019" << std::endl;
	for (const auto& station : yamanoteStations) {
		std::cout << station << std::endl;
	}

	// 高輪ゲートウェイ駅を挿入
	{
		auto it = yamanoteStations.begin();
		for (; it != yamanoteStations.end(); ++it) {
			if (strcmp(*it, "Tamachi") == 0) {
				++it; // "Tamachi"の次の位置に移動
				yamanoteStations.insert(it, "Takanawa Gateway");
				break;
			}
		}
	}

	// 2022年の山手線の各駅を出力する
	std::cout << "2022" << std::endl;
	for (const auto& station : yamanoteStations) {
		std::cout << station << std::endl;
	}

	// 終了
	return 0;
}