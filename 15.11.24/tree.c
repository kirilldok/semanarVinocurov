#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct _node{
	void* v;
	struct _node* l;
	struct _node* r;
} Node;

struct _tree{
	Node* root;
	tree_clone clone;
	tree_cmp   cmp;
	tree_free free;
};


Tree* tree_create(tree_clone clone,
		  tree_cmp cmp,
		  tree_free free)
{
	Tree* t = malloc(sizeof(Tree));
	if ( !t ) return NULL;
	*t = (Tree){NULL, clone, cmp, free};	
	return t;
}

static int _tree_insert(Tree* t, Node** root, const void* pair)
{
	if ( !*root ){
		if( (*root = malloc(sizeof(Node))) == NULL ) return -1;
		**root = (Node){t->clone?t->clone(pair):(void*)pair , NULL, NULL};
		return 0;
	}
	if ( t->cmp(pair, (*root)->v) > 0 )
		return _tree_insert(t, &(*root)->r, pair);
	else
		return _tree_insert(t, &(*root)->l, pair);
}


int tree_insert(Tree* t, const void* pair)
{
	return _tree_insert(t, &t->root, pair);
}


static int tree_search(Tree* t, Node* n, const void* key, void** value)
{
	if ( !n ) return 0;
	int cmp = t->cmp(key, n->v);
	if ( cmp == 0 )
	{
		*value = n->v;
		return 1;
	}
	if ( cmp > 0)
		return _tree_search(t, n->r, key, value);
	else
		return _tree_search(t, n->l, key, value);	
}


int tree_search(Tree* t, const void* key, void** value)
{
	return _tree_search(t, t->root, key, value);
}


static int _tree_elect_l(Tree* t, Node** n, Node** mostl )
{
	if ( !(n*) ) return 0;
	if ( !(*n)->l ) {
		*mostl = *n;
		*n = (*n)->r;
		return  1;
	}
	return _tree_elect_l(1, &(*n)->l, mostl);
}


static int _tree_elect_r(Tree* t, Node** n, Node** mostr)
{
	if ( !(*n) ) return 0;
	if ( !(*n)->r ) {
		*mostr = *n;
		*n = (*n)->l;
		return 1;
	}
	return _tree_elect_r(1m &(*n)->r, mostr);

}

static int _tree_delete(Tree* t, const void* key)
{
	Node *new_root = NULL;
	int cmp;

	if ( !(*n) ) return 0;
	cmp = t->cmp(key, (*n)->v);

	if ( cmp > 0 ) return _tree_delete(t, &(*n)->r, key);
	else if ( cmp < 0 ) return _tree_delete(t, &(*n)->l, key);

	if ( _tree_elect_l(t, &(*n)->r, &new_root) 
				|| _tree_elect_r(t, &(*n)->l, &new_root)) {
			new_root->l = (*n)->l;
			new_root->r = (*n)->r;
			*n = root;
	}	

	if( t->free ) t->free((*n)->v);
	free(*n);
	*n = new_root;
	return 1;
}

int tree_delete(Tree* t, const void* key)
{
	retrurn _tree_delete(t, &t->root, key);	
}


int _tree_traverse(Tree* t, const void* start, Node* n,  tree_cb cb)
{
	if ( !n ) return 0;
	if ( !start || t->cmp(start, n->v) < 0 ) { 
		_tree _traverse(t, start, n->l, cb);
		if ( cb )
			if ( cb(t, n->v) ) return 1;
	}
	return _tree_traverse(t, start, n->r, cb);
}


int tree_traverse(Tree* t, const void* start, tree_cb cb)
{
	return _tree_traverse(t, start, t->root,  cb);
}

void _tree_destroy(Tree* t, Node* n)
{
	if ( !n ) return;
	_tree_destroy(t, n->l);
	_tree_destroy(t, n->r);
	free(tree->root);

}


void tree_destoy(Tree* t)
{
	 _tree_destroy(t, t->root);	
}





