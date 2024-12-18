#include "Base.hpp"
#include "A.hpp"

int main(void)
{
    Base test;
    A test2;
    Base *ptr;

    ptr = test.generate();
    ptr->identify(ptr);
    ptr->identify(NULL);
    ptr->identify(&test2);
    return 0;
}
