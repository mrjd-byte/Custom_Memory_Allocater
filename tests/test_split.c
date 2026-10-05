#include "../include/allocator.h"
#include <stdio.h>

int main()
{
    printf("===== SPLIT TEST =====\n");


    void *a = my_malloc(500);

    printf("\nAfter allocating 500:\n");
    print_heap();


    my_free(a);

    printf("\nAfter freeing 500:\n");
    print_heap();


    void *b = my_malloc(100);

    printf("\nAfter allocating 100:\n");
    print_heap();


    return 0;
}