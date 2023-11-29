#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <random>

std::atomic<unsigned> number;

void PrintThread(int number);
void PrintFinalNumber();

int main()
{
  	std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 5000);

    number.store(0);

    std::vector<std::thread> listThreads;

    for(int i = 0; i < 100; ++i){
        listThreads.emplace_back([&]() {
            std::this_thread::sleep_for(std::chrono::seconds(3));

            int randomNumber = distribution(generator);

            if(randomNumber > number)
                number = randomNumber;
            
            PrintThread(randomNumber);
        });
    }

    for(auto& t : listThreads)
    {
        t.join();
    }

    PrintFinalNumber();
}

void PrintThread(int value)
{
    std::cout << "Thread: " << std::this_thread::get_id() << "  |  Value: " << value << std::endl;
}

void PrintFinalNumber()
{
    std::cout << "\n\nVariavel atomica: " << number << std::endl;
}