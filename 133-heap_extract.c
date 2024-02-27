#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_last_node - Gets the last node of a binary tree
 * @root: Pointer to the root node of the binary tree
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    if (!root)
        return NULL;

    while (root->left || root->right)
    {
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }

    return root;
}

/**
 * heapify_down - Heapifies the binary tree downward
 * @root: Double pointer to the root node of the binary tree
 */
void heapify_down(heap_t **root)
{
    if (!(*root))
        return;

    heap_t *current = *root;
    heap_t *max = current;
    int temp;

    while (current)
    {
        if (current->left && current->left->n > max->n)
            max = current->left;

        if (current->right && current->right->n > max->n)
            max = current->right;

        if (max != current)
        {
            temp = current->n;
            current->n = max->n;
            max->n = temp;
            current = max;
        }
        else
        {
            break;
        }
    }
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return 0;

    int value = (*root)->n;
    heap_t *last_node = get_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    if ((*root)->left == last_node)
        (*root)->left = NULL;
    else
        (*root)->right = NULL;

    (*root)->n = last_node->n;

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);

    heapify_down(root);

    return value;
}

