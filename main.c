/*
** EPITECH PROJECT, 2021
** Malloc bootstrap
** File description:
** myfunctions
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "include/my_malloc.h"
void myputchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int main()
{
    void *addr = 0;
    for (int i = 0; i != 3; i++)
    {
        char *test_2 = malloc(sizeof(char));
        test_2 = strcpy(test_2, "T\n");
        addr = test_2;
        //printf("address test2 %p\n", addr);
    }

    my_putstr("step1");
    char *toto = malloc(sizeof(char));
    strcpy(toto, "toto");
    my_putstr(toto);
    addr = toto;
    //printf("address toto %p\n", addr);

    //printf("my break is at %p\n", sbrk(0));
    char *test = malloc(sizeof(char) * 7000);
    strcpy(test, "test");
    my_putstr(test);
    addr = test;
    // printf("address test %p\n", test);

    int *stitch = malloc(sizeof(int));
    stitch[0] = 23;
    my_put_nbr(stitch[0]);
    my_putstr("");
    addr = stitch;
    //printf("address stitch %p\n", stitch);

    int *titi = malloc(sizeof(int));
    titi[0] = 2345;
    my_put_nbr(titi[0]);
    my_putstr("");
    addr = titi;
    //printf("address titi %p\n", titi);
    //printf("my break is at %p\n", sbrk(0));

    int *tete = realloc(tete, sizeof(int));
    tete[0] = 111;
    my_put_nbr(tete[0]);
    my_putstr("");
    return 0;
}
