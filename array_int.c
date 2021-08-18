/*
 * Task3, array_int.c
 * Purpose: The implementation of the array library functions. Array are allocated dynamically.
 * The ar_push() function adds a new element after the last one; ar_find_first() returns 
 * the positive index of the first occurrence of the given element in the array or -1 
 * if the number is not in the array; ar_remove() removes the element by it's index.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 12/08/2021
 */

#include "array_int.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * The funcion adds new element to the end on an array. 
 * 
 * @param arr the pointer to the pointer to the instance of ARRAY_INT data structure,
 * which is the wrapper around dynamically allocated array.
 * @param value the value to be added to the array
 * @return SUCCESS if new element added to the array, otherwise MEMORY_ALLOCATION_ERROR
 */
int ar_push(ARRAY_INT **arr, int value)
{
        // If it is the first element to add into the array, the memory will be allocated
        if((*arr) == NULL) {
                (*arr) = malloc(sizeof(ARRAY_INT));
                if(*arr == NULL) {
                        return MEMORY_ALLOCATION_ERROR;
                }

                (*arr)->array = malloc(sizeof(int));
                if(((*arr)->array) == NULL) {
                        return MEMORY_ALLOCATION_ERROR;
                }

                (*arr)->array[0] = value;
                (*arr)->size = 1;
        }
        // If there are elements in the array, the memory for new array will be allocated
        // and the size of the new array will be one more storage unit
        else
        {
                int *new_arr = malloc(((*arr)->size + 1) * sizeof(int));
                if(new_arr == NULL) {
                        return MEMORY_ALLOCATION_ERROR;
                }
                int i;
                for(i = 0; i < (*arr)->size; i++) {
                        new_arr[i] = (*arr)->array[i];
                }
                new_arr[i] = value;

                int *old_arr = (*arr)->array;
                (*arr)->array = new_arr;
                (*arr)->size++;
                free(old_arr);
        }

        return SUCCESS;
}

/*
 * The function finds the index of the first occurrence of the given element 
 * in the array.
 * 
 * @param arr the pointer to the dynamically allocated array (an instance of ARRAY_INT data structure)
 * @param value the value, the index of the first occurrence in the array of which it is needed to find
 * @return index of the first occurance in the array of given value, otherwise ELEMENT_NOT_FOUND
 */
int ar_find_first(const ARRAY_INT *arr, int value)
{
        if(arr == NULL) {
                return ELEMENT_NOT_FOUND;
        }
        for(int i = 0; i < arr->size; i++) {
                if(arr->array[i] == value) {
                        return i;
                }
        }

        return ELEMENT_NOT_FOUND;
}

/*
 * This function removes the element by it's index from the array.
 * 
 * @param arr the pointer to the dynamically allocated array (an instance of ARRAY_INT data structure)
 * @param index the index of the element to be removed from the array
 * @return SUCCESS if the element was removed from the array, ELEMENT_NOT_FOUND if the pointer to
 * the array is NULL, ARR_IDEX_OUT_OF_BOUNDS if the index of the element is out of bounds,
 * MEMORY_ALLOCATION_ERROR if there was an error while allocating memory
 */
int ar_remove(ARRAY_INT *arr, int index)
{
        if((arr == NULL) || (arr->array == NULL)) {
                return ELEMENT_NOT_FOUND;
        }

        if((index < 0) || (index > (arr->size - 1))) {
                return ARR_IDEX_OUT_OF_BOUNDS;
        }

        int *new_arr = malloc((arr->size - 1) * sizeof(int));
        if(new_arr == NULL) {
                return MEMORY_ALLOCATION_ERROR;
        }

        for(int i = 0; i < index; i++) {
                new_arr[i] = arr->array[i];
        }
        for(int i = index + 1; i < arr->size; i++) {
                new_arr[i - 1] = arr->array[i];
        }

        int *old_arr = arr->array;
        arr->array = new_arr;
        arr->size--;
        free(old_arr);
        return SUCCESS;
}

/*
 * The function allows to determine the number of elements that are in an array.
 *
 * @param arr the pointer to the dynamically allocated array
 * @return the number of elements in the array
 */
int ar_size(ARRAY_INT *arr)
{
        if(arr != NULL) {
                return arr->size;
        }
        return ARR_EMPTY;
}

/*
 * The function frees dynamically allocated memory.
 * 
 * @param the pointer to the dynamically allocated array
 */
void ar_destroy(ARRAY_INT *arr)
{
        if((arr != NULL) && (arr->array != NULL))
        {
                free(arr->array);
                arr->size = 0;
                free(arr);
        }
}

/*
 * The function prints all the elements that are in an array.
 *
 * @param the pointer to the dynamically allocated array
 */
void ar_print(const ARRAY_INT *arr)
{
        if((arr != NULL) && (arr->array != NULL)) {
                printf("[");
                int i;
                for(i = 0; i < arr->size - 1; i++) {
                        printf("%d, ", arr->array[i]);
                }
                printf("%d]\n", arr->array[i]);
        }
}

