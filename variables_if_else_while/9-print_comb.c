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
	{
		putchar(i + '0'); /* Print the number */
		if (i != 9)       /* Add comma and space except after the last number */
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n'); /* Print newline */

	return (0);
}
