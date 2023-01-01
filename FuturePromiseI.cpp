
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    auto promise = std::promise<std::string>();
    auto producer = std::thread([&] { promise.set_value("Hello World"); });
    auto future = promise.get_future();
    auto consumer = std::thread([&] { std::cout << future.get(); });

    producer.join();
    consumer.join();
    return 0;
}

