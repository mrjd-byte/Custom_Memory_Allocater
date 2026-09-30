#include "allocator.h"
#include <stdio.h>

int main()
{
    int *a = my_malloc(100);
    int *b = my_malloc(200);

    printf("Before free : %d\n", head->free);
    printf("Before free : %d\n", head->next->free);
    my_free(a);
    printf("After free : %d\n", head->free);
    my_free(b);
    printf("Before free : %d\n", head->next->free);
    return 0;
}