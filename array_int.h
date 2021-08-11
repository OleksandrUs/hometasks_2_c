#ifndef _ARRAY_INT_LIB_
#define _ARRAY_INT_LIB_

#define SUCCESS 0
#define ELEMENT_NOT_FOUND -1
#define ARR_EMPTY -1

// This value returns from a function if memory allocation was unsuccessful
#define MEMORY_ALLOCATION_ERROR -1

struct ARRAY_INT {
        int *array;
        int size;
};

/*
 * Function prototypes
 */
int ar_push(struct ARRAY_INT **arr, int value);
int ar_find_first(const struct ARRAY_INT *arr, int value);
int ar_remove(struct ARRAY_INT *arr, int index);

int ar_size(struct ARRAY_INT *arr);
struct ARRAY_INT* ar_create(int size);
void ar_destroy(struct ARRAY_INT *arr);
void ar_print(const struct ARRAY_INT *arr);

#endif