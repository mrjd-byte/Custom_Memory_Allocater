#include "../include/allocator.h"
#include <stdio.h>
#include <string.h>

int main()
{
    printf("===== REALLOC TEST =====\n");

    char *a = my_malloc(20);

    char *b = my_malloc(200);


    strcpy(a,"Hello");


    printf("\nBefore realloc:\n");
    printf("Address: %p\n", a);


    my_free(b);


    a = my_realloc(a,100);


    printf("\nAfter realloc:\n");
    printf("Address: %p\n", a);

    printf("Data: %s\n", a);


    print_heap();

    return 0;
}