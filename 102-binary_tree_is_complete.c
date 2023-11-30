#include "binary_trees.h"

/**
 * count_nodes - function that count the number of nodes
 * @root: pointer to the root node of the tree to check
 * Return: number of nodes
 */

size_t count_nodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - helper function that check if the binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * @indx: index.
 * @num_nodes: number of nodes.
 * Return: returns 1 if is complete, 0 otherwise.
 */

int is_complete(const binary_tree_t *tree, int indx, int num_nodes)
{
	if (tree == NULL)
		return (1);

	if (indx >= num_nodes)
		return (0);

	return (is_complete(tree->left, 2 * indx + 1, num_nodes) &&
			is_complete(tree->right, 2 * indx + 2, num_nodes));
}

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int countNodes = count_nodes(tree);

	if (tree == NULL)
		return (0);
	return (is_complete(tree, 0, countNodes));
}
