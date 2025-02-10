#include <stdio.h>

typedef struct _point {
    long x;
    long y;
    long z
} point;

point* points = NULL;

int main()
{
    size_t sz = 0;
    size_t i = 0;
    size_t cap = 0;
    if (scanf("%u", &sz) == 1)
    {
        points = malloc(sz * sizeof(point));

        for(i = 0; i < sz; i++)
        {
            scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].z);
            point[i].next = NULL;
        }
        for(i = 0; i < sz; i++)
            point_add

    }


}




