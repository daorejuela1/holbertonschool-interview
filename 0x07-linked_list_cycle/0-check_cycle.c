#include "lists.h"

/**
 * check_cycle - checks if a linked list contains a cycle
 * @list: header of the linked list
 *
 * Return: 1 if there is a cycle 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise, *hare;

	if (!list)
		return (0);
	tortoise = list;
	hare = list;
	while (1)
	{
		if (!tortoise->next)
			return (0);
		tortoise = tortoise->next;
		if (!hare->next || !hare->next->next)
			return (0);
		hare = hare->next->next;
		if (hare == tortoise)
			return (1);
	}
	return (0);
}
