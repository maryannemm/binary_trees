#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + tree_size(tree->left) + tree_size(tree->right);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array of integers, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (!heap)
        return NULL;

    *size = tree_size(heap);

    int *sorted_array = malloc(*size * sizeof(int));
    if (!sorted_array)
        return NULL;

    int i = *size - 1;
    while (heap != NULL)
    {
        sorted_array[i--] = heap->n;
        heap_extract(&heap);
    }

    return sorted_array;
}

