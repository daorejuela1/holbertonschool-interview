#include "binary_trees.h"
heap_t *recursive_insert(heap_t *root, heap_t *new_node);
/**
 * heap_insert - inserts data conserving max heap logic
 * @root: root of the tree
 * @value: value to insert
 *
 * Return: Pointer to the inserted node or null if failed
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *actual_node = NULL;
	list_t *queue = NULL, *actual_queue;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);
	enqueue(&queue, *root);
	while (queue)
	{
		actual_queue = dequeue(&queue);
		actual_node = actual_queue->node;
		new_node->parent = actual_node;
		free(actual_queue);
		if (!actual_node->left)
		{
			actual_node->left = new_node;
			while (new_node->parent && new_node->n > new_node->parent->n)
				swap(new_node, new_node->parent);
			if (!new_node->parent)
				*root = new_node;
			break;
		}
		else if (!actual_node->right)
		{
			actual_node->right = new_node;
			while (new_node->parent && new_node->n > new_node->parent->n)
				swap(new_node, new_node->parent);
			if (!new_node->parent)
				*root = new_node;
			break;
		}
		else
		{
			enqueue(&queue, actual_node->left);
			enqueue(&queue, actual_node->right);
		}
	}
	free_queue(queue);
	return (new_node);
}

/**
 * enqueue - push data in the queue
 * @queue: queue pointer
 * @new_node: node to insert in the queue
 */
void enqueue(list_t **queue, heap_t *new_node)
{
	list_t *temporal = NULL, *new_queue = NULL;

	if (!(*queue))
	{
		*queue = malloc(sizeof(list_t));
		if (!(*queue))
			return;
		(*queue)->node = new_node;
		(*queue)->next = NULL;
		return;
	}
	new_queue = malloc(sizeof(list_t));
	if (!new_queue)
		return;
	new_queue->next = NULL;
	new_queue->node = new_node;
	temporal = *queue;
	while (temporal->next != NULL)
		temporal = temporal->next;
	temporal->next = new_queue;
}

/**
 * dequeue - pop data from the queue
 * @queue: queue pointer
 *
 * Return: Null or the first node of the queue
 */
list_t *dequeue(list_t **queue)
{
	list_t *temporal = NULL;

	temporal = *queue;
	*queue = (*queue)->next;
	return (temporal);
}

/**
 * swap - swaps two numeric values
 * @node: first node
 * @parent: second node
 */
void swap(heap_t *node, heap_t *parent)
{
	heap_t *left_temp = NULL, *right_temp = NULL;

	if (!node || !parent)
		return;
	left_temp = node->left;
	right_temp = node->right;

	if (parent->parent && parent->parent->left == parent)
		parent->parent->left = node;
	else if (parent->parent && parent->parent->right == parent)
		parent->parent->right = node;
	node->parent = parent->parent;
	if (parent->left == node)
	{
		node->left = parent;
		node->right = parent->right;
		if (node->right)
			node->right->parent = node;
	}
	else if (parent->right == node)
	{
		node->right = parent;
		node->left = parent->left;
		if (node->left)
			node->left->parent = node;
	}
	parent->left = left_temp;
	if (parent->left)
		parent->left->parent = parent;
	parent->right = right_temp;
	if (parent->right)
		parent->right->parent = parent;
	parent->parent = node;
}

/**
 * free_queue - free the remainings mallocs in the que
 * @head: queue pointer
 *
 * Return: Null or the first node of the queue
 */
void free_queue(list_t *head)
{
	int i = 0;
	void *tmp = NULL;

	for (i = 0; head != NULL; i++)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
