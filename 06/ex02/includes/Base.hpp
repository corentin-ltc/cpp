#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
    public:
        Base(){};
        virtual ~Base(){};
        Base * generate(void);
        virtual void identify(Base* p);
        virtual void identify(Base& p);
};

#endif 