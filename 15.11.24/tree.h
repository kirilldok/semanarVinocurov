#ifndef _TREE_H_
#define _TREE_H_

typedef struct _tree Tree;

typedef void* (*tree_clone)(const void*);
typedef int   (*tree_cmp)(const void*, const void*);
typedef void  (*tree_free)(void *);
typedef void (*tree_cb)(const Tree* t, const void* key);

/*creates a new tree with interface functoins */
Tree* tree_create(tree_clone clone_func, tree_cmp cmp_func, tree_free destroy_func);

/* Inserts a new element into tree */
int tree_insert(Tree* t, const void* pair);

/* Search for an element */
int tree_search(Tree* t, const void* key, void** value);

/* Delete an element from the tree*/
int tree_delete(Tree* t, const void* key);

/* Tree destroy */
void tree_destroy(Tree* t);


/*Tree traverse*/
int tree_traverse(Tree* t, const void* start, tree_cb cb );

#endif /* _TREE_H_ */
