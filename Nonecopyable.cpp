
namespace util
{
    class Noncopyable
    {
    public:
        virtual ~Noncopyable(){}
        Noncopyable(){}

    protected:
        Noncopyable& operator=(const Noncopyable&) = delete;
        Noncopyable& operator=(Noncopyable&)       = delete;
        Noncopyable(Noncopyable&)                  = delete;
        Noncopyable(const Noncopyable&)            = delete;
        Noncopyable(Noncopyable&&)                 = delete;
        Noncopyable& operator=(Noncopyable&&)      = delete;
    };
}


int main(){return 0;}
