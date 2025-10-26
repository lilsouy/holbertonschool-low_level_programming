#include "main.h"

/**
* _strcat - concatenates two strings
* @dest: destination string
* @src: source string
*
* Return: pointer to dest
*/
char *_strcat(char *dest, char *src)
{
int i, j;

/* find the end of dest */
for (i = 0; dest[i] != '\0'; i++)
;

/* append src to dest */
for (j = 0; src[j] != '\0'; j++)
{
dest[i] = src[j];
i++;
}

/* add the terminating null byte */
dest[i] = '\0';

return (dest);
}
