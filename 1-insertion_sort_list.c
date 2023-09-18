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
	if (list == NULL || (*list)->next == NULL)
		return;
	listint_t *head = NULL;
	while (list != NULL)
	{
		listint_t *actuel = *list;
		*list = (*list)->next;
		if (head == NULL || actuel->n < head->n)
		{
			actuel->next = head;
			head = actuel;
		}
		else
		{
			listint_t *p = head;
			while (p != NULL)
			{
				if (p->next == NULL ||
				    actuel->n < p->next->n)
				{
					actuel->next = p->next;
					p->next = actuel;
					break;
				}
				p = p->next;
			}
		}
	}
}
