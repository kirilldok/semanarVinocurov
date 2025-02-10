#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gnuplot.h>


double dif(int n, double omega, double a, double b)
{
	if (n == 0) return a;
	printf("%lg\n", a);
	return dif(n - 1, omega, omega*a - sqrt(1 - omega*omega/2) * b, a);
}

int main(int argc, char* argv[])
{
	double omega;
	if (argc <= 1) fprintf(stderr, "Argumen:t required\n");
	omega = atof(argv[1]);
	dif(2000, 2*cos(omega),  .0, 2);
	return 0;
}




