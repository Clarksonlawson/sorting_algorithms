 #include "sort.h"
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
