#include "allocator.h"
#include <stdio.h>

void print_blocks()
{
    struct block *current = head;

    printf("BLOCK LIST\n");

    while(current != NULL)
    {
        printf("Block: %p\n", (void *)current);
        printf("Size: %zu\n", current->size);
        printf("Free: %d\n", current->free);
        printf("Prev: %p\n", (void *)current->prev);
        printf("Next: %p\n\n", (void *)current->next);

        current = current->next;
    }
}

int main()
{
    int *a = my_malloc(100);
    int *b = my_malloc(200);
    int *c = my_malloc(300);

    printf("After allocations:");
    print_blocks();


    printf("Freeing B\n");
    my_free(b);

    print_blocks();


    printf("Freeing C\n");
    my_free(c);

    print_blocks();


    return 0;
}