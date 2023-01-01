#include <memory>
struct B {
    virtual ~B() = default;
    virtual  std::shared_ptr<B> clone() = 0;
};
struct D : public B {
    virtual std::shared_ptr<B> clone() override
    {
        return std::shared_ptr<B>(this);
    }
};
using namespace std;
void proc()
{
    auto bPtr = make_shared<D>(); // new D here
    const auto anotherBPtr = bPtr->clone();
}
int main(){proc();}

