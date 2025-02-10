#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char** a, char** b)
{
	char* x = *a;
	*a = *b;
	*b = x;
}


int myqsort(char** array, size_t start, size_t end)
{
	size_t pivot = start;
	size_t last = end - 1;
	size_t i = pivot + 1;
	if (end <= start + 1) return 0;
	
	while(i < last)
	{
		if( strcmp(array[i], array[pivot]) < 0)
			swap(&array[i++], &array[pivot++]);
		else
			swap(&array[i], &array[last--]);
	}	
	
	myqsort(array, start, pivot);
	myqsort(array, pivot + 1, end);
	//merge is done automaticly
}



int main(int argc, char* argv[])
{
	char buf[4096];
	size_t cap = 4096;
	size_t sz = 0;
	
	char **array = malloc(cap * sizeof( char*));
	while(fgets(buf, sizeof(buf), stdin))
	{
		if (sz >= cap)
		{
			array = realloc(array, sizeof(char*) * (cap *= 2));
			if (!array) return -fprintf(stderr, "Cannot realocate memory of %lu\n", cap);
		}

		array[sz++] = strdup(buf);
	}
	myqsort(array, 0, sz);
	for (size_t i = 0; i < sz; i++)
	{
		fputs(array[i], stdout);
		free(array[i]);
	}
}








