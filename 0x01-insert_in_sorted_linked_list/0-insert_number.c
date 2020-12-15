#include "lists.h"
/**
 * insert_node - inserts the node in a sorted linked list
 * @head: pointer to start of the linked list
 * @number: integer to be included
 *
 * Return: the address of the new node or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL, *current = NULL, *prev = NULL;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = number;
	current = *head;
	prev = NULL;
	while (current)
	{
		if (!prev && current->n > number)
		{
			new_node->next = current;
			*head = new_node;
			return (new_node);
		}
		else if (prev && current->n > number)
		{
			prev->next = new_node;
			new_node->next = current;
			return (new_node);
		}
		prev = current;
		current = current->next;
	}
	if (prev && !current)
		prev->next = new_node;
	else
		*head = new_node;
	new_node->next = NULL;
	return (new_node);
}
