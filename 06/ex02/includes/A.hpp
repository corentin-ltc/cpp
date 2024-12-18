#include "Base.hpp"

class A : public Base
{
    private:
        std::string name;
    public:
        A() : name("A"){};
        ~A(){};
        void identify(Base* p){std::cout << "Type is A" << std::endl;};
        void identify(Base& p){std::cout << "Type is A" << std::endl;};

};