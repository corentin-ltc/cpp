#include "Base.hpp"

class A : public Base
{
    private:
        std::string name;
    public:
        A() : name("A"){};
        ~A(){};

};