#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: pointer on array's adress
 * @size: size of array
 * Return: nothing
 */

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, int low, int high)
{
	int pivot = array[high]; // Choose the last element as the pivot
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return i + 1;
}

void quick_sort(int *array, size_t size)
{
	// Initial call to the recursive quicksort function
	quicksort(array, 0, size - 1, size);

}

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		// Sort the two partitions
		quicksort(array, low, pivot - 1, size);  // Left side of pivot
		quicksort(array, pivot + 1, high,); // Right side of pivot
	}
	print_array(array, size);
}

