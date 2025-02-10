#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void swap(int* arr, int i, int j);
void Bsort(int data[], int size);
int max(int a, int b);

int main()
{
    int N = 0;
    int i = 0;
    int j = 0;
    scanf("%d", &N);
    int* data = (int*)calloc(N, sizeof(int));
    int* olddata = (int*)calloc(N, sizeof(int));
    for(i = 0; i < N; i ++)
    {
        scanf("%d", &data[i]);
        olddata[i] = data[i];
    }

    Bsort(data, N);

    for(j = 0,i = 0; i < N ; i++, j++)
    {
        if (i < N - 1)
            printf("%d ", data[i]);
        j++;
        if (j < N - 1)
            printf("%d ", max(olddata[j - 1], olddata[j]));
    }

    
    free(data);
    free(olddata);

    return 0;
}

int max(int a, int b)
{
    if(a >= b)
        return a;
    else
        return b;
}


void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Bsort(int data[], int size)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < size - 1 ; i++)
    {
        for(j = 0; j < (size - i - 1); j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data, j, j + 1);
            }
        }
    }
}
