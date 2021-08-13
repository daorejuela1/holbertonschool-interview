#include "limits.h"
#include "binary_trees.h"


/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
static int _height(const binary_tree_t *tree)
{
	int height_l;
	int height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * helper - helper func for binary_tree_is_bst
 * @tree: pointer to tree node
 * @min: minimum value of BST tree
 * @max: maximum value of BST tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
static int helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (helper(tree->left, min, tree->n - 1) &&
			helper(tree->right, tree->n + 1, max));
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to root of tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
static int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - checks if a binary tree is an avl
 * @tree: pointer to the root of the tree
 * Return: 1 if tree is an AVL, if 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_bst(tree))
	{
		if (ABS(_height(tree->right) - _height(tree->left)) >= 2)
		{
			return (0);
		}
		else
		{
			if (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->left))
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}
	}
	return (0);
}
