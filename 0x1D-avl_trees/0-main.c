#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	return (root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int avl;

	root = basic_tree();

	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Is %d avl: %d\n", root->n, avl);
	return (0);
}
