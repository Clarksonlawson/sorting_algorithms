#include "sort.h"

void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void swap_element(int *elem1, int *elem2);
/**
 * heap_sort - using heapSort: Sort an array of integers in A-Z
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int index;

    	if (array == NULL || size < 2)
        	return;

    	for (index = (size / 2) - 1; index >= 0; index--)
    	{
        	heapify(array, size, size, index);
    	}


    	for (index = size - 1; index > 0; index--)
    	{
        	swap_element(array, array + index);
        	print_array(array, size);
        	heapify(array, size, index, 0);
    	}
}

/**
 * heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t baseIndex, size_t rootNode)
{
	size_t leftIndex;
    	size_t rightIndex;
    	size_t large;

    	leftIndex = 2 * rootNode + 1;
    	rightIndex = 2 * rootNode + 2;
    	large = rootNode;

    	if (leftIndex < baseIndex && array[leftIndex] > array[large])
    	{
        	large = leftIndex;
    	}
    	if (rightIndex < baseIndex && array[rightIndex] > array[large])
    	{
        	large = rightIndex;
    	}
    	if (large != rootNode)
    	{
        	swap_element(array + rootNode, array + large);
        	print_array(array, size);
        	heapify(array, size, baseIndex, large);
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
