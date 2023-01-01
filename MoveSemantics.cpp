
#include <iostream>
#include <string>
using namespace std;
int proc();
int main()
{
    const auto a = string{"A"} ;
    const auto b = string{"B"} ;
    a + b = "Not to be seen";
    cout << a << b << endl;
    return proc();
}

string getName()
{
    return "Alex";
}

int proc()
{
    const string name = getName();
    cout << name << endl;
    return 0;
}
