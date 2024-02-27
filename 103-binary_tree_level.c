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
    
    return (binary_tree_level(tree->left, level - 1) ?:
            binary_tree_level(tree->right, level - 1));
}

