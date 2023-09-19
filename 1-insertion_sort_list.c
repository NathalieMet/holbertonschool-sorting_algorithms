#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL)
        return;

    listint_t *current = (*list)->next;
    
    while (current != NULL)
    {
        listint_t *temp = current->next;
        listint_t *prev = current->prev;
        
        while (prev != NULL && prev->n > current->n)
        {
            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;
            
            current->prev = prev->prev;
            current->next = prev;
            
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;
            
            prev->prev = current;
            
            prev = current->prev;
        }
        
        current = temp;
        
        print_list(*list);
    }
}
