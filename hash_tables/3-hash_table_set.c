#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
	* hash_table_set - Adds an element to the hash table
	* @ht: The hash table to add/update the key/value to
	* @key: The key (cannot be empty string)
	* @value: The value associated with the key (must be duplicated)
	*
	* Return: 1 if succeeded, 0 otherwise
	*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new, *temp;
	unsigned long int idx;
	char *val_copy, *key_copy;

	if (!ht || !key || !*key || !value)
		return (0);

	val_copy = strdup(value);
	if (!val_copy)
		return (0);

	key_copy = strdup(key);
	if (!key_copy)
	{
		free(val_copy);
		return (0);
	}

	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];

	while (temp)
	{
		if (!strcmp(temp->key, key))
		{
			free(temp->value);
			temp->value = val_copy;
			free(key_copy);
			return (1);
		}
		temp = temp->next;
	}

	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		free(val_copy);
		free(key_copy);
		return (0);
	}

	new->key = key_copy;
	new->value = val_copy;
	new->next = ht->array[idx];
	ht->array[idx] = new;

	return (1);
}
