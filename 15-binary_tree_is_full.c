#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 if the binary tree is full, 0 if not full or is NULL.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);
	if ((tree->left && !(tree->right)) ||
		(!(tree->left) && tree->right))
		return (0);
	return (left && right);
}
