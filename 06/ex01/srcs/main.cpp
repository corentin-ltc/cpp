#include "Serializer.hpp"

int main(void)
{
    Data *test = new Data("Hello");
    Data *test2;
    uintptr_t intptr;

    intptr = Serializer::serialize(test);
    test2 = Serializer::deserialize(intptr);

    std::cout << test2->getName() << std::endl;
    delete test;
    return 0;
}
