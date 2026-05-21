#include <iostream>
#include <vector>
#include <thread>

void call_from(int tid) {
    std::cout << "Launch by thread" << tid << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(call_from, i);
    }

    std::cout << "Launched from main" << std::endl;

    for(int i =0;i<10;i++){
        threads[i].join();
    }

    return 0;
}