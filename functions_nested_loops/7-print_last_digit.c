#include "main.h"

/**
	* print_last_digit - prints last digit
	* @n: number
	*
	* Return: last digit
	*/
int print_last_digit(int n)
{
	int ld;

	ld = _abs(n % 10);
	_putchar('0' + ld);
	return (ld);
}
