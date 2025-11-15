#include "variadic_functions.h"
#include <stdio.h>

/**
	* print_arg - prints a single argument based on format type
	* @c: type specifier
	* @args: va_list
	* @sep: separator string
	*/
void print_arg(char c, va_list args, char **sep)
{
	char *str;

	switch (c)
	{
	case 'c':
		printf("%s%c", *sep, va_arg(args, int));
		*sep = ", ";
		break;
	case 'i':
		printf("%s%d", *sep, va_arg(args, int));
		*sep = ", ";
		break;
	case 'f':
		printf("%s%f", *sep, (double)va_arg(args, double));
		*sep = ", ";
		break;
	case 's':
		str = va_arg(args, char *);
		if (!str)
			str = "(nil)";
		printf("%s%s", *sep, str);
		*sep = ", ";
		break;
	}
}

/**
	* print_all - prints anything
	* @format: list of types of arguments passed to the function
	*/
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *sep = "";

	va_start(args, format);

	if (format)
	{
		while (format[i])
		{
			print_arg(format[i], args, &sep);
			i++;
		}
	}

	va_end(args);
	printf("\n");
}

