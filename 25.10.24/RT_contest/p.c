#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int a = 1, b = 0;
    int n;
    int count = 1;
    bool loopflag = 1;
    scanf("%d", &n);

    while(loopflag)
    {
        int c = a;
        a = (a + b) % n;
        b = c;
        if (a == 1 && b ==0)
            loopflag = 0;
        count++;
    }

    printf("%d", count);

    return 0;
}
