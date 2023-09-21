#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 *  sort algorithm, using the Knuth sequence
 * @array:pointer on array's adress
 * @size: size of array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t intervalle = 1;
	int temp;
	size_t j, i;

	if (array == NULL || size < 2)
		return;

	while (intervalle < size / 3)
	{
		intervalle = intervalle * 3 + 1;
	}

	while (intervalle > 0)
	{
		for (i = intervalle; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= intervalle && array[j - intervalle]
			 > temp; j -= intervalle)
			{
				array[j] = array[j - intervalle];
			}
			array[j] = temp;
		}

		intervalle /= 3;

		for (i = 0; i < size; i++)
		{
			if (i > 0)
			printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");
	}
}
