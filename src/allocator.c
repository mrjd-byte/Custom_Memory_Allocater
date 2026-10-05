#include "allocator.h"
#include <unistd.h>
#include <string.h>
#define ALIGNMENT 8

size_t align_size(size_t size)
{
    return (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

struct block *head = NULL;

void *my_malloc(size_t size)
{
    size = align_size(size);
    size_t total_size;
    struct block *block;

    total_size = size + sizeof(struct block);
    block = find_free_block(size);

    if (block != NULL)
    {
        if (block->size >= size + sizeof(struct block))
        {
            split_block(block, size);
        }

        block->free = 0;

        return (void *)(block + 1);
    }

    block = sbrk(total_size);

    if (block == (void *)-1)
    {
        return NULL;
    }

    block->size = size;
    block->free = 0;
    block->next = NULL;
    block->prev = NULL;

    if (head == NULL)
    {
        head = block;
    }
    else
    {
        struct block *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = block;
        block->prev = current;
    }

    return (void *)(block + 1); // move 24 bytes
}

void my_free(void *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    struct block *block = (struct block *)ptr - 1;

    block->free = 1;

    merge_blocks(block);

    if (block->prev != NULL)
    {
        merge_blocks(block->prev); 
    }
}

struct block *find_free_block(size_t size)
{
    struct block *current = head;

    while (current != NULL)
    {
        if (current->free == 1 && current->size >= size)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void split_block(struct block *block, size_t size)
{
    struct block *new_block;

    new_block = (struct block *)((char *)block + sizeof(struct block) + size);
    new_block->size = block->size - size - sizeof(struct block);
    new_block->free = 1;
    new_block->next = block->next;
    new_block->prev = block;

    if (block->next != NULL)
    {
        block->next->prev = new_block;
    }

    block->next = new_block;
    block->size = size;
}

void merge_blocks(struct block *block)
{
    struct block *next_block = block->next;

    if (next_block == NULL || next_block->free == 0)
    {
        return;
    }

    block->size += sizeof(struct block) + next_block->size;

    block->next = next_block->next;

    if (next_block->next != NULL)
    {
        next_block->next->prev = block;
    }
}

void *my_calloc(size_t count, size_t size)
{
    size_t total_size = count * size;

    void *ptr = my_malloc(total_size);

    if(ptr == NULL)
    {
        return NULL;
    }

    memset(ptr, 0, total_size);

    return ptr;
}

void *my_realloc(void *ptr, size_t size)
{
    if(ptr == NULL)
    {
        return my_malloc(size);
    }

    struct block *block = (struct block *)ptr - 1;

    if(block->size >= size)
    {
        return ptr;
    }
    
    if(block->next != NULL && block->next->free == 1)
    {
        size_t total_size = block->size + sizeof(struct block) + block->next->size;

        if (total_size >= size)
        {
            merge_blocks(block);
            block->free = 0;
            return ptr;
        }   
    }

    void *new_ptr = my_malloc(size);

    if(new_ptr == NULL)
    {
        return NULL;
    }

    memcpy(new_ptr, ptr, block->size);

    my_free(ptr);

    return new_ptr;
}
