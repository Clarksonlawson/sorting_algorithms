#include "sort.h"

void swap_element(int *elem1, int *elem2);
int h_partition(int *array, size_t size, int startIndex, int endIndex);
void h_sort(int *array, size_t size, int startIndex, int endIndex);

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
        	return;

    	h_sort(array, size, 0, size - 1);
}

/**
 * h_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @startIndex: The starting index of the array partition to order.
 * @endIndex: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void h_sort(int *array, size_t size, int startIndex, int endIndex)
{
	int partition;

    	if (endIndex - startIndex > 0)
    	{
        	partition = h_partition(array, size, startIndex, endIndex);
        	h_sort(array, size, startIndex, partition - 1);
        	h_sort(array, size, partition, endIndex);
    	}
}

/**
 * h_partition - Order a subset of an array of integers
 * @array: The array of integers.
 * @size: The size of the array.
 * @startIndex: The starting index of the subset to order.
 * @endIndex: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 */

int h_partition(int *array, size_t size, int startIndex, int endIndex)
{
	int pivotal;
    	int up;
    	int down;

    	pivotal = array[endIndex];
    	for (up = startIndex - 1, down = endIndex + 1; up < down;)
    	{
        	do
        	{
            		up++;
        	}
        	while (array[up] < pivotal);
        	do
        	{
            		down--;
        	} 
		while (array[down] > pivotal);

        	if (up < down)
        	{
            		swap_element(array + up, array + down);
            		print_array(array, size);
        	}
    	}

    	return (up);
}

/**
 * swap_element - Swap two integers in an array.
 * @elem1: The first integer to swap.
 * @elem2: The second integer to swap.
 */

 void swap_element(int *elem1, int *elem2)
 {
	 int temp;
     	 temp = *elem1;
     	 *elem1 = *elem2;
     	 *elem2 = temp;
 }
