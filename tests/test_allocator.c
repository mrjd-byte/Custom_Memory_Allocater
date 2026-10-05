#include "allocator.h"
#include <stdio.h>

int main()
{
    int *a = my_malloc(100);
    int *b = my_malloc(200);
    int *c = my_malloc(300);

    print_heap();


    my_free(b);

    print_heap();


    my_free(c);

    print_heap();


    return 0;
}