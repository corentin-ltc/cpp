#include "Base.hpp"

class C : public Base
{
    private:
        std::string name;
    public:
        C() : name("C"){};
        ~C(){};
        void identify(Base* p){std::cout << "Type is C" << std::endl;};
        void identify(Base& p){std::cout << "Type is C" << std::endl;};

};