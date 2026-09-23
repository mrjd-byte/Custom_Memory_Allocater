#ifndef ALLOCATOR_H
#define ALLOCAOTR_H

#include <stddef.h>

struct block {
    size_t size;
    int free;
    struct block *next;  
};

extern struct block *head; //head exists
void *my_malloc(size_t size); // Function to allocate memory exists

#endif