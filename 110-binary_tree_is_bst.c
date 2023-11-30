#include "binary_trees.h"

int is_bst_helper(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the current node in the tree
 * @min: Minimum value for current node
 * @max: Maximum value for current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */

int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, max));
}
