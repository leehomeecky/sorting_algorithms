#include "sort.h"

void swap_list(listint_t **list, listint_t *val);

/**
 * swap_list - a function to swap a value into a lincked list
 * 
 * @list: pointer to the list to swap into
 * @val: value to swap
 */

void swap_list(listint_t **list, listint_t *val)
{	
			if (val->next)
			val->next->prev = val->prev;
			val->prev->next = val->next;
			val->next = val->prev;
			val->prev = val->prev->prev;
			val->next->prev = val;
		if (val->prev == NULL)
				*list = val;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *val, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	temp = (*list)->next;
	while (temp)
	{
		if (temp->prev->n < temp->n)
		{
			val = temp->next;
			if (val->next)
			val->next->prev = val->prev;
			val->prev->next = val->next;
			swap_list(list, val);
			print_list((const listint_t *)*list);
		}
		else
		temp = temp->next;
	}
}
