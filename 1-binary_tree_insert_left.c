#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    /* Allocate memory for new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize new node */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    /* If parent already has a left child */
    if (parent->left != NULL)
    {
        /* Set new node's left child pointer to current left child */
        new_node->left = parent->left;
        /* Update left child's parent pointer to new node */
        parent->left->parent = new_node;
    }

    /* Set parent's left child pointer to new node */
    parent->left = new_node;

    return (new_node);
}

