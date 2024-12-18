#include "Serializer.hpp"

int main(void)
{
    Data *test = new Data("Hello");
    Data *test2;
    uintptr_t intptr;
    Serializer s;

    intptr = s.serialize(test);
    test2 = s.deserialize(intptr);

    std::cout << test2->getName() << std::endl;

    return 0;
}
