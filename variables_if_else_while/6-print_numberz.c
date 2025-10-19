#include <stdio.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		putchar(i + '0'); /* Convert int to ASCII digit */
	putchar('\n');        /* Print newline */

	return (0);
}
