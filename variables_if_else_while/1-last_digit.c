#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
	* main - Entry point of the program
	*
	* Return: Always 0
	*/
int main(void)
{
	int n, lastdigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastdigit = n % 10;

	if (last_digit < 0)
	last_digit = -last_digit;

	printf("Last digit of %d is %d", n, last_digit);

	if (lastdigit > 5)
	{
	printf(" and is greater than 5\n");
	}
	else if (lastdigit == 0)
	{
	printf(" and is 0\n");
	}
	else
	{
	printf(" and is less than 6 and not 0\n");
	}

	return (0);
}
