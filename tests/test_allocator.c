#include "../include/allocator.h"
#include <stdio.h>

int main()
{
    int *ptr = my_malloc(sizeof(int));

    if(ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    *ptr = 42;
    
    printf("User pointer : %p\n", ptr);

    struct block *header = (struct block *)ptr - 1;

    printf("Header address: %p\n", header);

    printf("Header size: %zu\n", header->size);
    printf("Header free: %d\n", header->free);

    printf("Distance: %ld bytes\n",
           (char *)ptr - (char *)header);
    return 0;
}