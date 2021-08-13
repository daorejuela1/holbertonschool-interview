#include "limits.h"
#include "binary_trees.h"

/**
 *countpa - counter for parametter
 *@countLeft: counter for left node
 *@countRight: counter for right node
 *@tree: binari tree
 *Return: value of counter
 */
static int countpa(int countLeft, int countRight, const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
		countLeft = countpa(countLeft, countRight, tree->left);
		countRight = countpa(countLeft, countRight, tree->right);
		if (countRight > countLeft)
			return (countRight + 1);
		return (countLeft + 1);
}

/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
static int _height(const binary_tree_t *tree)
{
	int countLeft = 0, countRight = 0;

	if (tree == NULL)
		return (0);
	return (countpa(countLeft, countRight, tree) - 1);
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
		return (1);
	return (helper(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - checks if a binary tree is an avl
 * @tree: pointer to the root of the tree
 * Return: 1 if tree is an AVL, if 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_difference = 0;

	if (!tree)
		return (0);
	height_difference = _height(tree->right) - _height(tree->left);
	if (binary_tree_is_bst(tree))
	{
		if (height_difference >= 1 || height_difference <= -1)
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
