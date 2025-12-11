#include "hash_tables.h"

/**
	* create_new_node - Creates a new hash node
	* @key: The key string
	* @value: The value string
	*
	* Return: Pointer to the new node, or NULL on failure
	*/
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));
	
	if (new_node == NULL)
	return (NULL);
	
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
	free(new_node);
	return (NULL);
	}
	
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
	free(new_node->key);
	free(new_node);
	return (NULL);
	}
	
	new_node->next = NULL;
	return (new_node);
}

/**
	* hash_table_set - Adds or updates an element in the hash table
	* @ht: The hash table to add/update the key/value to
	* @key: The key (cannot be an empty string)
	* @value: The value associated with the key (must be duplicated)
	*
	* Return: 1 if succeeded, 0 otherwise
	*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;
	
	/* Check for invalid parameters */
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	return (0);
	
	/* Get the index for this key */
	index = key_index((const unsigned char *)key, ht->size);
	
	/* Check if key already exists in the chain */
	current = ht->array[index];
	while (current != NULL)
	{
	if (strcmp(current->key, key) == 0)
	{
	/* Key exists, update the value */
	free(current->value);
	current->value = strdup(value);
	if (current->value == NULL)
	return (0);
	return (1);
	}
	current = current->next;
	}
	
	/* Key doesn't exist, create new node */
	new_node = create_new_node(key, value);
	if (new_node == NULL)
	return (0);
	
	/* Add new node at the beginning of the chain (collision handling) */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	
	return (1);
}
