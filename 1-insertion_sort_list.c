#include "sort.h"

/**
 * nodes_swap - swaps two nodes in a doubly linked list
 * @head: ptr to the head of the doubly linked list
 * @n1: ptr to the first node
 * @n2: ptr to the second node
 *
 * Return: void
 */

void nodes_swap(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts list in ascending order using Insertion sort
 * @list: doubly linked list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *insert, *temp;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	for (iterate = (*list)->next; iterate != NULL; iterate = temp)
	{
		temp = iterate->next;
		insert = iterate->prev;

		while (insert != NULL && iterate->n < insert->n)
		{
			nodes_swap(list, &insert, iterate);
			print_list((const listint_t *)*list);
		}
	}
}
