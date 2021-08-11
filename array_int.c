#include "array_int.h"
#include <stdio.h>
#include <stdlib.h>


int ar_push(struct ARRAY_INT **arr, int value)
{
        // If it is the first element to add into the array, the memory will be allocated
        if((*arr) == NULL) {
                (*arr) = malloc(sizeof(struct ARRAY_INT));
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
                for(i = 0; i<(*arr)->size; i++) {
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

int ar_find_first(const struct ARRAY_INT *arr, int value)
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

int ar_remove(struct ARRAY_INT *arr, int index)
{
        // TODO: add implementation
}

int ar_size(struct ARRAY_INT *arr)
{
        if(arr != NULL) {
                return arr->size;
        }
        return ARR_EMPTY;
}

void ar_destroy(struct ARRAY_INT *arr)
{
        if((arr != NULL) && (arr->array != NULL))
        {
                free(arr->array);
                arr->size = 0;
                free(arr);
        }
}

void ar_print(const struct ARRAY_INT *arr)
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
