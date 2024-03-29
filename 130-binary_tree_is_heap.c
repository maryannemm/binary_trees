#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
/* Function prototypes */
int btih_helper(const binary_tree_t *tree);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - helper function to check if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (btih_helper(tree->left) && btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is a complete tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a complete tree, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - helper function to check if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: current index of the node
 * @size: total number of nodes in the tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

