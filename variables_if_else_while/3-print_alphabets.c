#include <stdio.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char letter;

	/* Print lowercase letters */
	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	/* Print uppercase letters */
	for (letter = 'A'; letter <= 'Z'; letter++)
		putchar(letter);
	putchar('\n');

	return (0);
}
