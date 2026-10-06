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

void add_allocation(void *ptr)
{
    if (ptr == NULL)
    {
        printf("Cannot store NULL allocation\n");
        return;
    }

    if (allocation_count >= MAX_ALLOCATIONS)
    {
        printf("Allocation table full\n");
        return;
    }

    allocations[allocation_count].id = allocation_count + 1;
    allocations[allocation_count].ptr = ptr;

    printf("Allocated ID: %d\n", allocations[allocation_count].id);

    allocation_count++;
}

void free_allocation(int id)
{
    for (int i = 0; i < allocation_count; i++)
    {
        if (allocations[i].id == id)
        {
            if (allocations[i].ptr == NULL)
            {
                printf("Block already freed\n");
                return;
            }

            my_free(allocations[i].ptr);

            allocations[i].ptr = NULL;

            printf("Freed ID: %d\n", id);

            return;
        }
    }

    printf("Allocation ID not found\n");
}

int main()
{
    char command[100];

    printf("===== Custom Memory Allocator Shell =====\n");

    while (1)
    {
        printf("\nallocator> ");

        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = '\0';

        char *token = strtok(command, " ");

        if (token == NULL)
            continue;

        if (strcmp(token, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        else if (strcmp(token, "heap") == 0)
        {
            print_heap();
        }

        else if (strcmp(token, "malloc") == 0)
        {
            char *size_str = strtok(NULL, " ");

            if (size_str == NULL)
            {
                printf("Usage: malloc <size>\n");
                continue;
            }

            size_t size = atoi(size_str);

            void *ptr = my_malloc(size);

            if (ptr == NULL)
            {
                printf("Allocation failed\n");
            }
            else
            {
                add_allocation(ptr);
            }
        }

        else if (strcmp(token, "calloc") == 0)
        {
            char *count_str = strtok(NULL, " ");
            char *size_str = strtok(NULL, " ");

            if (count_str == NULL || size_str == NULL)
            {
                printf("Usage: calloc <count> <size>\n");
                continue;
            }

            size_t count = atoi(count_str);
            size_t size = atoi(size_str);

            void *ptr = my_calloc(count, size);

            if (ptr == NULL)
            {
                printf("Allocation failed\n");
            }
            else
            {
                add_allocation(ptr);
            }
        }

        else if (strcmp(token, "free") == 0)
        {
            char *id_str = strtok(NULL, " ");

            if (id_str == NULL)
            {
                printf("Usage: free <id>\n");
                continue;
            }

            int id = atoi(id_str);

            free_allocation(id);
        }

        else
        {
            printf("Unknown command\n");
        }
    }

    return 0;
}