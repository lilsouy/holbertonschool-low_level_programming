#include "main.h"
#include <stdlib.h>

/**
	* str_concat - concatenates two strings
	* and returns a pointer to a newly allocated space in memory
	* which contains the contents of s1 followed by the contents of s2
	* @s1: first string
	* @s2: second string
	*
	* Return: pointer to newly allocated space containing s1, then s2,
	* or NULL on failure
	*/
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	concat = malloc((len1 + len2 + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];
	for (j = 0; j < len2; j++)
		concat[i + j] = s2[j];
	concat[i + j] = '\0';

	return (concat);
}

