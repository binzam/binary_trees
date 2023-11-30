#include "binary_trees.h"

bst_t *bst_minimum(bst_t *node);
/**
 * bst_remove - Removes a node from a BST.
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove from the tree.
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			free(root);
			return (temp);
		}

		bst_t *successor = bst_minimum(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}

/**
 * bst_minimum - Finds the minimum node in a BST.
 * @node: Pointer to the root node of the tree.
 * Return: Pointer to the minimum node in the tree.
 */
bst_t *bst_minimum(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->left != NULL)
		node = node->left;

	return (node);
}
