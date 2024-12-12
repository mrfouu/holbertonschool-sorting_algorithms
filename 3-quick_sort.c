#include "sort.h"
#include <stdio.h>
/**
 * swap - Swaps two elements in an array.
 * @arr: The array.
 * @i: Index of the first element.
 * @j: Index of the second element.
 */
void swap(int *arr, size_t i, size_t j)
{
	int temp = arr[i];

	arr[i] = arr[j];
	arr[j] = temp;
}
/**
 * partition - Partitions the array using the Lomuto scheme.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition (pivot).
 * @size: The total size of the array (for printing).
 *
 * Return: The index of the pivot after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_sort_recursive - Recursively applies Quick Sort to partitions.
 * @array: The array to sort.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The total size of the array (for printing).
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to sort.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
