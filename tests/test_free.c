#include "../include/allocator.h"
#include <stdio.h>

int main()
{
    printf("===== FREE TEST =====\n");

    int *ptr = my_malloc(100);

    printf("\nBefore free:\n");
    print_heap();


    my_free(ptr);


    printf("\nAfter free:\n");
    print_heap();


    return 0;
}