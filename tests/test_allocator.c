#include "allocator.h"
#include <stdio.h>

int main()
{
    void *a = my_malloc(0);

    printf("malloc(0): %p\n", a);


    void *b = my_realloc(NULL,100);

    printf("realloc(NULL,100): %p\n", b);


    b = my_realloc(b,0);

    printf("realloc(ptr,0): %p\n", b);


    void *c = my_calloc(100,100);

    printf("calloc: %p\n", c);

    return 0;
}