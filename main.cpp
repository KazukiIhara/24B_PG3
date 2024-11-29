#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    // ファイル名
    const std::string filename = "PG3_2024_03_02.txt";

    // ファイル読み込み用のストリーム
    std::ifstream inputFile(filename);

    // ファイルからデータを読み込む
    std::vector<std::string> data;
    std::string line;
    if (std::getline(inputFile, line)) {
        if (!line.empty() && line.front() == '[') {
            line.erase(0, 1); 
        }
        if (!line.empty() && line.back() == ']') {
            line.pop_back(); 
        }

        size_t start = 0;
        size_t end = line.find(',');

        // データをカンマ区切りで分割して格納
        while (end != std::string::npos) {
            data.push_back(line.substr(start, end - start));
            start = end + 1;
            end = line.find(',', start);
        }
        // 最後の要素を追加
        data.push_back(line.substr(start));
    }
    inputFile.close();

    // 昇順にソート
    std::sort(data.begin(), data.end());

    // 結果を出力
    std::cout << "学籍番号順にソート:" << std::endl;
    for (const auto& email : data) {
        std::cout << email << std::endl;
    }

    return 0;
}