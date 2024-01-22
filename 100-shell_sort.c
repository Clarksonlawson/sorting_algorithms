#include "sort.h"

 void swap_element(int *elem1, int *elem2);

/**
 * shell_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space;
    	size_t i;
    	size_t j;

    	if (array == NULL || size < 2)
	{
		return;
	}
	for (space = 1; space < (size / 3);)
	{
		space = space * 3 + 1;
	}
	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				swap_element(array + j, array + (j - space));
                		j -= space;
			}
		}
		print_array(array, size);
	}
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
