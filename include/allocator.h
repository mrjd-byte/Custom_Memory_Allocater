#ifndef ALLOCATOR_H
#define ALLOCAOTR_H

#include <stddef.h>

struct block {
    size_t size;
    int free;
    struct block *next;  
};

#endif