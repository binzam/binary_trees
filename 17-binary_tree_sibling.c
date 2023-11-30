#include "binary_trees.h"

/**
 * binary_tree_sibling -  finds the sibling of a node.
 * @node: a pointer to the node to find the sibling.
 * Return: the sibling of the node,
 * NULL if node or the parent is NULL or node has no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (parent->left == node)
	{
		return (parent->right);
	}
	else
	{
		return (parent->left);
	}
	return (NULL);
}
