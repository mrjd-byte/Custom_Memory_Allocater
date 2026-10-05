#include "../include/allocator.h"
#include <stdio.h>

int main()
{
    printf("===== MERGE TEST =====\n");


    void *a = my_malloc(100);
    void *b = my_malloc(200);


    printf("\nAfter allocations:\n");
    print_heap();



    my_free(a);

    printf("\nAfter freeing A:\n");
    print_heap();



    my_free(b);

    printf("\nAfter freeing B:\n");
    print_heap();


    return 0;
}