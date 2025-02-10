#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _matrix {
	long a, b, c, d;
} matrix;


void mmul(matrix* a, matrix* b, matrix* c) {
	*c = (matrix) { a->a*b->a + a->b*b->c,
		a->a*b->b + a->b*b->d,
		a->c*b->a + a->d*b->c,
		a->c*b->b + a->d*b->d};
}


matrix mone = {1,0,0,1};

void mpow(matrix* a, int p, matrix* c) {
	if ( p == 0) *c = mone;
	else if ( p == 1) *c = *a;
	else if ( p % 2 ) {
		matrix x;
		mpow(a, p-1, &x);
		mmul(a, &x, c);
	} else {
		matrix x;
		mpow(a, p/2, &x);
		mmul(&x, &x, c);
	}
}

double _fib2(long n, double a, double b) {
	return n ? _fib2(n-1, a , b):a;
}

double _fib3(long n, double a, double b) {
	while(n) {
		long c = b;
		b = a;
		a = a+c;
		n--;
	}
return a;
}

/*double fib4(long n) {
	matrix F = {1,1,1,0};
	matrix res;
	mpow(&F, n, &res);
	return res.a;
}*/

double fib2(long n, double a, double b) {
	return _fib2(n, a, b);
}

double fib(long n) {
	return n<2 ? 1 : fib(n-1)+fib(n-2);
}

double dif(int n, double a, double b, double alfa)
{
	if(n == 0) return a;
	printf("%lg\n", a);
	return dif(n - 1, alfa*a - sqrt(1 - alfa*alfa/2) * b, b,  alfa);

}



int main(int argc, char* argv[]) {
	double alfa;
	if (argc <= 1) return fprintf(stderr, "Argument required\n");
	alfa = atof(argv[1]); 
	dif(2000, 0.2, .0 , alfa);
	return 0;
}
