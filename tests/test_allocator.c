#include "allocator.h"
#include <stdio.h>

void print_blocks()
{
    struct block *current = head;

    printf("BLOCK LIST\n");

    while (current != NULL)
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

    my_free(a);

    int *b = my_calloc(20, sizeof(char));

    printf("%p\n", a);
    printf("%p\n", b);
}