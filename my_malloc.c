/*
** EPITECH PROJECT, 2021
** Malloc 
** File description:
** myfunctions
*/

#include "my_malloc.h"
void *myhead = NULL;

void *myfirst_alloc(size_t size, meta_d *ptr)
{
    meta_d *newnode = NULL;
    meta_d *mylist = myhead;
    size_t mysize = my_power_of_2(size + meta_d_size);
    newnode = (void *)(long int)ptr + (long int)mysize;
    newnode->is_free = true;
    newnode->size = ptr->size - mysize;
    newnode->next = NULL;
    ptr->size = mysize;
    ptr->is_free = false;
    ptr->next = newnode;
    if (!myhead)
        myhead = ptr;
    else {
        while (mylist->next)
            mylist = mylist->next;
        mylist->next = ptr;
    }
    return ptr + 1;
}

void *space_with_sbrk(size_t size)
{
    void *myaddr = NULL;
    size_t total_size = getpagesize() * 2;
    size_t mysize = my_power_of_2(size + meta_d_size);
    if (mysize >= total_size)
        total_size = (getpagesize() * 2) * 21;
    meta_d *ptr = sbrk(total_size);
    if (ptr == (void *)-1 || size <= 0)
        return NULL;
    ptr->is_free = true;
    ptr->size = total_size;
    ptr->next = NULL;
    myaddr = myfirst_alloc(size, ptr);
    return myaddr;
}

void *best_fit_alloc(size_t size)
{
    void *ptr = NULL;
    ptr = check_for_space(size, &myhead);

    if (ptr != NULL)
        return ptr + 1;
    else
        return space_with_sbrk(size);
    return NULL;
}

void *malloc(size_t size)
{

    if (!myhead)
        return space_with_sbrk(size);
    else
        return best_fit_alloc(size);

    return NULL;
}

void free(void *ptr)
{
    meta_d *mylist = myhead;

    while (mylist) {
        if ((mylist + 1) == ptr) {
            mylist->is_free = true;
            break;
        }
        mylist = mylist->next;
    }
}
