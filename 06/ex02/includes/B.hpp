#include "Base.hpp"

class B : public Base
{
    private:
        std::string name;
    public:
        B() : name("B"){};
        ~B(){};

};