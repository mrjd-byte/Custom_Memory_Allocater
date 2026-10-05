#include "allocator.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char *a = my_malloc(100);
    char *b = my_malloc(300);

    strcpy(a,"hello");

    my_free(b);

    printf("Before realloc: %p\n", a);

    a = my_realloc(a,200);

    printf("After realloc: %p\n", a);
    printf("Data: %s\n", a);

    return 0;
}