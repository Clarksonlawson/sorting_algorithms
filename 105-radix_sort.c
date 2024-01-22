#include "sort.h"
void radix_counting(int *array, size_t size, int sign, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int maximum;
    	int sign;
    	int *buffer;

    	if (array == NULL || size < 2)
        	return;

    	if ((buffer = malloc(sizeof(int) * size)) == NULL)
        	return;

   	maximum = find_maximum(array, size);

    	for (sign = 1; maximum / sign > 0; sign *= 10)
    	{
        	radix_counting(array, size, sign, buffer);
        	print_array(array, size);
    	}

    	free(buffer);
}

/**
 * radix_counting - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting(int *array, size_t size, int sign, int *buffer)
{
	int countArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    	size_t index;

    	for (index = 0; index < size; index++)
   	{	
        	countArray[(array[index] / sign) % 10] += 1;
    	}

    	for (index = 0; index < 10; index++)
        	countArray[index] += countArray[index - 1];

    	for (index = size - 1; (int)index >= 0; index--)
    	{
        	buffer[countArray[(array[index] / sign) % 10] - 1] = array[index];
        	countArray[(array[index] / sign) % 10] -= 1;
    	}

   	for (index = 0; index < size; index++)
    	{
        	array[index] = buffer[index];
    	}
}

/**
 * find_maximum - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_maximum(int *array, int size)
{
	int maximum;
    	int index;

    	for (maximum = array[0], index = 1; index < size; index++)
    	{
        	if (array[index] > maximum)
            		maximum = array[index];
    	}

    	return (maximum);
}
