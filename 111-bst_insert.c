#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 *
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *currnt_node = *tree, *new_node;

	if (tree == NULL)
		return (NULL);

	if (currnt_node == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	while (1)
	{
		if (value == currnt_node->n)
			return (NULL);

		if (value < currnt_node->n)
		{
			if (currnt_node->left != NULL)
				currnt_node = currnt_node->left;
			else
			{
				new_node = binary_tree_node(currnt_node, value);
				currnt_node->left = new_node;
				return (new_node);
			}
		}
		else
		{
			if (currnt_node->right != NULL)
				currnt_node = currnt_node->right;
			else
			{
				new_node = binary_tree_node(currnt_node, value);
				currnt_node->right = new_node;
				return (new_node);
			}
		}
	}
}
