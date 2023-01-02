#ifndef Refcountable_hh
#define Refcountable_hh

#if __cplusplus < 201103L
# error "Older versions of C++ not supported."
#endif

#include <atomic>
#include <boost/assert.hpp>

namespace util
{
    using atomic_type = std::atomic_int64_t;

    static inline int64_t AtomicAdd(atomic_type* counter, const int32_t toAdd)
    {
        const auto oldValue = counter->fetch_add(toAdd, std::memory_order_relaxed);
        return oldValue + toAdd; // Returns new value (after adding value).
    }
}
namespace util
{
    class Refcountable
    {
    protected:
        virtual ~Refcountable(){};
        virtual void deleteNotify() {}
    public:
        void _addRef_() { AtomicAdd(&theRefcount, 1); }
        void _decRef_()
        {
            if ( AtomicAdd(&theRefcount,  -1) == 0 )
            {
                deleteNotify();
                theRefcount = -1;
                delete this;
            }
        }
        int refcount() const
        {
            return theRefcount.load(std::memory_order_relaxed);
        }

    protected:
        Refcountable() : theRefcount(0) {}

    private:
        atomic_type theRefcount;

        Refcountable& operator=(const Refcountable&rhs);
        Refcountable(Refcountable&);
    };
}

#ifdef _inc_intrusive_ptr_add_ref_macro

// Scaffolding required for boost/intrusive_ptr.hpp
// Should be a template in a namespace but these macros can be used in a pinch
//
# define intrusive_ptr_add_ref(_ptr) do { _ptr->_addRef_(); } while(false)
# define intrusive_ptr_release(_ptr) do { _ptr->_decRef_(); } while(false)
#endif /* _inc_intrusive_ptr_add_ref_macro */

#endif  // Refcountable_hh
