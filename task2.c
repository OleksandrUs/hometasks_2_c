/*
 * Task2, task2.c
 * Purpose: create a linked list library with functions list_add(), list_contains(),
 * list_remove(). Elements in a list should be dynamically allocated. 
 * 
 * @author Oleksandr Ushkarenko
 * @version 1.0 11/08/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * The main function of the program.
 * Demonstration of using the functions from the linked list library.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        struct LIST_ITEM * list = NULL;
        struct DATA data;

        // Create list and add 5 elements (from 1 to 5)
        for(int i = 1; i < 6; i++) {
                data.value = i;
                if(list_add(&list, data) != SUCCESS) {
                        printf("Error while adding item to list!\n");
                        exit(0);
                }
        }

        // Print the number of elements in the list (i.e. size of the list)
        printf("The linked list contains %d elements.\n", list_size(list));

        // Print all elements that are in the list
        list_print_all(list);

        // Chech if list contains some elements
        data.value = 2;
        if(list_contains(list, &data) == SUCCESS) {
                printf("Value %d is in the list\n", data.value);
        } else {
                printf("Value %d is not in the list\n", data.value);
        }

        data.value = 7;
        if(list_contains(list, &data) == SUCCESS) {
                printf("Value %d is in the list\n", data.value);
        } else {
                printf("Value %d is not in the list\n", data.value);
        }

        // Delete some elements from the list
        printf("Removing elements 1, 8(not in list), 5 from the list.\n");
        data.value = 1; 
        list_remove(&list, &data);
        data.value = 8; // this element is not in the list
        list_remove(&list, &data);
        data.value = 5;
        list_remove(&list, &data);
        
        // Print the number of elements in the list after deleting some of them
        printf("The linked list contains %d elements after deleting some of them.\n", list_size(list));

        // Print all elements that are in the list after deleting an element
        list_print_all(list);

        // Delete all elements and free the memory that was allocated before.
        list_clear(&list);
        
        // Print the number of elements in the list after it has been cleared 
        // (i.e. after deleting all elements from the list).
        printf("The linked list after deleting all elements contains %d elements.\n", list_size(list));

        return 0;
}
