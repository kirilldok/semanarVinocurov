#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int* lab;

size_t W;
size_t H;

struct point{
	int x;
	int y;
};

typedef struct queue_{
	struct point pt;
	struct queue_ next;
} queue;

struct point start;
struct point end;
size_t cap;
int dist = 1;

#define CELL(x, y) *(lab + (y) * W + (x))
#define VALID(dx, dy) (dx)*(dx) + (dy)*(dy) == 1
#define INBOUNDS(x, y) ((x >= 0 && (x) < W) && (y) >= 0 && y < H)
#define METRIC(dx, dy) (((dx)*(dx)+ (dy)*(dy)) == 1?5:7)


int queue_add(queue** q, struct point pt){
	queue* n = malloc(sizeof(queue));
	
	if (!*q){
		*n = (queue){pt,n};
	} else {
		*n = (queue){pt, (*q)->next};
		(*q)->next = n;
	}
	*q = n;
	return 0;
}

int queue_pop(queue** q, struct point* pt){
	if (! *q) return -1;
	*pt = (*q)->next->pt;
	queue* old = (*q)->next;
	if(old == (*q))
		*q = NULL;
	else 
		(*q)->next = old->next;
	free(old);
	return 0;
}


int read_lab(FILE* f) {
	H = 0;
	W = 0;
	char buf[1024];
	cap = 1024;
	lab = calloc(cap, sizeof(int));
	if(!lab ) return -1;
	while(fgets(buf, sizeof(buf), f)){
		if(H == 0) W = strlen(buf);
		if((H+1)*W >= cap) lab = realloc(lab, sizeof(int) * (cap*=2));
		if(!lab) return -1;

		for(int i = 0; i < W; i++)
		{
			switch(buf[i])
			{
			case 'i':
				start = (struct point){i, H};
				CELL(i, H) = 0;
				break;
			case 'o':
				end = (struct point){i, H};
				CELL(i, H) = 0;
				break;
			case ' ':
				CELL(i, H) = 0;
				break;
			default:
				CELL(i, H) = -1;
				break;
			}
		}
		H++;
	}
	return 0;
}


int print_lab() {
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++)
		{
			if( x == start.x && y == start.y){
				fputc('i', stdout);
			} else if(x == end.x && y == end.y){
				fputc('o', stdout);
			} else {
				switch(CELL(x, y)){
				case 0: fputs(' ', stdout); break;
				case -1: fputs('#', stdout); break;
				default: printf("\033[9%dm%c \033[0m",  (CELL(x, y) / 10)%10, '0' + CELL(x, y) / 10); break;
				}
			}
		}
		fputc('\n', stdout);
	
	}
}


int shortest_path(queue** q){
	if (*q)
	{
		struct point pt;
		queue_pop(q, &pt);
		for(int dx = -1; dx <= 1; dx++)
		{
			for( int dy = -1; dy <= 1; dy++)
			{
				struct point n = {pt.x +dx, pt.y +dy};
				if(VALID(dx, dy) && INBOUNDS(n.x, n.y))
				{
					if (CELL(n.x, n.y) != -1
							&& (CELL(n.x, n.y) == 0)
								|| (CELL(n.x, n.y) > dist + METRIC(dx, dy)))
					{
						CELL(n.x, n.y) = dist + METRIC(dx, dy);
						queue_add(q, n);
					}
				}
			}	
		}
		return shortest_path(q);
	}
	return 0;
}


int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		FILE* f = fopen(argv[1], "r");
		if (!f) return -fprintf(stderr, "cannot open file %s\n", argv[1]);
		if (!read_lab(f)){
			print_lab();
			queue* q = NULL;
			queue_add(&q,start);
			if(!shortest_path(&q)){
				if( CELL(end.x, end.y) >=0){
					printf("The way has been found:%d\n", CELL(end.x,end.y));
				} else {
					printf("NO WAY!\n");
				}
			} else {
				printf("Founding error\n");
			}
		}
		fclose(f);
		free(lab);
	} else {
		fprintf(stderr, "Waiting for file\n");
	}
	return 0;
}
