/*
 * v.cpp -- C++ documentation snippets.
 */

//! [v_property_example]
#include <fcntl.h>
#include <libpmemobj++/persistent_ptr.hpp>
#include <libpmemobj++/pool.hpp>
#include <libpmemobj++/v.hpp>

using namespace pmem::obj;

void v_property_example()
{
    struct foo {
        foo() : counter(10) {}
        int counter;
    };

    // pool root structure
    struct root {
        v<foo> f;
    };

    // create a pmemobj pool
    auto pop = pool<root>::create("poolfile", "layout", PMEMOBJ_MIN_POOL);
    auto proot = pop.get_root();

    assert(proot->f.get().counter == 10);

    proot->f.get().counter++;

    assert(proot->f.get().counter == 11);
}
//! [v_property_example]
