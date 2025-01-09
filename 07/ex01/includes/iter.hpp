#pragma once


template <typename T, typename U>
void iter(T *tab, int size, void(*f)(U&))
{
    int i = 0;

    while(i < size)
    {
        f(tab[i]);
        i++;
    }
}
