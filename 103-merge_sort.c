#include "sort.h"

void recursive_sort(int *subArray, int *buffer, size_t frontIndex, size_t backIndex);
void merge_sort(int *array, size_t size);
void subArray_merger(int *subArray, int *buffer, size_t frontIndex, size_t midIndex,
                  size_t backIndex);

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

    	if (array == NULL || size < 2)
        	return;

    	if (( buffer = malloc(sizeof(int) * size)) == NULL)
        	return;

    	/**Recursive Sorting**/
    	recursive_sort(array, buffer, 0, size);

    	free(buffer);
}

/**
 * recursive_sort - Implement the merge sort algorithm through recursion.
 * @subArray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @frontIndex: The front index of the subarray.
 * @backIndex: The back index of the subarray.
 */
void recursive_sort(int *subArray, int *buffer, size_t frontIndex, size_t backIndex)
{
	size_t middle;

    	if (backIndex - frontIndex > 1)
    	{
        	middle = frontIndex + (backIndex - frontIndex) / 2;
        	recursive_sort(subArray, buffer, frontIndex, middle);
        	recursive_sort(subArray, buffer, middle, backIndex);
        	subArray_merger(subArray, buffer, frontIndex, middle, backIndex);
    	}
}

/**
 * subArray_merger - Sort a subarray of integers.
 * @subArray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @frontIndex: The front index of the array.
 * @midIndex: The middle index of the array.
 * @backIndex: The back index of the array.
 */
void subArray_merger(int *subArray, int *buffer, size_t frontIndex, size_t midIndex,
                  size_t backIndex)
{
	size_t i, j, k = 0;
	
    	printf("Merging...\n[left]: ");
    	print_array(subArray + frontIndex, midIndex - frontIndex);

    	printf("[right]: ");
    	print_array(subArray + midIndex, backIndex - midIndex);

    	for (i = frontIndex, j = midIndex; i < midIndex && j < backIndex; k++)
    	{
         	buffer[k] = (subArray[i] < subArray[j]) ? subArray[i++] : subArray[j++];
    	}
    	for (; i < midIndex; i++)
    	{
        	buffer[k++] = subArray[i];
    	}
    	for (; j < backIndex; j++)
    	{
         	buffer[k++] = subArray[j];
    	}
    	for (i = frontIndex, k = 0; i < backIndex; i++)
    	{
        	subArray[i] = buffer[k++];
    	}

    	printf("[Done]: ");
    	print_array(subArray + frontIndex, backIndex - frontIndex);
}
