#include "main.h"

/**
	* print_last_digit - prints the last digit of a number
	* @n: the number
	*
	* Return: value of the last digit
	*/
int print_last_digit(int n)
{
	int last_digit;

	last_digit = n % 10;

	/* Make last digit positive */
	if (last_digit < 0)
	last_digit = -last_digit;

	_putchar('0' + last_digit);

	return (last_digit);
}
