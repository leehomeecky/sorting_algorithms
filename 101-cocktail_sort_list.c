#include "sort.h"
#include <stdbool.h>
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
void swap(listint_t **list, listint_t *node)
{
    node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
    else
        *list = node->next;
    node->prev = node->next;
    node->next = node->next->next;
    node->prev->next = node;
    if (node->next)
        node->next->prev = node;
}
/**
 * cocktail_sort_list - sorting
 * @list: list
 * Return: return all
 */
void cocktail_sort_list(listint_t **list)
{
    bool swapped = true;
    listint_t *start = *list;
    listint_t *end;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = false;
        end = start;

        /* Forward pass (bubble sort) */
        while (end->next != NULL)
        {
            if (end->next->n < end->n)
            {
                swap(list, end);
                swapped = true;
                print_list(*list);
            }
            else
            {
                end = end->next;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        /* Backward pass (bubble sort) */
        while (end->prev != NULL)
        {
            if (end->prev->n > end->n)
            {
                swap(list, end->prev);
                swapped = true;
                print_list(*list);
            }
            else
            {
                end = end->prev;
            }
        }
    }
}
