#ifndef ITER_HPP
#define ITER_HPP


template <typename T>
void iter(T *tab, int size, void(*f)(T))
{
    int i = 0;

    while(i < size)
    {
        f(tab[i]);
        i++;
    }
}

#endif