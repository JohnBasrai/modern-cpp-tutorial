#include <iostream>
#include <thread>

struct Widget
{
    void hello() { std::cout << "Widget::Hello\n"; }
    void run() { std::cout << "Widget::run\n"; }

    // Thread on a member function
    Widget() : thr1( [this]{ run(); } ) {}
    std::thread thr1;
    ~Widget() { thr1.join(); }
};

void global_hello() { std::cout << "::Hello\n"; }

int main()
{
    Widget widget;

    // Thread on a Lambda
    std::thread thr2( [&widget](){ widget.hello(); } );

    // Thread on a free standing function
    std::thread thr3(::global_hello);

    thr2.join();
    thr3.join();
}

