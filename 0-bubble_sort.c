#include "sort.h"
/**
 * swap - A function to swap two values in an array.
 * @arr: Pointer to the array containing the values to swap.
 * @i: Index of the first value.
 * @j: Index of the second value.
 */
void swap(int *arr, size_t i, size_t j)
{
	int tmp = arr[i];

	arr[i] = arr[j];
	arr[j] = tmp;
}
/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: pointer to the array of integer
 * @size: number of byte size of the entire array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
			}
		}
	}
}
