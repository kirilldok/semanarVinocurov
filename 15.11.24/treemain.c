#include"tree.h"

void* str_clode(const void* a){
	return strdup((const char* a));
}

int str_cmp(const void* a, const void* b){
	return strcmp((const char*)a, (const char*) b);
}

int tree_print(Tree* t, void* v){
	printf("Node %s ", (char*)v);
}


int main()
{
	
}



