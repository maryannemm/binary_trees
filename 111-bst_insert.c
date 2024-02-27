#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current;

    if (tree == NULL)
        return (NULL);

    current = *tree;

    /* If the tree is empty, create a new node and make it the root */
    if (current == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        if (new_node == NULL)
            return (NULL);
        *tree = new_node;
        return (new_node);
    }

    /* If the value already exists, return NULL */
    if (value == current->n)
        return (NULL);

    /* Traverse the tree to find the appropriate position for insertion */
    if (value < current->n)
    {
        if (current->left != NULL)
            return (bst_insert(&(current->left), value));
        else
        {
            new_node = binary_tree_node(current, value);
            if (new_node == NULL)
                return (NULL);
            current->left = new_node;
            return (new_node);
        }
    }
    else
    {
        if (current->right != NULL)
            return (bst_insert(&(current->right), value));
        else
        {
            new_node = binary_tree_node(current, value);
            if (new_node == NULL)
                return (NULL);
            current->right = new_node;
            return (new_node);
        }
    }
}

