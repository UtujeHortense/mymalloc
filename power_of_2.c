/*
** EPITECH PROJECT, 2021
** Malloc 
** File description:
** myfunctions
*/

#include <stdio.h>
size_t my_power_of_2(size_t n)
{
    size_t i = 1;
    if (n == i)
        return n;
    else
    {
        while (i < n)
            i = i << 1;
    }
    return i;
}
