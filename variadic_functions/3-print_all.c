#include <stdio.h>
#include "variadic_functions.h"

/**
	* print_all - prints anything
	* @format: list of types of arguments passed to the function
	*/
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str;
	char *sep = "";
	char c;

	va_start(args, format);

	if (format) /* IF #1 */
	{
	while (format[i]) /* LOOP #1 */
	{
	c = format[i];

	switch (c)
	{
	case 'c':
	printf("%s%c", sep, va_arg(args, int));
	sep = ", ";
	break;

	case 'i':
	printf("%s%d", sep, va_arg(args, int));
	sep = ", ";
	break;

	case 'f':
	printf("%s%f", sep, (double)va_arg(args, double));
	sep = ", ";
	break;

	case 's':
	str = va_arg(args, char *);
	if (!str) /* IF #2 */
	str = "(nil)";
	printf("%s%s", sep, str);
	sep = ", ";
	break;

	default:
	i++;
	continue;
	}

	i++;
	}
	}

	va_end(args);
	printf("\n");
}

