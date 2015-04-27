#include <time.h>
#include <stdlib.h>

int generate_random_numbers(int **arr, int n, int min, int max)
{
    int i;
    *arr = (int *)malloc(sizeof(int)*n); 
    if (*arr == NULL)
        return -1;
    srand(time(NULL));
    for(i = 0; i < n; i++)
        (*arr)[i] = min + rand() % (max - min + 1);
    return 0;
}

int test(int *arr, int n)
{
    int i;
    for(i = 0; i < n - 1; i++)
        if (arr[i] > arr[i+1])
            return 0;
    return 1;
}

void destroy(int **arr)
{
    free(*arr);
    return;
}
