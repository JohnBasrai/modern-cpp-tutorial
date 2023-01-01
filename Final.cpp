struct Base
{
    virtual void foo();
};
 
struct A : Base
{
    void foo() final; // Base::foo is overridden and A::foo is the final override
//  void bar() final; // Error: non-virtual function cannot be overridden or be final
};
 
struct B final : A    // struct B is final
{
//  void foo() override; // Error: foo cannot be overridden as it's final in A
};

 
//struct C : B{}; // error: cannot derive from ‘final’ base ‘B’ in derived type ‘C’

int main(){return 0;}
