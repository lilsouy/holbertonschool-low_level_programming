#include <stdlib.h>
#include "lists.h"

/**
	* insert_dnodeint_at_index - inserts a new node at a given index
	* @h: pointer to pointer to the head of the list
	* @idx: index where the new node should be inserted (starting at 0)
	* @n: value to insert
	*
	* Return: address of the new node, or NULL if it failed
	*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i = 0;

	if (h == NULL)
	return (NULL);

	/* Insert at head */
	if (idx == 0)
	return (add_dnodeint(h, n));

	current = *h;

	while (current != NULL)
	{
	if (i == idx - 1)
	{
	/* Insert at end */
	if (current->next == NULL)
	return (add_dnodeint_end(h, n));

	/* Insert in the middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;

	current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
	}

	current = current->next;
	i++;
	}

	/* Index out of bounds */
	return (NULL);
}

