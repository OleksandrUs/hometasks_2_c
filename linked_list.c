#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

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

int list_size(const struct LIST_ITEM *head)
{
        int size = 0;
        while(head != NULL) {
                size++;
                head = head->next;
        }
        return size;
}

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
}

void list_print_item(const struct DATA *data)
{
        printf("%d", data->value);
}

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
