#include "lists.h"
/**
 * rec_palindrome - recursive function to check the address of the palindrome
 * @head: starting address of the linked list
 * @rev: same address than head but its analyzed in reverse
 * @activated: status flag to know if a mismatch has been found
 *
 * Return: 1 if is a palindrome 0 otherwise
 */
static int rec_palindrome(listint_t **head, listint_t *rev, int *activated)
{
	if (!rev)
		return (1);
	rec_palindrome(head, rev->next, activated);
	if (rev->n == (*head)->n && *activated)
	{
		(*head) = (*head)->next;
		return (1);
	}
	*activated = 0;
	return (0);
}
/**
 * is_palindrome - this function checks if a linked list is a palindrome
 * @head: address of the start of the single linked list
 *
 * Return: 1 if is a palindrome 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	int activated = 1;
	listint_t *current = NULL, *rev = NULL;

	if (!head || !*head)
		return (1);
	current = rev = *head;
	return (rec_palindrome(&current, rev, &activated));
}
