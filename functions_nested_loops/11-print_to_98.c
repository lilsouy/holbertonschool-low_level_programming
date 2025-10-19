#include "main.h"
#include <stdio.h>

/**
	* print_to_98 - prints natural numbers from n to 98
	* @n: start
	*/
void print_to_98(int n)
{
	if (n <= 98)
	{
	while (n < 98)
	printf("%d, ", n++);
	printf("98\n");
	}
	else
	{
	while (n > 98)
	printf("%d, ", n--);
	printf("98\n");
	}
}
