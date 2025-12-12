#include <stdlib.h>
#include "hash_tables.h"

/**
	* hash_table_delete - Deletes a hash table
	* @ht: The hash table to delete
	*
	* Description: Frees all memory allocated for the hash table including
	* all nodes, keys, values, the array, and the table structure itself.
	*/
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	/* Free each bucket's linked list */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node->next;
			free(node->key);    /* Free the key string */
			free(node->value);  /* Free the value string */
			free(node);         /* Free the node itself */
			node = temp;
		}
	}

	/* Free the array of pointers */
	free(ht->array);

	/* Free the hash table structure */
	free(ht);
}
