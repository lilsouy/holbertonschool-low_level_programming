#include "main.h"

/**
	* puts_half - prints half of a string, followed by a new line
	* @str: pointer to the string
	*
	* Return: void
	*/
void puts_half(char *str)
{
	int length = 0, n;

	while (str[length] != '\0')
	{
	length++;
	}

	if (length % 2 == 0)
	n = length / 2;
	else
	n = (length - 1) / 2 + 1;

	while (str[n] != '\0')
	{
	_putchar(str[n]);
	n++;
	}
	_putchar('\n');
}

