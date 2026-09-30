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
void my_free(void *ptr); // Function to free memory exists
struct block *find_free_block(size_t size); // Function to find a free block exists

#endif