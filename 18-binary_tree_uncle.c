#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node
 *         NULL if node is NULL
 *         NULL if the parent is NULL
 *         NULL if the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (!node || !node->parent)
        return (NULL);

    if (node->parent->parent == NULL)
        return (NULL);

    if (node->parent->parent->left == node->parent)
        return (node->parent->parent->right);
    else
        return (node->parent->parent->left);
}

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node
 *         NULL if node is NULL
 *         NULL if the parent is NULL
 *         NULL if the node has no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (!node || !node->parent)
        return (NULL);

    if (node == node->parent->left)
        return (node->parent->right);
    else
        return (node->parent->left);
}

