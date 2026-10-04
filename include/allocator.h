#ifndef ALLOCATOR_H
#define ALLOCAOTR_H

#include <stddef.h>

struct block {
    size_t size;
    int free;
    struct block *next;  
    struct block *prev;
};

extern struct block *head; //head exists
void *my_malloc(size_t size); // Function to allocate memory exists
void my_free(void *ptr); // Function to free memory exists
struct block *find_free_block(size_t size); // Function to find a free block exists
void split_block(struct block *block, size_t size); // Function to split a block exists
void merge_blocks(struct block *block); // Function to merge blocks

#endif