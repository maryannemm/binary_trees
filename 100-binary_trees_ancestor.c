#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    binary_tree_t *p, *q;

    if (!first || !second)
        return (NULL);

    p = (binary_tree_t *)first;
    q = (binary_tree_t *)second;

    while (p != q)
    {
        if (!p)
            p = (binary_tree_t *)second;
        else
            p = p->parent;

        if (!q)
            q = (binary_tree_t *)first;
        else
            q = q->parent;
    }

    return (p);
}

