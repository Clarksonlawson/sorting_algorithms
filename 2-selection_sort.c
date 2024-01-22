#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

 void selection_sort(int *array, size_t size)
{
	int *minIndex;
     	size_t index, j;
     	int temp;

     	if (array == NULL || size < 2)
	{
		return;
	}
	for (index = 0; index < size - 1; index++)
	{
		minIndex = array + index;

         	for (j = index + 1; j < size; j++)
		{
			if(array[j] < *minIndex)
			{
				minIndex = array + j;
			}
			else
			{
				 minIndex = minIndex;
			}
			if ((array + index) != minIndex)
			{
				temp = *(array + index);
                 		*(array + index) = *minIndex;
                 		*minIndex = temp;

                 		print_array(array, size);
			}
		}
	}
}
