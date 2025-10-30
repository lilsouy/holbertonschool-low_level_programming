#include "main.h"

/**
* _strstr - locates a substring
* @haystack: string to search in
* @needle: substring to find
*
* Return: pointer to the beginning of the located substring, or NULL
*/
char *_strstr(char *haystack, char *needle)
{
while (*haystack)
{
char *h = haystack;
char *n = needle;

while (*n && *h == *n)
{
h++;
n++;
}

if (*n == '\0')
return (haystack);

haystack++;
}

return (0);
}

