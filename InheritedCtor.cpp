
#include <iostream>
#include <stdlib.h>             // strtol
using namespace std;
class A
{
public: 
    explicit A(int x)
    {
        cout << "A::A(int):" << x << "\n";
    }
};

class B: public A
{
public:
    using A::A;
    B(const char * s)
        : A(strtol(s,0,0))
    {}
};

int main()
{
    B b1(1);      // A::A(int)
    B b2("2");    // B::B(const char*)
} 


