#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: array to sort
 * @size: size of array to sort
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, bubble = 1;

	if (size < 2)
		return;
	while (bubble)
	{
		bubble = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[(i + 1)])
			{
				temp = array[i];
				array[i] = array[(i + 1)];
				array[(i + 1)] = temp;
				print_array(array, size);
				bubble = 1;
			}
		}
	}
}
