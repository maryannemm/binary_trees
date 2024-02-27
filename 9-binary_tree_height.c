#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    if (tree == NULL)
        return (0);

    /* Get the height of the left subtree */
    height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;

    /* Get the height of the right subtree */
    height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    /* Return the maximum of the two heights */
    return (height_left > height_right ? height_left : height_right);
}

