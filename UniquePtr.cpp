#include <memory>
struct B {
    virtual ~B() = default;
    virtual void fun(){};
};
struct D : public B {
    void fun() override{};
};
int main() {
    auto aPtr = std::make_unique<D>();

    // Type is of base class (polymorphic)
    //std::unique_ptr<B> bPtr = new D(); // fails to compile
    // error: conversion from ‘D*’ to non-scalar type ‘std::unique_ptr<B>’ requested

    const auto bPtr = std::unique_ptr<B>(new D());
    bPtr->fun(); // invokes D::fun
    aPtr->fun(); // invokes D::fun

    // Correct way to "reset" a pointer
    aPtr.reset(new D());
    aPtr.reset(nullptr);

    //bPtr = nullptr;
    // error: no match for ‘operator=’ (operand types are ‘const
    // std::unique_ptr<B>’ and ‘std::nullptr_t’)
    // bPtr = 0;
    // error: no match for ‘operator=’ (operand types are ‘const
    // std::unique_ptr<B>’ and ‘int’)

    // Access native pointer (use with caution).
    bPtr.get();
}

