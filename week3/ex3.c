#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void print_list(struct node *node)
{
    while(1)
    {
        if(node == NULL)
            break;
        printf(" %d ", node->value);
        node = node->next;
    }
}

void insert_node(struct node** node, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value  = new_data;
    new_node->next = (*node);
    (*node)    = new_node;
}

void delete_node(struct node **head_ref, int key)
{
    struct node* buff = *head_ref, *prev;
    if(buff != NULL && buff->value == key)
    {
        *head_ref = buff->next;
        free(buff);
        return;
    }

    while(buff != NULL && buff->value != key)
    {
        prev = buff;
        buff = buff->next;
    }

    if (buff == NULL) return;
    prev->next = buff->next;
    free(buff);
}

int main()
{
    struct node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    print_list(head);
    delete_node(&head, 2);
    printf("\nNew list: ");
    print_list(head);
    return 0;
}

