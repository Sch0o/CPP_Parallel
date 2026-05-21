#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;

void call_from(int tid) {
    mtx.lock();
    std::cout << "Launch by thread" << tid << std::endl;
    mtx.unlock();
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(call_from, i);
    }

    mtx.lock();
    std::cout << "Launched from main" << std::endl;
    mtx.unlock();
    for (int i = 0; i < 10; i++) {
        threads[i].join();
    }

    return 0;
}