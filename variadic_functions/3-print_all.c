#include <stdio.h>
#include "variadic_functions.h"

/**
	* print_all - prints anything
	* @format: format list of types of arguments
	*/
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str;
	char *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
	if (format[i] == 'c')
	{
	printf("%s%c", sep, va_arg(args, int));
	}
	else if (format[i] == 'i')
	{
	printf("%s%d", sep, va_arg(args, int));
	}
	else if (format[i] == 'f')
	{
	printf("%s%f", sep, (double)va_arg(args, double));
	}
	else if (format[i] == 's')
	{
	str = va_arg(args, char *);
	if (str == NULL)
	str = "(nil)";
	printf("%s%s", sep, str);
	}
	else
	{
	i++;
	continue;
	}

	sep = ", ";
	i++;
	}

	va_end(args);
	printf("\n");
}

