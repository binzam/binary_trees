#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *recursive_sort_array_avl(avl_t *parent, int *array, int begin, int last);
/**
 * recursive_sort_array_avl - Create the tree using the half element of the array.
 *
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @begin: Position where the array starts.
 * @last: Position where the array ends.
 *
 * Return: Tree created.
 */
avl_t *recursive_sort_array_avl(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = recursive_sort_array_avl(root, array, begin, mid - 1);
		root->right = recursive_sort_array_avl(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - Builds an AVL tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (recursive_sort_array_avl(NULL, array, 0, ((int)(size)) - 1));
}
