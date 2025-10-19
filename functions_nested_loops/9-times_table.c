#include "main.h"

/**
	* times_table - prints 9 times table
	*/
void times_table(void)
{
	int i, j, prod;

	for (i = 0; i <= 9; i++)
	{
	for (j = 0; j <= 9; j++)
	{
	prod = i * j;
	if (j != 0)
	_putchar(',');
	_putchar(' ');
	if (prod >= 10)
	{
	_putchar('0' + prod / 10);
	_putchar('0' + prod % 10);
	}
	else
	_putchar('0' + prod);
	}
	_putchar('\n');
	}
}
