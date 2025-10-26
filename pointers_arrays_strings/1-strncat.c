#include "main.h"

/**
* _strncat - concatenates two strings, using at most n bytes from src
* @dest: destination string
* @src: source string
* @n: maximum number of bytes to use from src
*
* Return: pointer to dest
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;

/* find end of dest */
for (i = 0; dest[i] != '\0'; i++)
;

/* append at most n characters from src */
for (j = 0; j < n && src[j] != '\0'; j++)
{
dest[i] = src[j];
i++;
}

/* add terminating null byte */
dest[i] = '\0';

return (dest);
}

