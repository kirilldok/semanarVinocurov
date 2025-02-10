#include <stdio.h>
#include <sring.h>
#include <stdlib.h>

int* lab;

size_t W;
size_t H;


typedef struct _point{
	int x;
	int y;
} point;


typedef struct queue_{
	point pt;
	struct queue_
} queue;

point start;
point end;

#define CELL(x,y) *(lab + (y) * W + (x))


int queue_add(queue** q, point pt){
	queue* n = malloc(sizeof(queue));

	if( !*q){
		*n = (queue){pt, n};
	} else {
		*n = (queue){pt, (*q)->next};
		(*q)->next = n;
	}
	*q = n;
	return 0;
}

int queue_pop(queue** q, point pt){
	if(! *q) return -1;
	*pt = (*q)->next->pt;
	queue* old = (*q)->next;
	if(old == (*q))
		*q == NULL;
	else
		(*q)->next = old->next;
	free(old);
	return 0;
}


int read_lab(FILE* f)
{
	H = 0;
	W = 0;
	char buf[1024];
	lab = calloc(1024, sizeof(int));
	if(!lab) return -1;
	while(fgets(buf, sizeof(buf), f))
	{
		if(H == 0) W = strlen(buf);
		if((H+1)*W >= cap) lab = realloc(lab, sizeof(int) * (cap*=2));
		if(!lab) return -1;

		for(int i = 0; i < W; i++ )
		{
			switch(buf[i]){
				case 'i':
					start = (point){i, H};
					CELL(i, H) = 0;
					break;
				case 'o':
					end = (point){i, H};
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

int print_lab(){
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){
			if(x == start.x && y == start.y){
				fputc('i', stdout);
			} else if(x == end.x && y == end.y){
				fputc('o', stdout);
			} else {
				switch(CELL(x, y)){
				case 0: fputs(' ', stdout); break;
				case -1: fputs('#', stdout); break;
				default: fputs(CELL(x, y) % 10, stdout); break;
				}
			}
		}
		fputc('\n', stdout);
	}
	return 0;
}




