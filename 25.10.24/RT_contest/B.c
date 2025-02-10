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

//  Прямоугольник на плоскости XY со сторонами параллельными осям, задан координатами xlt и ylt левой верхней точки и координатами xrb и ybr правой нижней точки.
//
// Дан список прямоугольников, по одному праямоугольнику на строку.
//
// Найти минимальную площадь прямоугольника.



int main()
{
    int n = 0;
    int i = 0;
    int square = 0;
    Rect* rect = { 0 };
    int min_square = 0;
    if ( scanf("%d", &n) == 1 )
    {
        //printf("%d", N);
        //rect = calloc(n, sizeof(rect));
	Rect r;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &r.lt.x, &r.lt.y, &r.rb.x, &r.rb.y);
            square = (abs(r.rb.x - r.lt.x)) * (abs(r.lt.y - r.rb.y));
            if (i == 0 || square < min_square)
                min_square = square;
        }
    }
    //free(rect); rect = NULL;
    printf("%d\n", min_square);

    return 0;
}

