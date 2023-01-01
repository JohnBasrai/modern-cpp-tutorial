#include "Refcountable.hh"
#include <iostream>
#include <boost/intrusive_ptr.hpp>

namespace acme
{
    class Widget : public util::Refcountable
    {
    public:
        void hello(){std::cout << "Hello\n"; }
    private:
        virtual ~Widget(){std::cout << "Widget::~Widget" << std::endl;};
        virtual void deleteNotify(){std::cout << "Widget::deleteNotify" << std::endl;}
    };
    using WidgetPtr = boost::intrusive_ptr<Widget>;

    // Required for boost::intrusive_ptr
    template<typename T> void intrusive_ptr_add_ref(T *p) {p->_addRef_();}
    template<typename T> void intrusive_ptr_release(T *p) {p->_decRef_();}
}

int main()
{
    const acme::WidgetPtr ptr = new acme::Widget();
    ptr->hello();
    return 0;
}


const auto ptr = acme::WidgetPtr(new acme::Widget());
