#include "binary_trees.h"

/**
 * array_to_avl_recursive - Recursive function to build AVL tree from sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the first element in the current subarray
 * @end: Index of the last element in the current subarray
 * Return: Pointer to the root of the created AVL tree
 */
avl_t *array_to_avl_recursive(int *array, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    avl_t *root = binary_tree_node(NULL, array[mid]);
    if (!root)
        return NULL;

    root->left = array_to_avl_recursive(array, start, mid - 1);
    if (root->left)
        root->left->parent = root;

    root->right = array_to_avl_recursive(array, mid + 1, end);
    if (root->right)
        root->right->parent = root;

    return root;
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    return array_to_avl_recursive(array, 0, size - 1);
}

