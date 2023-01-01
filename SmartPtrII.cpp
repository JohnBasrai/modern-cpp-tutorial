#include <memory>
struct B : public std::enable_shared_from_this<B>
{
    virtual ~B() = default;
    virtual  std::shared_ptr<B> clone() = 0;
};
struct D : public B
{
    virtual std::shared_ptr<B> clone() override
    {
        return this->shared_from_this();
    }
};
int main() { auto bPtr = std::make_shared<D>(); }

