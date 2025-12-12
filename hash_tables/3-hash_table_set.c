#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * create_node - Creates a new hash node
 * @key: The key string
 * @value: The value string
 *
 * Return: Pointer to new node, or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;
	char *key_copy, *value_copy;

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (NULL);

	key_copy = strdup(key);
	if (key_copy == NULL)
	{
		free(value_copy);
		return (NULL);
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(key_copy);
		free(value_copy);
		return (NULL);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = NULL;

	return (new_node);
}

/**
 * update_existing_key - Updates value for existing key
 * @node: Node with existing key
 * @value_copy: New value copy
 * @key_copy: Key copy to free
 *
 * Return: 1 on success
 */
int update_existing_key(hash_node_t *node, char *value_copy, char *key_copy)
{
	free(node->value);
	node->value = value_copy;
	free(key_copy);
	return (1);
}

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
	hash_node_t *new_node = NULL, *temp = NULL;
	unsigned long int index;
	char *value_copy = NULL, *key_copy = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	/* Check if key already exists */
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);

			key_copy = strdup(key);
			if (key_copy == NULL)
			{
				free(value_copy);
				return (0);
			}

			return (update_existing_key(temp, value_copy, key_copy));
		}
		temp = temp->next;
	}

	/* Create new node for new key */
	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	/* Add new node at beginning of list */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
