#include <Span.hpp>

Span::Span() : _size_max(10){}

Span::Span(unsigned int size_max) : _size_max(size_max){}

Span::Span(const Span &other) : _size_max(other._size_max)
{
    _vec = other._vec;
}

Span::~Span(){}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _size_max = other._size_max;
        _vec = other._vec;
    }
    return (*this);
}

int Span::shortestSpan()
{
    std::vector<int> sorted;

    sorted = _vec;
    sort(sorted.begin(), sorted.end());
    if (sorted.size() < 2)
        throw NotEnoughElementsException();
    else
    {
        int minSpan = sorted[1] - sorted[0];
        long unsigned int i = 1;
        while (i < sorted.size() - 1)
        {
            if (sorted[i + 1] - sorted[i] < minSpan)
                minSpan = sorted[i + 1] - sorted[i];
            i++;
        }
        return (minSpan);
    }
}

int Span::longestSpan()
{
    std::vector<int> sorted;
    sorted = _vec;
    sort(sorted.begin(), sorted.end());
    if (sorted.size() < 2)
        throw NotEnoughElementsException();
    else
        return (sorted[sorted.size() - 1] - sorted[0]);
}

void Span::addNumber(int nb)
{
    if (_vec.size() < _size_max)
        _vec.push_back(nb);
    else
        throw TooManyElementsException();
}

void Span::addNumbers(int start, int end)
{
    if (start > end)
        throw IncorrectRangeException();
    if (_vec.size() + (end - start) < _size_max)
    {
        while(start <= end)
        {
            _vec.push_back(start);
            start++;
        }
    }
    else
        throw TooManyElementsException();
}

