#include "allocator.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char *name = my_malloc(10);

    strcpy(name, "hello");

    printf("Before realloc: %s\n", name);

    name = my_realloc(name, 20);

    printf("After realloc: %s\n", name);

    return 0;
}