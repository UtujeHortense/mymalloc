/*
** EPITECH PROJECT, 2021
** Malloc 
** File description:
** myfunctions
*/

#include "my_malloc.h"

void *find_bestsize(meta_d *mylist, int *bestsize, size_t mysize)
{
    void *ptr = NULL;
    while (mylist) {
        if (mylist->size >= mysize && mylist->is_free == true) {
            if (*bestsize == -1 || (int)mylist->size <= *bestsize) {
                *bestsize = mylist->size;
                ptr = mylist;
            }
        }
        mylist = mylist->next;
    }
    return ptr;
}

void resize_list(int bestsize, size_t mysize, meta_d **tmp, void *ptr)
{
    meta_d *newnode = NULL;
    if (bestsize != -1)
        while ((*tmp)) {
            if (*tmp == ptr && (*tmp)->size - mysize > 0) {
                newnode = (void *)(long int)ptr + (long int)mysize;
                newnode->is_free = true;
                newnode->size = (*tmp)->size - mysize;
                newnode->next = NULL;
                (*tmp)->size = mysize;
                (*tmp)->is_free = false;
                if ((*tmp)->next != NULL)
                    newnode->next = (*tmp)->next;
                (*tmp)->next = newnode;
            }
            else if (*tmp == ptr && (*tmp)->size - mysize <= 0)
                (*tmp)->is_free = false;
            *tmp = (*tmp)->next;
        }
}
void *check_for_space(size_t size, void **myhead)
{
    meta_d *tmp = *myhead;
    meta_d *mylist = *myhead;
    int bestsize = -1;
    size_t mysize = my_power_of_2(size + meta_d_size);
    void *ptr = find_bestsize(mylist, &bestsize, mysize);
    resize_list(bestsize, mysize, &tmp, ptr);
    if (bestsize == -1)
        return NULL;
    return ptr + 1;
}