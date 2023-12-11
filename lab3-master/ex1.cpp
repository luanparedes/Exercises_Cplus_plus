#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<unsigned> number;

void PrintThread();

int main()
{
    number.store(0);

    std::vector<std::thread> listThreads;

    for(int i = 0; i < 100; ++i){
        listThreads.emplace_back([&]() {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            number.fetch_add(1);
        });
    }

    for(auto& t : listThreads)
    {
        t.join();
    }

    PrintThread();
}

void PrintThread()
{
    std::cout << "Threads: " << std::this_thread::get_id() << "  |  Counter: " << number << std::endl;
}