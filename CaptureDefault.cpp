
struct S2 { void f(int i); int memb = 20; };

void S2::f(int i)
{
    auto a = 20;

    auto b = 30;

    [=](int){ return memb == a; }; // Capture a and this (by const value)

//  [=](int){ a = b; };     // Capture a and b (by const value)
                            // error: assignment of read-only variable ‘a’

    [&](){a = b; memb=0;};  // Capture a and b (by ref), and this (by const value)

//  [&,a](){b = a; a++;};   // Capture b by ref, a by value
                            // error: increment of read-only variable ‘a’

    [i, i] {};              // warning: already captured ‘i’ in lambda expression
}

int main(){return 0;}
