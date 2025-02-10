# include <stdio.h>

# define print(x)  printf ("%d ", x)

int x;

void Q(int);

void P(int *y);

int main()

{

  x = 7;

  P(&x);

  print(x);

  return 0;

}

void Q(int z)

{

  z += x;

  print(z);

}

void P(int *y)

{

  int x = *y+2;

  Q(x);

  *y = x-1;

  print(x);

} 
