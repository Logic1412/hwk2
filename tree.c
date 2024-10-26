#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

//#define HERE fprintf(stderr, "YOU NEED TO IMPLEMENT THIS!\n");

// A useful helper function for contains/find/insert.
// This returns the pointer to the node that matches the
// key or NULL if nothing matches.
tree_node *find_node(tree_node *t, const void *key, int (*comparison_fn)(const void *, const void *))
{
    // Suppress compiler warnings
    (void)t;
    (void)key;
    (void)comparison_fn;
    //variables

    if (t == NULL) {
        return NULL;
    }//if null

    int comparison = comparison_fn(key, t->key);
    if (comparison < 0) {
        return find_node(t->left, key, comparison_fn);
    } else if (comparison > 0) {
        return find_node(t->right, key, comparison_fn);
    } else {
        return t;
    }
}//end of find_node

// Allocates a new tree with the specified comparison function.
tree *new_tree(int (*comparison_fn)(const void *, const void *))
{
    (void)comparison_fn;
    //variables

    tree *t = malloc(sizeof(tree));
    if (!t) {
        exit(EXIT_FAILURE);
    }//not find

    t->root = NULL;
    t->comparison_fn = comparison_fn;
    return t;
}//end of new_tree

// Frees the the nodes, but does not free the keys
// or data (deliberately so).
void free_node(tree_node *t)
{
    (void)t;
    if (t == NULL) {
        return;
    }

    free(t);//free
}//end of free_node

// And frees the entire tree and the nodes
// but again, not the data or keys.
void free_tree(tree *t)
{
    (void)t;
    if (t == NULL) {
        return;
    }

    tree_node *stack[1000];
    int top = -1;
    tree_node *current = t->root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        tree_node *right = current->right;
        free_node(current);
        current = right;
    }

    free(t);//free
}//end of free_tree

// Returns true if the key (comparison == 0) is in the tree
bool contains(tree *t, const void *key)
{
    return (t != NULL) && (find_node(t->root, key, t->comparison_fn) != NULL);
}

// Returns the data or NULL if the data is not in the tree.
void *find(tree *t, const void *key)
{
    (void)t;
    (void)key;
    if (t == NULL) {
        return NULL;
    }
    tree_node *found = find_node(t->root, key, t->comparison_fn);
    if (found != NULL) {
        return found->data;
    }
    return NULL;
}//end of find

// Inserts the element into the tree
void insert(tree *t, void *key, void *data)
{
    (void)t;
    (void)key;
    (void)data;
    if (t == NULL) {
        return;
    }

    tree_node *parent = NULL;
    tree_node *current = t->root;
    int comparison = 0;

    while (current != NULL) {
        parent = current;
        comparison = t->comparison_fn(key, current->key);
        if (comparison < 0) {
            current = current->left;
        } else if (comparison > 0) {
            current = current->right;
        } else {
            // Key already exists, update data
            current->data = data;
            return;
        }
    }// fint insert position

    tree_node *new_node = malloc(sizeof(tree_node));
    if (!new_node) {
        perror("Failed to allocate memory for tree node");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    // Create a new node

    if (parent == NULL) {
        t->root = new_node;
    } else {
        if (comparison < 0) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }//insert the new node
}//end of insert

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
    if (t == NULL) {
        return;
    }

    traverse_node(t->left, f, context);
    f(t->key, t->data, context);
    traverse_node(t->right, f, context);
}//end of traverse_node

void traverse(tree *t, void (*f)(void *, void *, void *), void *context)
{
    (void)t;
    (void)f;
    (void)context;
    if (t == NULL) {
        return;
    }
    traverse_node(t->root, f, context);
}//end of traverse
