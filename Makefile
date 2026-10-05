CC = gcc

CFLAGS = -Iinclude

SRC = src/allocator.c


test_malloc:
	$(CC) $(CFLAGS) $(SRC) tests/test_malloc.c -o test_malloc


test_free:
	$(CC) $(CFLAGS) $(SRC) tests/test_free.c -o test_free


test_split:
	$(CC) $(CFLAGS) $(SRC) tests/test_split.c -o test_split


test_merge:
	$(CC) $(CFLAGS) $(SRC) tests/test_merge.c -o test_merge


test_calloc:
	$(CC) $(CFLAGS) $(SRC) tests/test_calloc.c -o test_calloc


test_realloc:
	$(CC) $(CFLAGS) $(SRC) tests/test_realloc.c -o test_realloc


clean:
	rm -f test_malloc test_free test_split test_merge test_calloc test_realloc