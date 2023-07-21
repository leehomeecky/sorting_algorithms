#include "sort.h"
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1,
		listint_t *node2);
/**
 * swap_nodes - swapping nodes
 * @node1: first node
 * @node2: Second node
 * @list: list
 * @pos: pos
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

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		while (start->next != NULL)/* Forward pass (bubble sort)*/
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
			start = start->next;
			}
		}
		if (!swapped)/* If no swaps occurred, the list is sorted*/
			break;
		swapped = 0;
		/* Mark the end of the sorted portion*/
		/* Backward pass (bubble sort)*/
		while (start->prev != NULL)/* Backward pass (bubble sort)*/
		{
			if ((start->n < start->prev->n))
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
				print_list(*list);
			}
			else
			{
			start = start->prev;
			}
		}
	}
}

