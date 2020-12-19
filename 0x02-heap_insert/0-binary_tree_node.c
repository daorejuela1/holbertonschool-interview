#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree having in account the parent
 * @parent: Node before this node is created
 * @value: integer value of the node
 *
 * Return: Node address or Null if failed
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	return (new_node);
}
