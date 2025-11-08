#include "dog.h"
#include <stdlib.h>

/**
	* _strlen - returns the length of a string
	* @s: string to measure
	* Return: length of string
	*/
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
	len++;
	return (len);
}

/**
	* _strcpy - copies a string
	* @dest: destination buffer
	* @src: source string
	* Return: pointer to dest
	*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
	* new_dog - creates a new dog
	* @name: name of the dog
	* @age: age of the dog
	* @owner: owner of the dog
	* Return: pointer to new dog_t, or NULL on failure
	*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new;
	int name_len, owner_len;

	if (name == NULL || owner == NULL)
	return (NULL);

	new = malloc(sizeof(dog_t));
	if (new == NULL)
	return (NULL);

	name_len = _strlen(name);
	owner_len = _strlen(owner);

	new->name = malloc(name_len + 1);
	if (new->name == NULL)
	{
	free(new);
	return (NULL);
	}
	_strcpy(new->name, name);

	new->owner = malloc(owner_len + 1);
	if (new->owner == NULL)
	{
	free(new->name);
	free(new);
	return (NULL);
	}
	_strcpy(new->owner, owner);

	new->age = age;
	return (new);
}

