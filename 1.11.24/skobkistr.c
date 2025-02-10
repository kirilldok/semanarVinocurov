#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check(FILE* f, int  expect)
{
	int c = fgetc(f);
	switch(c)
	{
		case EOF: return expect == 0;
		case '{': return check(f, '}') && check(f, expect);
		case '(': return check(f, ')') && check(f, expect);
		case '[': return check(f, ']') && check(f, expect);
		case '}': case ')': case ']': return expect == c;
		case '"': return check(f, '"');
		default : return check(f, expect);
	}
}

int main(int argc, char* argv[])
{
	if(check(stdin, 0))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}



