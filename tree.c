#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

#define HERE fprintf(stderr, "YOU NEED TO IMPLEMENT THIS!\n");

// A useful helper function for contains/find/insert.
// This returns the pointer to the node that matches the
// key or NULL if nothing matches.
tree_node *find_node(tree_node *t, const void *key, int (*comparison_fn)(const void *, const void *))
{
    // Suppress compiler warnings
    (void)t;
    (void)key;
    (void)comparison_fn;
    HERE;
    return NULL;
}

// Allocates a new tree with the specified comparison function.
tree *new_tree(int (*comparison_fn)(const void *, const void *))
{
    (void)comparison_fn;
    HERE;
    return NULL;
}

// Frees the the nodes, but does not free the keys
// or data (deliberately so).
void free_node(tree_node *t)
{
    (void)t;
    HERE;
    return;
}

// And frees the entire tree and the nodes
// but again, not the data or keys.
void free_tree(tree *t)
{
    (void)t;
    HERE;
    return;
}

// Returns true if the key (comparison == 0) is in the tree
bool contains(tree *t, const void *key)
{
    (void)t;
    (void)key;
    HERE;
    return false;
}

// Returns the data or NULL if the data is not in the tree.
void *find(tree *t, const void *key)
{
    (void)t;
    (void)key;
    HERE;
    return NULL;
}

// Inserts the element into the tree
void insert(tree *t, void *key, void *data)
{
    (void)t;
    (void)key;
    (void)data;
    HERE;
    return;
}

// This visits every node in an in-order traversal,
// calling f on key, data, context.  Context is
// so that f has an ability to maintain its own state
// between calls.  This is a useful helper function for implemneting
// traverse
void traverse_node(tree_node *t, void (*f)(void *, void *, void *), void *context)
{
    (void)t;
    (void)f;
    (void)context;
    HERE;
    return;
}

void traverse(tree *t, void (*f)(void *, void *, void *), void *context)
{
    (void)t;
    (void)f;
    (void)context;
    HERE;
    return;
}