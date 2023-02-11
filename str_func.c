/*
** EPITECH PROJECT, 2021
** Malloc bootstrap
** File description:
** myfunctions
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "include/my_malloc.h"

void myputchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int x = 0;
    while (str[x] != '\0')
    {
        myputchar(str[x]);
        x++;
    }
    myputchar('\n');
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648)
    {
        my_put_nbr(-214748364);
        myputchar('8');
        return (0);
    }
    if (nb < 0)
    {
        myputchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    myputchar(nb % 10 + '0');
    return (0);
}

void my_list(meta_d *tmp)
{
    int i = 0;
    my_putstr("PRINT NODE : ");
    while (tmp)
    {
        my_putstr("my node :");
        my_put_nbr(tmp->size);
        if (tmp->is_free == true)
            my_putstr(" FREE");
        else
            my_putstr(" NOT");
        my_putstr("");
        tmp = tmp->next;
        i++;
    }
    my_putstr("NUMBER OF NODE : ");
    my_put_nbr(i);
    my_putstr("");
}