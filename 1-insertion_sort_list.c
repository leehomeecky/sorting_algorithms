#include "sort.h"

void swap_list(listint_t **list, listint_t **pos, listint_t *val);

/**
 * swap_list - a function to swap a value in a lincked list
 * 
 * @list: pointer to the list to swap into
 * @pos: position to swap
 * @val: value to swap
 */

void swap_list (listint_t **list, listint_t **pos, listint_t *val)
{
	listint_t *temp = *pos;

	temp->next = val->next;
	if (val->next != NULL)
		val->next->prev = temp;
	val->prev = temp->prev;
	val->next = temp;
	if (temp->prev != NULL)
		temp->prev->next = val;
	else
		*list = val;
	temp->prev = val;
	*pos = val->prev;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next_val, *tep2, *temp1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (next_val = (*list)->next; next_val != NULL; next_val = temp1)
	{
		temp1 = next_val->next;
		tep2 = next_val->prev;
		while (tep2 != NULL && next_val->n < tep2->n)
		{
			swap_list(list, &tep2, next_val);
			print_list(*list);
		}
	}
}
