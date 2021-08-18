/*
 * Task2, linked_list.c
 * Purpose: The implementation of the linked list library functions.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 12/08/2021
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * This function creates new element and adds it to the linked list.
 *
 * @param head is the pointer to the pointer the head of the linked list
 * @param data is the instance of DATA structure that contains a value
 * (the DATA structure is a wrapper around useful data and allows to make
 * the linked list independent from data type stored in it)
 * @return SUCCESS if element has been added to the list, or MEMORY_ALLOCATION_ERROR
 */
int list_add(struct LIST_ITEM **head, struct DATA data)
{
        // This branch executes if there are no elements in the list and the
        // very first element of the list will be created.
        if((*head) == NULL){
                *head = (struct LIST_ITEM *)malloc(sizeof(struct LIST_ITEM));
                if((*head) == NULL) {
                        return MEMORY_ALLOCATION_ERROR;
                }
                (*head)->data = data;
                (*head)->next = NULL;  
        }
        // This branch executes if the list contains some elements and
        // new element will be created and added to the end (i.e. tail) of the list.
        else {
                struct LIST_ITEM *node = *head;
                while(node->next != NULL) {
                        node = node->next;
                }
                node->next = (struct LIST_ITEM *)malloc(sizeof(struct LIST_ITEM));
                if(node->next == NULL) {
                        return MEMORY_ALLOCATION_ERROR;
                }
                node->next->next = NULL;
                node->next->data = data;
        }
        return SUCCESS;
}

/*
 * The function checks if the specific element is in the list.
 * 
 * @param head is the pointer to the head of the linked list
 * @param data is the pointer to the instance of DATA structure 
 * that contains a value to be found
 * @return SUCCESS if the element to search for is in the list, otherwise FAIL
 */
int list_contains(const struct LIST_ITEM *head, const struct DATA *data)
{
        if(head == NULL) {
                return FAIL;
        }
        do {
                if(head->data.value == (*data).value) {
                        return SUCCESS;
                }
                head = head->next;
        } while(head->next != NULL);
       
        return FAIL;
}

/*
 * The function removes the specific element from the list.
 * 
 * @param head is the pointer to the pointer to the head of the list
 * @param data is the pointer to the instance of DATA structure 
 * that contains a value that will be removed from the list
 * @return SUCCESS if the specific element was found and removed, otherwise FAIL
 */
int list_remove(struct LIST_ITEM **head, const struct DATA *data)
{
        // If there is no elements in the list
        if((*head) == NULL) {
                return FAIL;
        }
     
        if((*head)->data.value == data->value) {
                struct LIST_ITEM *temp = *head;
                (*head) = (*head)->next;
                free(temp);
                return SUCCESS;
         } else {
                 struct LIST_ITEM *node = (*head);
                 while(node->next != NULL) {
                         if(node->next->data.value == data->value) {
                               struct LIST_ITEM *temp = node->next;
                               node->next = node->next->next;
                               free(temp);
                               return SUCCESS;
                         }
                        node = node->next;
                 }
         }
        return FAIL;
}

/*
 * The function determines the number of elements in the linked list.
 * 
 * @param head is the pointer to the head of the linked list
 * @return the number of elements in the list
 */
int list_size(const struct LIST_ITEM *head)
{
        int size = 0;
        while(head != NULL) {
                size++;
                head = head->next;
        }
        return size;
}

/*
 * The function deletes all the elements from the list and frees allocated memory.
 * 
 * @param head is the pointer to the pointer to the head of the linked list
 * @return SUCCESS if all elements were removed from the list and 
 */
int list_clear(struct LIST_ITEM **head)
{
        struct LIST_ITEM *temp;
        do {
                temp = (*head)->next;
                free(*head);
                *head = temp;
        } while((*head)->next != NULL);
        free(*head);
        *head = NULL;
        return SUCCESS;
}

/*
 * The function prints the value that an instance if DATA structure contains.
 * 
 * @param data is the instance of DATA structure to be printed
 */
void list_print_item(const struct DATA *data)
{
        printf("%d", data->value);
}

/*
 * The function prints all the elements that are in the list
 * 
 * @param head is the pointer to the head of the list
 */
void list_print_all(const struct LIST_ITEM *head)
{
        printf("[");
        while(head != NULL) {
                list_print_item(&(head->data));
                if(head->next != NULL) {
                        printf(", ");
                }
                head = head->next;
        }
        printf("]\n");
}
