#include "binary_trees.h"
#include <stdlib.h> // Include the standard library header for abs function

/**
 * max - Get the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (1);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (abs(left_height - right_height) <= 1 &&
        binary_tree_is_avl(tree->left) &&
        binary_tree_is_avl(tree->right))
        return (1);
    
    return (0);
}

