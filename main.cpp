#include <iostream>
#include <string>
#include <chrono>

int main() {
    // 100,000文字の'a'で初期化されたstd::string
    std::string original(100000, 'a');

    // コピーの時間計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string copy = original; // コピー操作
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_time = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // 移動の時間計測 (std::moveを使用)
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string moved = std::move(original); // 移動操作
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_time = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 結果を表示
    std::cout << "100,000文字を移動とコピーで比較しました。" << std::endl;
    std::cout << "コピーにかかった時間: " << copy_time << " μs\n";
    std::cout << "移動にかかった時間: " << move_time << " μs\n";

    return 0;
}
