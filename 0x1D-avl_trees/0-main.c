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

	root = binary_tree_node(NULL, 70);
	root->left = binary_tree_node(root, 50);
	root->right = binary_tree_node(root, 90);
	root->left->left = binary_tree_node(root->left, 40);
	root->left->right = binary_tree_node(root->left, 60);
	root->right->left = binary_tree_node(root->right, 80);
	root->right->right = binary_tree_node(root->right, 110);
	root->right->right->left = binary_tree_node(root->right->right, 105);
	root->right->right->right = binary_tree_node(root->right->right, 120);
	root->right->left->left = binary_tree_node(root->right->left, 75);
	root->right->left->right = binary_tree_node(root->right->left, 85);
	/*root->left->right->left = binary_tree_node(root->left->right, 55);*/
	/*root->left->right->right = binary_tree_node(root->left->right, 65);*/
	root->left->left->left = binary_tree_node(root->left->left, 35);
	root->left->left->right = binary_tree_node(root->left->left, 45);
	root->left->left->left->left = binary_tree_node(root->left->left->left, 25);

	avl = binary_tree_is_avl(root);
	printf("Is the tree with root node (%d) an AVL: %d\n", root->n, avl);

	binary_tree_print(root);
	return (0);
}
