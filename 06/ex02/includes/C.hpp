#include "Base.hpp"

class C : public Base
{
    private:
        std::string name;
    public:
        C() : name("C"){};
        ~C(){};

};