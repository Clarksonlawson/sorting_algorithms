#include "sort.h"

void swap_elements(listint_t **head, listint_t **elem1, listint_t *elem2);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator;
	listint_t *insert;
    	listint_t *temp;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (iterator = (*list)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
        	insert = iterator->prev;

		while (insert != NULL && iterator->n < insert->n)
		{
			swap_elements(list, &insert, iterator);
           		print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_elements - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @elem1: A pointer to the first node to swap.
 * @elem2: The second node to swap.
 */

void swap_elements(listint_t **head, listint_t **elem1, listint_t *elem2)
{
	(*elem1)->next = elem2->next;
    	if (elem2->next != NULL)
	{
		elem2->next->prev = *elem1;
	}
	elem2->prev = (*elem1)->prev;
    	elem2->next = *elem1;
    	if ((*elem1)->prev != NULL)
	{
		(*elem1)->prev->next = elem2;
	}
	else
	{
		*head = elem2;
	}
	(*elem1)->prev = elem2;
    	*elem1 = elem2->prev;
}
