#include <iostream>
using namespace std;
class A
{
public: 
    explicit A(int)
    {
        cout << "A::A(int)\n";
    }
};

class B: public A
{
    using A::A;
};

int main()
{
    B b1(1);
} 

