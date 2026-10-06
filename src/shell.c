#include "allocator.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_ALLOCATIONS 100

struct allocation_entry
{
    int id;
    void *ptr;
};


struct allocation_entry allocations[MAX_ALLOCATIONS];

int allocation_count = 0;



int main()
{
    char command[100];


    printf("===== Custom Memory Allocator Shell =====\n");


    while(1)
    {
        printf("\nallocator> ");

        fgets(command, sizeof(command), stdin);


        command[strcspn(command, "\n")] = '\0';


        if(strcmp(command,"exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }


        else if(strcmp(command,"heap") == 0)
        {
            print_heap();
        }


        else
        {
            printf("Unknown command\n");
        }
    }


    return 0;
}