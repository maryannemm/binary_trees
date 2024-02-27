#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l, height_r;

    if (tree == NULL)
        return (0);

    height_l = binary_tree_height(tree->left);
    height_r = binary_tree_height(tree->right);

    return ((height_l > height_r ? height_l : height_r) + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int height_left, height_right;

    if (tree == NULL)
        return (0);

    height_left = binary_tree_height(tree->left);
    height_right = binary_tree_height(tree->right);

    return (height_left - height_right);
}

