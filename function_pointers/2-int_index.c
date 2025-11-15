#include "function_pointers.h"

/**
	* int_index - searches for an integer
	* @array: array of integers
	* @size: number of elements
	* @cmp: pointer to the comparing function
	*
	* Return: index of first match, -1 if none or size <= 0
	*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
	return (-1);

	for (i = 0; i < size; i++)
	{
	if (cmp(array[i]) != 0)
	return (i);
	}

	return (-1);
}

