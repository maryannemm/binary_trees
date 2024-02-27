#include "binary_trees.h"

/**
 * binary_tree_level - Finds the node at a given level
 * @tree: A pointer to the root node of the tree
 * @level: The level to find
 *
 * Return: A pointer to the node at the specified level, or NULL if not found
 */
binary_tree_t *binary_tree_level(const binary_tree_t *tree, size_t level)
{
    if (tree == NULL)
        return (NULL);
    if (level == 0)
        return ((binary_tree_t *)tree);

    binary_tree_t *left = binary_tree_level(tree->left, level - 1);
    binary_tree_t *right = binary_tree_level(tree->right, level - 1);
    
    return (left ? left : right);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t height = 0, i;

    if (tree == NULL)
        return (0);

    while (binary_tree_level(tree, height))
        height++;

    for (i = 0; i < height - 1; i++)
    {
        if ((binary_tree_level(tree, i)->left == NULL && binary_tree_level(tree, i)->right != NULL) ||
            (binary_tree_level(tree, i)->left != NULL && binary_tree_level(tree, i)->right == NULL))
            return (0);
        else if (binary_tree_level(tree, i)->left == NULL && binary_tree_level(tree, i)->right == NULL)
        {
            if (binary_tree_level(tree, i + 1)->left != NULL || binary_tree_level(tree, i + 1)->right != NULL)
                return (0);
        }
    }

    return (1);
}

