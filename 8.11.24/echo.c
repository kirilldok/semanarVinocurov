#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _queue
{
	double* buf;
	size_t cap;
	size_t first;
	size_t last;
	size_t size;
} queue; 

int queue_init(queue* q, size_t cap)
{
	*q = (queue){calloc(cap, sizeof(double)), cap, 0, 0, 0};
	return q->buf != NULL;
}

int queue_add(queue* q, double v)
{
	if ( q->size >= q->cap ) return -1;
	q->buf[q->first] = v;
	q->first = (q->first + 1) % q->cap;
	q->size++;
	return 0;
}

int queue_pop(queue* q, double* v)
{
	if ( q->size == 0 ) return -1;
	*v = q->buf[q->last];
	q->last = (q->last + 1) % q->cap;
	q->size--;
	return 0;
}


size_t queue_size(queue* q)
{
	return q->size;
}

void queue_free(queue*q)
{
	free(q->buf);
}


int main(int argc, char* argv[])
{
	size_t delay = 10;
	double alpha = 0.5;
	if ( argc > 1 )
		delay = atol(argv[1]);
	if ( argc > 2 )
		alpha = atof(argv[2]); 
	
	queue q;
	queue_init(&q, delay);
	double x;
	while( fscanf(stdin, "%lf", &x) == 1 )
	{
		double echo = 0;
		if ( queue_size(&q) == delay )
		{
			queue_pop(&q, &echo);
			printf("%lf\n", x + echo * alpha);
		} else
			printf("%lf\n", x);
		queue_add(&q, x);
	}
	while( queue_size(&q) ){
		double echo = 0;
		queue_pop(&q, &echo);
		printf("%lf", echo*alpha);
	}
	queue_free(&q);
}
