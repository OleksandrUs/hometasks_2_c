/*
 * Task3, task3.c
 * Purpose: create an integer array library with functions ar_push(), ar_find_first(),
 * ar_remove(). Array should be allocated dynamically. The ar_push() function adds
 * a new element after the last one; ar_find_first() returns the positive index of
 * the first occurence of the given element in the array or -1 if the number is not
 * in the array; ar_remove() removes the element by it's index. Order of elements 
 * in an array is not important.
 * 
 * @author Oleksandr Ushkarenko
 * @version 1.0 11/08/2021
 */

#include <stdio.h>
#include "array_int.h"

/*
 * The main function of the program.
 * Demonstration of using the functions from the integer array library.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        struct ARRAY_INT *array = NULL;

        // Add elements to the array
        ar_push(&array, 1);
        ar_push(&array, 2);
        ar_push(&array, 3);
        ar_push(&array, 4);
        ar_push(&array, 5);

        //Print the array
        ar_print(array);
        
        // Print the number of elements in the array
        printf("size=%d\n", array->size);

        // Print indexes of some elements that are (or not) in the array
        int value_to_find = 2;
        printf("The index of %d is %d\n", value_to_find, ar_find_first(array, value_to_find));
        value_to_find = 5;
        printf("The index of %d is %d\n", value_to_find, ar_find_first(array, value_to_find));
        value_to_find = 9;
        printf("The index of %d is %d\n", value_to_find, ar_find_first(array, value_to_find));

        // Delete all elements in the array and free the allocated memory
        ar_destroy(array);

        return 0;
}