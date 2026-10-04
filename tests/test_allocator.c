#include "allocator.h"
#include <stdio.h>

int main()
{
    int *a = my_malloc(100);
    int *c = my_malloc(200);
    my_free(c);

    int *b = my_malloc(50);

    //print doulelinked list
    struct block *current = head;
    while (current != NULL)
    {
        printf("Block size: %zu, free: %d\n", current->size, current->free);
        printf("Prev: %p\n", (void *)current->prev);;
        current = current->next;
    }
}