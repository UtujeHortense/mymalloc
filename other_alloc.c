/*
** EPITECH PROJECT, 2021
** Malloc bootstrap
** File description:
** myfunctions
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;
    size_t total = nmemb * size;
    ptr = malloc(total);
    if (ptr == NULL)
        return NULL;
    memset(ptr, 0, total);
    return ptr;
}
void *realloc(void *ptr, size_t size)
{
    void *newptr = malloc(size);
    if (ptr == NULL)
        return newptr;
    else {
        memcpy(newptr, ptr, size);
        free(ptr);
    }
    return newptr;
}
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t mysize = nmemb * size;
    if (mysize > 0)
        return realloc(ptr, mysize);
    return NULL;
}
