#include "allocator.h"
#include <stdio.h>

int main()
{
    char *a = my_malloc(13);

    struct block *header = (struct block *)a - 1;

    printf("Requested: 13\n");
    printf("Allocated: %zu\n", header->size);

    printf("Address: %p\n", a);

    return 0;
}