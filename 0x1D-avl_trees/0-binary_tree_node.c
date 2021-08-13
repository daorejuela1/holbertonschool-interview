#include "binary_trees.h"

/**
 *binary_tree_node - create a new node
 *@parent: the parent of tree
 *@value: the value
 *Return: value of return
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nuevo = NULL;

	nuevo = malloc(sizeof(binary_tree_t));
	if (nuevo == NULL)
	return (NULL);

	nuevo->n = value;
	nuevo->parent = parent;
	nuevo->left = NULL;
	nuevo->right = NULL;

	return (nuevo);
}
