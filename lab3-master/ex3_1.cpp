#include <iostream>
#include <vector>
#include <numeric>
#include <future>
#include <random>

int calculate_sum(std::vector<int>::iterator begin, std::vector<int>::iterator end);

int main() {
    const int vectorSize = 100;
    std::vector<int> vector(vectorSize);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < vectorSize; ++i) {
        vector[i] = dis(gen);
    }

    auto middle = vector.begin() + vectorSize / 2;

    std::packaged_task<int(std::vector<int>::iterator, std::vector<int>::iterator)> task1(calculate_sum);
    std::packaged_task<int(std::vector<int>::iterator, std::vector<int>::iterator)> task2(calculate_sum);

    auto future1 = task1.get_future();
    auto future2 = task2.get_future();

    std::thread thread1(std::move(task1), vector.begin(), middle);
    std::thread thread2(std::move(task2), middle, vector.end());

    thread1.join();
    thread2.join();

    int result1 = future1.get();
    int result2 = future2.get();
    int totalSum = result1 + result2;

    std::cout << "Vector sum: " << totalSum << std::endl;

    return 0;
}

int calculate_sum(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    return std::accumulate(begin, end, 0);
}