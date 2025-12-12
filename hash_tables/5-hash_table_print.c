#include <stdio.h>
#include "hash_tables.h"

/**
	* hash_table_print - Prints a hash table
	* @ht: The hash table to print
	*
	* Description: Prints key/value pairs in the order they appear in the array
	* Format: {'key': 'value', 'key2': 'value2', ...}
	* If ht is NULL, don't print anything
	*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	int first = 1; /* Flag to track first element for comma placement */

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			first = 0;
			node = node->next;
		}
	}
	printf("}\n");
}
