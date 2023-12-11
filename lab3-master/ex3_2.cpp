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

    auto future1 = std::async(calculate_sum, vector.begin(), middle);
    auto future2 = std::async(calculate_sum, middle, vector.end());

    int result1 = future1.get();
    int result2 = future2.get();
    int totalSum = result1 + result2;

    std::cout << "Vector sum: " << totalSum << std::endl;

    return 0;
}

int calculate_sum(std::vector<int>::iterator begin, std::vector<int>::iterator end) 
{
    return std::accumulate(begin, end, 0);
}