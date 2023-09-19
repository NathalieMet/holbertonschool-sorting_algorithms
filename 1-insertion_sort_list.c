#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *  order using the Insertion sort algorithm
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

	listint_t *head = NULL, *next = NULL;
	listint_t *actual = *list;

	while (actual != NULL)
	{
		 next = actual->next;

        if (head == NULL || actual->n < head->n)
        {
            actual->next = head;
            actual->prev = NULL;

            if (head != NULL)
                head->prev = actual;
            head = actual;
        }
		else
		{
            listint_t *temp = head;
            while (temp->next != NULL && actual->n > temp->next->n)
                temp = temp->next;

            actual->next = temp->next;
            actual->prev = temp;
			
            if (temp->next != NULL)
                temp->next->prev = actual;
            temp->next = actual;
        }
		if (actual->prev == NULL)
            *list = actual;

        print_list(head);
        actual = next;
    }
}