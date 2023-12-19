#include "sort.h"

/**
 * swap_int - swaps two integers
 * @a: first int to swap
 * @b: second int to swap
 *
 * return: void
 */

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts array of int in ascending order using Selection sort
 * @array: an array to be sorted
 * @size: size of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, min_i;

	for (a = 0; a < size - 1; a++)
	{
		min_i = a;
		for (b = a + 1; b < size; b++)
			if (array[b] < array[min_i])
				min_i = b;

		if (min_i != a)
		{
			swap_int(&array[min_i], &array[a]);
			print_array(array, size);
		}
	}
}
