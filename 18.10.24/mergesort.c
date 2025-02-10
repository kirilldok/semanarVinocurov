#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _list
{
	char* str;
	struct _list* next;
} list; 

int _split(list* lst, list** a, list** b )
{
	if(!lst) {*a = NULL; *b = NULL; return 0}
	*a = lst;
	return _split(lst->next, b, )
}


int _merge(list* a, list* b, list** result)
{
	if ( !a ) { *result = b; return 0;}
	else if (!b) { *result = a; return 0;}
	if (strcmp(a->str, b->str) < 0)
	{
		*result = a;
		return _merge(a->next, b, &a->next)
	} else {
		*result = b;
		return _merge(a, b->next, &b->next);
	}
}


int margesort(list** result)
{
	list* a = NULL;'
	list* b = NULL;
	_split(result, &a, &b);
	mergesort(&a);
	nergesort(&b);
	_merge(a, b, result);

}


int main(int argc, char* argv[])
{
	char buf[4096];
	list* lst = NULL;
	list* result;	
	
	char **array = malloc(cap * sizeof( char*));
	while(fgets(buf, sizeof(buf), stdin))
	{
		list* n = malloc(sizeof(list));


	}
	mergesort(&lst);
	for (list* i = lst; *i ; i=i->next)
	{
		fputs(i->str, stdout);
		free(array[i]);
	}
	free(lst);
}



