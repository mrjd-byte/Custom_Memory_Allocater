#include "allocator.h"
#include <unistd.h>

struct block *head = NULL;

void *my_malloc(size_t size) {
    size_t total_size;
    struct block *block;
    
    total_size = size + sizeof(struct block);
    block = find_free_block(size);

    if (block != NULL) {
        if (block != NULL) {
            block->free = 0;
            return (void*)(block + 1);
        }
    }

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

void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    struct block *block = (struct block *)ptr - 1;

    block->free = 1;
}

struct block *find_free_block(size_t size)
{
    struct block *current = head;

    while(current != NULL) {
        if(current->free == 1 && current->size >= size) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}