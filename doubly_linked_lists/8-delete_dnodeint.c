#include "lists.h"
#include <stdlib.h>

/**
	* delete_dnodeint_at_index - deletes the node at a given index
	* @head: pointer to pointer to the head of the linked list
	* @index: index of the node to delete (starting at 0)
	*
	* Return: 1 if it succeeded, -1 if it failed
	*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Delete head node */
	if (index == 0)
	{
		*head = current->next;

		if (current->next != NULL)
			current->next->prev = NULL;

		free(current);
		return (1);
	}

	while (current != NULL)
	{
		if (i == index)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			free(current);
			return (1);
		}

		current = current->next;
		i++;
	}

	/* Index out of range */
	return (-1);
}

