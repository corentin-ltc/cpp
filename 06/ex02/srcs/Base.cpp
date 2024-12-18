#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * Base::generate(void)
{
    Base *base;
    int rdm = rand() % 3;

    if (rdm == 0)
        return (base = new A());
    if (rdm == 1)
        return (base = new B());
    if (rdm == 2)
        return (base = new C());
    return base;
}

void Base::identify(Base* p) const {}
void Base::identify(Base& p) const {}