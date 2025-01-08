#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T>
class Array{

    private:
        T *_elements;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int  n);
        Array(const Array &other);
        Array &operator=(const Array &other)
        ~Array();
        class OutOfBoundsExeption : public std::exceptions
        {
            public:
            const char *what() const throw()
            {
                return ("Cannot access array: Out of bounds");
            }
        };
};


#endif