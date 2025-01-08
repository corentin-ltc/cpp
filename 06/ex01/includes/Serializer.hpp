#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &src);
        ~Serializer();
    public:
        Serializer& operator=(const Serializer &src);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif