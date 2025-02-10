#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Solger
{
    int height;
    int num;
} Solger;


void swap(int* arr, int i, int j);
void Bsort(Solger* arm, int size, bool sortflag);

int main()
{
    int n = 0;
    int i = 0;

    scanf("%d", &n);

    Solger* arm = { 0 };
    arm = calloc(n, sizeof(Solger));

    for(i = 0; i < n; i++)
        scanf("%d", &arm[i].num);

    Bsort(arm, n, 1);

    arm[0].height = arm[0].num;

    for(i = 1; i < n ; i++)
        arm[i].height = arm[i].num - arm[i-1].num;

    Bsort(arm, n, 0);

    for(i = 0; i < n; i++)
        printf("%d ", arm[i].num);

    return 0;
}



void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Bsort(Solger* arm, int size, bool sortflag)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < size - 1 ; i++)
    {
        for(j = 0; j < (size - i - 1); j++)
        {
            if (sortflag)
            {
                if (arm[j].num < arm[j + 1].num)
                    swap(&arm->num, j, j + 1);
            }
            else
            {
               if (arm[j].height < arm[j + 1].height)
                    swap(&arm->height, j, j + 1);
            }
        }
    }
}

