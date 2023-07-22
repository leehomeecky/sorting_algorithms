#include "sort.h"

void insert(listint_t **list, listint_t *val);

/**
 * insert - a function to insert a value into a lincked list
 * 
 * @list: pointer to the list to insert into
 * @val: value to insert
 */

void insert(listint_t **list, listint_t *val)
{
	listint_t *temp = *list;
	
	while (temp)
	{
		if (temp->n > val->n)
		{
			val->prev = temp->prev;
			val->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = val;
			else
				*list = val;
			temp->prev = val;
			return;
		}
		else if (temp->next == NULL)
		{
			val->prev = temp;
			val->next = temp->next;
			temp->next = val;
			return;
		}
		temp = temp->next;
	}

}

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *val, *temp = *list;

	while (temp->next)
	{
		if (temp->next->n < temp->n)
		{
			val = temp->next;
			if (val->next)
			val->next->prev = val->prev;
			val->prev->next = val->next;
			insert(list, val);
			print_list(*list);
		}
		else
		temp = temp->next;
	}
}
