#include "Base.hpp"

class B : public Base
{
    private:
        std::string name;
    public:
        B() : name("B"){};
        ~B(){};
        void identify(Base* p){std::cout << "Type is B" << std::endl;};
        void identify(Base& p){std::cout << "Type is B" << std::endl;};

};