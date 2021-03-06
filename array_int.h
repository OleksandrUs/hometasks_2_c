/*
 * Task3, array_int.h
 * Purpose: The header file of the array library.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 12/08/2021
 */


#ifndef _ARRAY_INT_LIB_
#define _ARRAY_INT_LIB_

// Execution result codes returned by some functions
#define SUCCESS 0
#define ELEMENT_NOT_FOUND -1
#define ARR_EMPTY -2
#define ARR_IDEX_OUT_OF_BOUNDS -3

// This value returns from a function if memory allocation was unsuccessful
#define MEMORY_ALLOCATION_ERROR -1

/*
 * The structure is a wrapper around dynamically allocated array and it contains
 * the pointer to the first element of the dynamically allocated array and
 * its size (max number of elements to store).
 */
typedef struct {
        int *array;
        int size;
} ARRAY_INT;

/*
 * Function prototypes
 */
int ar_push(ARRAY_INT **arr, int value);
int ar_find_first(const ARRAY_INT *arr, int value);
int ar_remove(ARRAY_INT *arr, int index);

int ar_size(ARRAY_INT *arr);
struct ARRAY_INT* ar_create(int size);
void ar_destroy(ARRAY_INT *arr);
void ar_print(const ARRAY_INT *arr);

#endif