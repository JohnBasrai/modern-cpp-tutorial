
#include <future>
#include <functional>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>

template<typename F> auto async(F && func) -> std::future<decltype(func())>
{
    using result_type = decltype(func());

    auto promise = std::promise<result_type>();
    auto future  = promise.get_future();

    std::thread( std::bind( [=](std::promise<result_type>& promise )
    {
        try
        {
            promise.set_value(func());
        }
        catch(...)
        {
            promise.set_exception(std::current_exception());
        }
    }, std::move(promise))).detach();

    return std::move(future);
}
int main()
{
    auto work_task =
        []()
        {
            /*working...*/ sleep(2); return std::string("Final Answer");
        };
    auto resp = async(work_task);
    std::cout << resp.get() << std::endl;
}

 // Note: Will not work with std::promise<void>. Needs some
 // meta-template programming which is out of scope for this question.

