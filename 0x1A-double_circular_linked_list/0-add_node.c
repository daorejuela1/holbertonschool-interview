#include "list.h"

/**
 * create_node - creates a new list node
 * @str: string to insert in the node
 *
 * Return: new node or null if not found
 */
static List *create_node(char *str)
{
	List *new_node = NULL;

	if (!str)
		return (NULL);
	new_node = malloc(sizeof(new_node));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->prev = new_node->next = NULL;
	return (new_node);
}


/**
 * add_node_end - adds a node to the end of a dbl list
 * @list: list to modify
 * @str: string to copy
 *
 * Return: address of the new node or null on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL, *tail = NULL, *head = NULL;

	new_node = create_node(str);
	if (!new_node)
		return (NULL);
	if (!*list)
	{
		new_node->prev = new_node->next = new_node;
		*list = new_node;
		return (new_node);
	}

	head = *list;
	tail = head->prev;
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = head;
	head->prev = new_node;
	return (new_node);
}

/**
 * add_node_begin - adds a node to the begin of a dbl list
 * @list: list to modify
 * @str: string to copy
 *
 * Return: address of the new node or null on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = NULL, *tail = NULL, *head = NULL;

	new_node = create_node(str);
	if (!new_node)
		return (NULL);
	if (!*list)
	{
		new_node->prev = new_node->next = new_node;
		*list = new_node;
		return (new_node);
	}

	head = *list;
	tail = head->prev;
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = head;
	head->prev = new_node;
	*list = new_node;
	return (new_node);
}
