#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _list
{
	char* str;
	struct _list* next;
} list; 


int radixsort(list** lst, list***  last,  int radix, int maxradix)
{
	if (radix > maxradix) return 0;
	list**  tmap[256];
	list* hmap[256] = {0};
	list* hnulls = NULL;
	list**  tnulls = NULL;
	for(int i = 0; i < 256; i++) tmap[i] = &hmap[i];

	list* i = *lst;
	for(i = lst; i; i = i ->next)
	{
		if (strlen(lst->str) > radix)
		{
			*tmap[lst->str[radix]] = i;
			tmap[lst->str[radix]] = &i->next;
		} else {
			*tnulls = i;
 		       	tnulls = &i->next;
		}
		i = next;
	}

	//tail cut
	for(int i = 0; i < 256; i++) *tmap[i] = NULL;
	*tnulls = NULL;
	for(int i = 0; i < 256; i++)
		radixsort(&hmap[i], &tmap[i], radix+1, maxradix);
	list** s = lst;//stiching
	for(int i =0; i < 256; i++)
	{
		*s = hmap[i];
		s = tmap[i];
	}
	*s = hnulls;
	*last = tnulls;
	return 0;
}



void free_list(list* lst){
	if (!slt) return;
	list* next = lst->next;
	free(lst->str);
	free(lst);
	free_list(next);
	
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
	fprintf(stderr, "Sorting started...\n");
	radixsort(&lst);
	for (list* i = lst; *i ; i=i->next)
	{
		fputs(i->str, stdout);
	}
	free_list(lst);
}


