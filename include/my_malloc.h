/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/
#ifndef MYMALLOC_HPP
#define MYMALLOC_HPP
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

typedef struct meta_data
{
    size_t size;
    bool is_free;
    struct meta_data *next;
} meta_d;

#define meta_d_size sizeof(meta_d)
void *best_fit_alloc(size_t size);
void *check_for_space(size_t size, void **myhead);
void *space_with_sbrk(size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
size_t my_power_of_2(size_t n);

#endif
