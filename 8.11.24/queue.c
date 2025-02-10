#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _list
{
	double v;
	struct _list* next;
} list; 


int queue_add(list** queue, list* e)
{
	if ( *queue ){
		list* z = (*queue)->next;
		(*queue)->next = e;
		e->next = z;
	} else {
		e->next = e;
	}
	*queue = e;
	return 0;
}

int queue_pop(list** q, list** v)
{
	if( !*q) return -1;
	*v = (*q)->next;
	if( (*q)->next == *q)
		*q = NULL;
	 else
		(*q)->next = (*v)->next;
	return 0;
}


int main(int argc, char* argv[])
{
	size_t delay = 10;
	double alpha = 0.5;
	if ( argc > 1 )
		delay = atol(argv[1]);
	if ( argc > 2 )
		alpha = atof(argv[2]); 
	
	list* q = NULL;
	size_t sz = 0;
	double x;
	while( fscanf(stdin, "%lf", &x) == 1 )
	{
		list* echo = NULL;
		if ( sz  == delay )
		{
			queue_pop(&q, &echo);
			printf("%lf\n", x + echo->v * alpha);
			free(echo);
			sz--;
		} else
			printf("%lf\n", x);

		list* n = malloc(sizeof(list));
		*n = (list){x + alpha *(echo?echo->v:0), NULL};
		queue_add(&q, n);
		sz++;
	}
	while( q ){
		list* echo;
		queue_pop(&q, &echo);
		printf("%lf", echo->v * alpha);
		free(echo);
	}
	queue_free(&q);
}
