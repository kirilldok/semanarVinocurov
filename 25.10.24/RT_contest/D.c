#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
} Rect;


int main()
{
    int N = 0;
    int i = 0;
    int count = 0;
    int square_sing = 0;
    Rect* rect = { 0 };
    int* square = NULL;

    if ( scanf("%d", &N) == 1 )
    {
        //printf("%d", N);
        rect = calloc(N, sizeof(Rect));
        square = (int*)calloc(N, sizeof(int));

        for(i = 0; i < N; i++)
        {
            scanf("%d%d%d%d", &rect[i].lt.x, &rect[i].lt.y, &rect[i].rb.x, &rect[i].rb.y);
            square_sing = (abs(rect[i].rb.x - rect[i].lt.x)) * (abs(rect[i].lt.y - rect[i].rb.y));
            square[i] = square_sing;
        }
    }

    for(i = 0; i < N - 1; i++)
    {
        if (square[i] < square[N - 1])
            ++count;
    }

    free(rect);
    free(square);
    printf("%d\n", count);

    return 0;
}

