#include "sort.h"

void swap_element(int *elem1, int *elem2);
void d_lomuto_sort(int *array, size_t size, int startIndex, int endIndex);
void quick_sort(int *array, size_t size);
int lomuto_partitioning(int *array, size_t size, int startIndex, int endIndex);

/**
 * quick_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 */

 void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	d_lomuto_sort(array, size, 0, size - 1);
}

/**
 * d_lomuto_sort - Uses the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @startIndex: Starting index of the array.
 * @endIndex: Ending index of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 */
 void d_lomuto_sort(int *array, size_t size, int startIndex, int endIndex)
{
	int partition;

     	if (endIndex - startIndex > 0)
	{
		partition = lomuto_partitioning(array, size, startIndex, endIndex);
         	d_lomuto_sort(array, size, startIndex, partition - 1);
         	d_lomuto_sort(array, size, partition + 1, endIndex);
	}
}

 /**
 * lomuto_partitioning - Order a subset of an array of integers according to lomuto
 * @array: The array of integers.
 * @size: The size of the array.
 * @startIndex: The starting index of the subset to order.
 * @endIndex: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partitioning(int *array, size_t size, int startIndex, int endIndex)
{
	int *pivotal, down, up;

    	pivotal = array + endIndex;
    	for (up = down = startIndex; down < endIndex; down++)
	{
		if (array[down] < *pivotal)
		{
			if (up < down)
			{
				/**Swap & Print**/
                		swap_element(array + down, array + up);
                		print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivotal)
	{
		/**Swap & Print **/
        	swap_element(array + up, pivotal);
        	print_array(array, size);
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
