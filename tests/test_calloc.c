#include "../include/allocator.h"
#include <stdio.h>


int main()
{
    printf("===== CALLOC TEST =====\n");


    int *arr = my_calloc(5, sizeof(int));


    if(arr == NULL)
    {
        printf("calloc failed\n");
        return 1;
    }


    for(int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    print_heap();


    return 0;
}