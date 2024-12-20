#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// グローバルなミューテックスと条件変数
std::mutex mtx;
std::condition_variable cv;

// 出力する順番を制御するためのカウンタ
int current = 1;

// スレッドの関数
void threadFunc(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    // 自分の順番になるまで待機
    cv.wait(lock, [&]() { return current == id; });

    // 出力
    std::cout << "thread " << id << std::endl;

    // 次のスレッドに進める
    current++;
    cv.notify_all();
}

int main() {
    // スレッドの作成（並列に実行開始）
    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);
    std::thread t3(threadFunc, 3);

    // スレッドの終了を待つ
    t1.join();
    t2.join();
    t3.join();

    return 0;
}