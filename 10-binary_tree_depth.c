#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the depth.
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	if (tree->parent != NULL)
	{
		depth = binary_tree_depth(tree->parent) + 1;
	}
	return (depth);
}
