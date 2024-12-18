#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>

Base * Base::generate(void)
{
    Base *base;
    int rdm;

    srand(time(NULL));
    rdm = rand();
    rdm %= 3;
    if (rdm == 0)
        return (base = new A());
    else if (rdm == 1)
        return (base = new B());
    else
        return (base = new C());
}

void Base::identify(Base* p) 
{
    A *a;
    B *b;
    C *c;

    if (!p)
    {
        std::cout << "This pointer is NULL." << std::endl;
        return ;
    }
    a = dynamic_cast<A*> (p);
    if (a)
    {
        std::cout << "The class is A." << std::endl;
        return ;
    }
    b = dynamic_cast<B*> (p);
    if (b)
    {
        std::cout << "The class is B." << std::endl;
        return ;
    }
    c = dynamic_cast<C*> (p);
    if (c)
    {
        std::cout << "The class is C." << std::endl;
        return ;
    }
    std::cout << "The class is not valid." << std::endl;

}
void Base::identify(Base& p) 
{
    try
    {
        A *a = dynamic_cast<A*> (&p);
        (void)a;
        std::cout << "The class is A." << std::endl;
        return ;
    }
    catch (...){}
    try
    {
        B *b = dynamic_cast<B*> (&p);
        std::cout << "The class is B." << std::endl;
        (void)b;
        return ;
    }
    catch (...){}
    try
    {
        C *c = dynamic_cast<C*> (&p);
        std::cout << "The class is C." << std::endl;
        (void)c;
        return ;
    }
    catch (...){
        std::cout << "The class is not valid." << std::endl;
    }
}