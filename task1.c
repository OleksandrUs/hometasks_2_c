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
 * These identifiers are used as codes to identify whether a function call was successfull
 * or an error occured.
 */
#define SUCCESS 0
#define MEMORY_ALLOC_ERR_CODE 1
#define NEGATIVE_ARRAY_SIZE_ERR_CODE 2

/*
 * The data structure is used to describe the element of an array of integer numbers.
 */
typedef struct {
        // The value of an array element
        int value;
        // The index of the value in an array.
        unsigned int index;
} ARRAY_ELEMENT;

/*
 * The prototype of the function that finds the biggest element in an array of ints.
 */
int find_max_value(const int *arr, int size);

/*
 * The prototypes of additional function to demonstrate the work of the program.
 */
ARRAY_ELEMENT find_max_element(const int *arr, int size);
int bulid_array_of_ints(int **arr, int *size);
void print_element_info(const ARRAY_ELEMENT *element);
void print_int_value(int value);
void print_error_message(int status);
int get_array_size(void);

/*
 * The main function of the program.
 * Demonstration of using the function that finds the biggest element in an array of ints.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        int *array = NULL;
        int size = 0;

        int status = bulid_array_of_ints(&array, &size);

        if(status == SUCCESS) {
                // This code allows to find the biggest element and its index in an array of ints
                ARRAY_ELEMENT max_element = find_max_element(array, size);
                print_element_info(&max_element);

                // This code allows to find only the biggest element array of ints (simplified version)
                // int max_val = find_max_value(array, size);
                // print_int_value(max_val);
        }
        else {
                print_error_message(status);
        }

        if(array != NULL) {
                free(array);
        }
        return 0;
}

/*
 * The function finds the biggest element in an array of integer numbers.
 *
 * @param arr is an array of integer numbers
 * @param size the size of the array
 * @return the biggest number in the array
 */
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

/*
 * The function finds the biggest element in an array of integer numbers and returns
 * its value and index in the form of ARRAY_ELEMENT data format.
 *
 * @param arr is an array of integer numbers
 * @param size the size of the array
 * @return the instance of ARRAY_ELEMENT thet contains the biggest element in the array and its index
 */
ARRAY_ELEMENT find_max_element(const int *arr, int size)
{
        ARRAY_ELEMENT element;
        element.value = arr[0];
        element.index = 0;

        for(int i = 0; i < size; i++) {
                if(element.value < arr[i]) {
                        element.value = arr[i];
                        element.index = i;
                }
        }

        return element;
}

/*
 * The function is used to create an array of integer numbers, received from a user.
 * The function allocates memory for storing array elements and it must be freed
 * after not needed.
 * 
 * @param out arr the pointer to the pointer of int that is used to address the allocated memory
 * @param out size the size of the array received from a user
 * @return SUCCESS if successful or one of the error codes
 */
int bulid_array_of_ints(int **arr, int *size)
{
        *size = get_array_size();

        if((*size) <= 0) {
                return NEGATIVE_ARRAY_SIZE_ERR_CODE;
        }

        *arr = (int *)malloc((*size) * sizeof(int));
        if((*arr) == NULL) {
                return MEMORY_ALLOC_ERR_CODE;
        }

        printf("Enter %d elements of the array A:\n", *size);

        for(int i = 0; i < (*size); i++)
        {
                printf("A[%d]=", i);
                fflush(stdout);
                scanf("%d", &((*arr)[i]));
        }

        return SUCCESS;
}

/*
 * The function prints the formatted string with the information that the instance
 * of the ARRAY_ELEMENT data structure contains.
 * 
 * @param the instance of the ARRAY_ELEMENT data structure that contains
 * the value and the index of an array element 
 */
void  print_element_info(const ARRAY_ELEMENT *element)
{
        printf("The biggest element in the array is %d. Its index is %d.\n", element->value, element->index);
}

/*
 * The function prints the formatted string with the integer number.
 * 
 * @param value the integer number to be printed
 */
void  print_int_value(int value)
{
        printf("The biggest element in the array is %d.\n", value);
}

/*
 * The function prints the message that depends on the value passed into it.
 * 
 * @param status the code according to which the message will be printed
 */
void print_error_message(int status) 
{
        if(status == MEMORY_ALLOC_ERR_CODE) {
                printf("Memory allocation error!\n");
        }
        else if (status == NEGATIVE_ARRAY_SIZE_ERR_CODE) {
                printf("The number of enements must be positive value!\n");
        }
        else {
                printf("Unkown error!\n");
        }
}

/*
 * The function receives from the user the size of an array.
 *
 * @return the size of an array that will be created
 */
int get_array_size(void)
{
        int size;
        printf("Enter the number of elements in the array: ");
        fflush(stdout);
        scanf("%d", &size);
        return size;
}