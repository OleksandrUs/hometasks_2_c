/*
 * Task1, task1.c
 * Purpose: write a function that finds the biggest element in an array of ints.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 11/08/2021
 */

#include "stdio.h"
#include "stdlib.h"

/*
 * Function prototypes
 */
int find_max_value(const int *arr, int size);
void print_value(int value);

int main(int argc, char *argv[])
{
        int size = 0;
        printf("Enter the number of elements in an array:");
        fflush(stdout);
        scanf("%d", &size);
        if(size <= 0) {
                printf("The number of elements must be positive.\n");
        }
        else{
                int * arr;
                arr = (int*)malloc(size * sizeof(int));
                if(arr == NULL) {
                        printf("Memory allocation error!\n");
                }
                else {
                        printf("Enter the elements of the array A:\n");
                        for(int i = 0; i < size; i++) {
                                printf("A[%d]=", i);
                                fflush(stdout);
                                scanf("%d", &arr[i]);
                        }
                        int max_val;
                        max_val = find_max_value(arr, size);
                        print_value(max_val);
                        free(arr);
                }
        }
       
        return 0;
}

int find_max_value(const int *arr, int size)
{
        int max_val = arr[0];

        for(int i = 0; i < size; i++) {
                if(max_val < arr[i]) {
                        max_val = arr[i];
                }
        }

        return max_val;
}

void print_value(int value)
{
        printf("The biggest element in the array is %d. ", value);
}