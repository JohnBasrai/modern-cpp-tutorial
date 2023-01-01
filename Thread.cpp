#include <iostream>
#include <thread>

struct Widget
{
    void hello() { std::cout << "Widget::Hello\n"; }
    void run() { std::cout << "Widget::run\n"; }

    // Thread on a member function
    Widget() : _thread( [this]{ run(); } )
    {}
    std::thread _thread;
    ~Widget() { _thread.join(); }
};

void global_hello() { std::cout << "::Hello\n"; }

int main()
{
    Widget widget;

    // Thread on a Lambda
    std::thread thr1( [&widget](){ widget.hello(); } );

    // Thread on a free standing function
    std::thread thr2(::global_hello);
    thr2.join();
    thr1.join();
}


