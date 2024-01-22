#include "sort.h"


void counting_sort(int *array, size_t size);
/**
 * counting_sort - Sort array using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *counter;
    	int *sort;
    	int maximum;
    	int index;

    	if (array == NULL || size < 2)
	{
		return;
	}
	if ((sort = malloc(sizeof(int) * size)) == NULL)
	{
		return;
	}
	/**Getting the Maximum**/
    	maximum = find_maximum(array, size);
	if ((counter = malloc(sizeof(int) * (maximum + 1))) == NULL)
	{
		free(sort);
        	return;
	}
	for (index = 0; index < (maximum + 1); index++)
	{
		counter[index] = 0;
	}
	for (index = 0; index < (int)size; index++)
	{
		 counter[array[index]] += 1;
	}
	for (index = 0; index < (maximum + 1); index++)
    	{
         	counter[index] += counter[index - 1];
    	}
    	print_array(counter, maximum + 1);

    	for (index = 0; index < (int)size; index++)
    	{	
        	sort[counter[array[index]] - 1] = array[index];
        	counter[array[index]] -= 1;
    	}

    	for (index = 0; index < (int)size; index++)
	{
		array[index] = sort[index];
	}
	free(sort);
    	free(counter);
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
