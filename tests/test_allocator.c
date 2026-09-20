#include "../include/allocator.h"
#include <stdio.h>

int main() {
    struct block b;
    b.size = 1024;
    b.free = 0;
    b.next = NULL;

    printf("Block created");
    printf("Size: %zu, Free: %d, Next: %p\n", b.size, b.free, (void*)b.next);
}