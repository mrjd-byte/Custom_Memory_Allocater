#include "../include/allocator.h"
#include <stdio.h>

int main()
{
    printf("===== MALLOC TEST =====\n");

    int *ptr = my_malloc(sizeof(int));

    if(ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    *ptr = 42;

    printf("Stored value: %d\n", *ptr);

    print_heap();

    return 0;
}