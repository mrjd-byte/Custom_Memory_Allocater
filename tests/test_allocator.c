#include "allocator.h"
#include <stdio.h>

int main()
{
    int *a = my_malloc(100);
    printf("First address : %p\n", a);
    my_free(a);

    int *b = my_malloc(50);
    printf("Second address : %p\n", b);

    printf("Size: %zu Free: %d\n", head->size, head->free);
    
    printf("Size: %zu Free: %d\n", head->next->size, head->next->free); //no output for this line, as head->next is NULL
    return 0;
}