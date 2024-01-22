#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_ahead(listint_t **list, listint_t **tail, listint_t **wobbler);
void swap_behind(listint_t **list, listint_t **tail, listint_t **wobbler);
 void swap_element(int *elem1, int *elem2);

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail;
    	listint_t *wobble;

	bool is_shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (tail = *list; tail->next != NULL;)
	{
		tail = tail->next;
	}
	while (!is_shaken)
	{
		is_shaken = true;
		for (wobble = *list; wobble != tail; wobble = wobble->next)
		{
			if (wobble->n > wobble->next->n)
			{
				swap_ahead(list, &tail, &wobble);
				print_list((const listint_t *)*list);
				is_shaken = false;
			}
		}
		for (wobble = wobble->prev; wobble != *list;
			 wobble = wobble->prev)
		{
			if (wobble->n < wobble->prev->n)
			{
				swap_behind(list, &tail, &wobble);
				print_list((const listint_t *)*list);
				is_shaken = false;
			}
		}
	}
}

/**
 * swap_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @wobbler: A pointer to the current swapping node
 */

void swap_ahead(listint_t **list, listint_t **tail, listint_t **wobbler)
{
	listint_t *temp = (*wobbler)->next;

	if ((*wobbler)->prev != NULL)
	{
		(*wobbler)->prev->next = temp;
	}
	else
	{
		*list = temp;
	}
	temp->prev = (*wobbler)->prev;
	(*wobbler)->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = *wobbler;
	}
	else
	{
		*tail = *wobbler;
	}
	(*wobbler)->prev = temp;
	temp->next = *wobbler;
	*wobbler = temp;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @wobbler: A pointer to the current swapping node.
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **wobbler)
{
	listint_t *temp = (*wobbler)->prev;

   	if ((*wobbler)->next != NULL)
	{
		(*wobbler)->next->prev = temp;
	}
	else
	{
		 *tail = temp;
	}
	temp->next = (*wobbler)->next;
    	(*wobbler)->prev = temp->prev;

    	if (temp->prev != NULL)
	{
		 temp->prev->next = *wobbler;
	}
	else
	{
		*list = *wobbler;
	}
	(*wobbler)->next = temp;
	temp->prev = *wobbler;
	*wobbler = temp;
}
