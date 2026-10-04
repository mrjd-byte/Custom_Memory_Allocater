#include "allocator.h"
#include <stdio.h>

int main()
{
    int *a = my_malloc(100);
    int *c = my_malloc(200);
    my_free(c);

    int *b = my_malloc(50);

    //print linkedlist
    struct block *current = head;
    while (current != NULL)
    {
        printf("Block size: %zu, Free: %d\n", current->size, current->free);
        current = current->next;
    }
}