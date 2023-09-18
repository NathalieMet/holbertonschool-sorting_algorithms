#include "sort.h"
#include <stdio.h>

/**
 * swap - swap two integers
 * @a: integer 1
 * @b: integer 2
 * Return: nothing
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - selects the last element (array[high]) as the pivot, then
 *  rearranges the array so that elements smaller than the pivot are to the
 *  left of the pivot and larger elements are to the right.
 * @array: pointer on array's adress
 * @low: the lowest value
 * @high: the highest value
 * @size: size of array
 * Return: index of pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 *  sort algorithm
 * @array: pointer on array's adress
 * @size: size of array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - main recursive function for sorting a portion of an array
 * @array: pointer on array's adress
 * @low: the lowest value
 * @high: the highest value
 * @size: size of array
 * Return: nothing
 */

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);


		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}
