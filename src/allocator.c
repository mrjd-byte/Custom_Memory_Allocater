#include "allocator.h"
#include <unistd.h>


struct block *head = NULL;

void *my_malloc(size_t size) {
    size_t total_size;
    struct block *block;

    total_size = size + sizeof(struct block);

    block = sbrk(total_size);

    if (block == (void* )-1) {
        return NULL;
    }

    block->size = size;
    block->free = 0;
    block->next = NULL;
    
    if (head == NULL) {
        head = block;
    } else {
        struct block *current = head;
        while (current->next !=NULL){
            current = current->next;
        }
        current->next = block;
    }

   
    return (void*)(block + 1); //move 24 bytes
} 