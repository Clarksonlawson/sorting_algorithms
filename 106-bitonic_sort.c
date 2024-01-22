#include "sort.h"

void swap_element(int *elem1, int *elem2);
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t startIndex, size_t sequence,
		char direction);

/**
 * bitonic_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @startIndex: The starting index of a block of the building bitonic sequence.
 * @sequence: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block in.
 */
void bitonic_sequence(int *array, size_t size, size_t startIndex, size_t sequence, char direction)
{
	size_t sequenceCut = sequence / 2;
	char *flowDir = (direction == UP) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, flowDir);
		print_array(array + startIndex, sequence);

		bitonic_sequence(array, size, startIndex, sequenceCut, UP);
		bitonic_sequence(array, size, startIndex + sequenceCut, sequenceCut, DOWN);
		bitonic_merge(array, size, startIndex, sequence, direction);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, flowDir);
		print_array(array + startIndex, sequence);
	}
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @startIndex: The starting index of the sequence in array to sort.
 * @sequence: The size of the sequence to sort.
 * @direction: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t startIndex, size_t sequence,
		char direction)
{
	size_t i;
	size_t jumpSequence = sequence / 2;

	if (sequence > 1)
	{
		for (i = startIndex; i < startIndex + jumpSequence; i++)
		{
			if ((direction == UP && array[i] > array[i + jumpSequence]) ||
			    (direction == DOWN && array[i] < array[i + jumpSequence]))
				swap_element(array + i, array + i + jumpSequence);
		}
		bitonic_merge(array, size, startIndex, jumpSequence, direction);
		bitonic_merge(array, size, startIndex + jumpSequence, jumpSequence, direction);
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
