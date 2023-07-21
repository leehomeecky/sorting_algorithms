#include "sort.h"
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1,
		listint_t *node2);
/**
 * swap_nodes - swapping nodes
 * @node1: first node
 * @node2: Second node
 * @list: list
 * Return: Current swapped node
 */
void swap_nodes(listint_t **list, listint_t *node1,
		listint_t *node2)
{
	listint_t *first = node1;
	listint_t *second = node2;

	/*Update next and prev pointers of adjacent nodes */
	if (first->prev != NULL)
		first->prev->next = second;
	else
		*list = second;

	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;

	if (second->next != NULL)
		second->next->prev = first;

	second->next = first;
	/*innernode = second;*/
}
/**
 * cocktail_sort_list - sorting
 * @list: list
 * Return: return all
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		/* Forward pass (bubble sort) */
		current = start;
		while (current->next != NULL)
		{
			if (current->next->n < current->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		/* Backward pass (bubble sort) */
		current = current->prev; /* Move to the last node in the list */
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
	}
}

