#ifndef _LINKED_LIST_LIB_
#define _LINKED_LIST_LIB_

#define SUCCESS 0
#define FAIL 1
#define MEMORY_ALLOCATION_ERROR 2

struct DATA
{
        int value;
};

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