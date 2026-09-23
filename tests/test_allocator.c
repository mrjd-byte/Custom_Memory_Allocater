#include "allocator.h"
#include <stdio.h>

int main()
{
    int *a = my_malloc(100);
    int *b = my_malloc(200);
    int *c = my_malloc(300);

    if (a == NULL || b == NULL || c == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    struct block *current = head;
    while (current != NULL)
    {
        printf("Block: %p | Size: %zu | Free: %d |Next: %p\n",
               (void *)current,
               current->size,
               current->free,
               current->next);
        current = current->next;
    }
    return 0;
}