/*
 * Task2, linked_list.h
 * Purpose: The header file of the linked list library.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 12/08/2021
 */

#ifndef _LINKED_LIST_LIB_
#define _LINKED_LIST_LIB_

// This value returns if a function call was succesfull
#define SUCCESS 0

// This value returns if a function call was unsuccesfull
#define FAIL 1

// This value returns from a function if memory allocation was unsuccessful
#define MEMORY_ALLOCATION_ERROR 2

/*
 * This data structure is used as a wrapper around the useful data (in this case the values of int data type)
 * and it allows to make list independent from data types stored in it
 * (i.e. a kind of abstraction).
 */
struct DATA
{
        int value;
};

/*
 * This structure describes the element (node) of the linked list.
 */
struct LIST_ITEM
{
        struct DATA data;
        struct LIST_ITEM *next; 
};

// The prototypes of base functions to work with a linked list
int list_add(struct LIST_ITEM **head, struct DATA data);
int list_contains(const struct LIST_ITEM *head, const struct DATA *data);
int list_remove(struct LIST_ITEM **head, const struct DATA *data);

// The prototypes of additional functions to work with a linked list
int list_size(const struct LIST_ITEM *head);
int list_clear(struct LIST_ITEM **head);
void list_print_item(const struct DATA *data);
void list_print_all(const struct LIST_ITEM *head);

#endif